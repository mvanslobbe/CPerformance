clean :
	rm -f posix_server libevent2_server 
	
servers : posix_server libevent2_server

posix_server :
	gcc repeating_posix_server.c -o posix_server

libevent2_server :
	gcc repeating_libevent_server.c -I/usr/include/ -levent -L/usr/lib -o libevent2_server
	