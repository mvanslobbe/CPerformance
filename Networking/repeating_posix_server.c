#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    struct sockaddr_in accept_socket;
    char buf[256];
    int i, num_bytes, fd_max, new_fd, num_connections = 0 ;
    int accept_socket_descriptor = socket(PF_INET,
                                          SOCK_STREAM,
                                          IPPROTO_TCP);

    if ( accept_socket_descriptor == -1 )
    {
        perror("can't create socket");
        exit(1);
    }

    memset ( &accept_socket, 0, sizeof(accept_socket) );
    accept_socket.sin_family = AF_INET;
    accept_socket.sin_port = htons(5555);
    accept_socket.sin_addr.s_addr = htonl(INADDR_ANY);
    int reuse_socket = 1;
    setsockopt(accept_socket_descriptor, SOL_SOCKET, SO_REUSEADDR, &reuse_socket, sizeof(int));

    if ( bind ( accept_socket_descriptor,
                (struct sockaddr *)&accept_socket,
                sizeof(accept_socket)) == -1)
    {
        perror("bind failed");
        close(accept_socket_descriptor);
        exit(1);
    }

    printf("start listening..\n");
    if ( listen(accept_socket_descriptor, 10) == -1 )
    {
        perror("listen failed");
        close(accept_socket_descriptor);
        exit(1);
    }

    fd_set read_fds;
    fd_set write_fds;
    fd_set all_fds;
    fd_max = accept_socket_descriptor;
    FD_SET( accept_socket_descriptor, &all_fds );

    while(1)
    {
        read_fds = all_fds; // copy, use select again
        if ( select ( fd_max+1, &read_fds, &write_fds, NULL, NULL) == -1 )
        {
            perror("select failed");
            exit(1);
        }

        for(i = 0 ; i <= fd_max; i++ )
        {
            if ( FD_ISSET(i,&read_fds) )
            {
                // more likely we're receiving data rather than a new connection .. handle this first
                if ( i!=accept_socket_descriptor )
                {
                    num_bytes = recv(i,buf,sizeof buf, 0);
                    if ( num_bytes == 0 )
                    {
                        printf("Close connection.. have %d left\n", --num_connections);
                        FD_CLR(i, &all_fds);
                    }
                    send(i,buf,num_bytes,0);
                }
                else
                {
                    struct sockaddr_storage remote_addr;
                    socklen_t addrlen = sizeof remote_addr;
                    new_fd = accept(accept_socket_descriptor,
                                    (struct sockaddr *)&remote_addr,
                                    &addrlen);
                    FD_SET(new_fd,&all_fds);
                    fd_max=new_fd > fd_max ? new_fd : fd_max;
                    num_connections++;
                }
            }
        }
    }
    return 0;
}
