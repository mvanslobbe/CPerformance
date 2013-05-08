#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_RUNS 1e9
#define NUM_RANDOM_NUMBERS 20000

void testIfEvenDistribution( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		if ( r < 5 )
			a++;
		else if ( r < 10 )
			b++;
		else if ( r < 15 )
			c++;
		else
			d++;
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

void testManyIfsEvenDistribution ( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		if ( r == 0 )
			a++;
		else if ( r == 1 )
			a++;
		else if ( r == 2 )
			a++;
		else if ( r == 3)
			a++;
		else if ( r == 4 )
			a++;
		else if ( r == 5 )
			b++;
		else if ( r == 6 )
			b++;
		else if ( r == 7 )
			b++;
		else if ( r == 8 )
			b++;
		else if ( r == 9 )
			b++;
		else if ( r == 10 )
			c++;
		else if ( r == 11 )
			c++;
		else if ( r == 12 )
			c++;
		else if ( r == 13 )
			c++;
		else if ( r == 14 )
			c++;
		else if ( r == 15 )
			d++;
		else if ( r == 16 )
			d++;
		else if ( r == 17 )
			d++;
		else if ( r == 18 )
			d++;
		else
			d++;
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

void testIfUnevenLuckyDistribution( int random_numbers[] )
{
	int r = 0,a = 0,b =0,c = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		// same number of if/else statements, but the first one is most likely
		if ( r < 10 )
			a++;
		else if ( r < 15 )
			b++;
		else if ( r < 17 )
			c++;
		else
			c++;
	}

	// do something with a,b,c,d..
	if ( a+b+c != NUM_RUNS )
		printf("Totals don't add up!");
}

void testIfUnevenUnluckyDistribution( int random_numbers[] )
{
	int r = 0,a = 0,b =0,c = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		// same number of if/else statements, but the last ones are most likely
		if ( r < 5 )
			a++;
		else if ( r < 10 )
			b++;
		else if ( r < 15 )
			c++;
		else if ( r < 20 )
			c++;
	}

	// do something with a,b,c,d..
	if ( a+b+c != NUM_RUNS )
		printf("Totals don't add up!");
}

void testNoIf( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		a += ( r<5 ? 1 : 0 );
		b += ( r>=5 && r <10 ? 1 : 0 );
		c += ( r>=10 && r < 15 ? 1 : 0 );
		d += ( r>=15 && r <= 20 ? 1 : 0 );
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

void testNoIfManyOptions( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;

	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		a += ( r==0 ? 1 : 0 );
		a += ( r==1 ? 1 : 0 );
		a += ( r==2 ? 1 : 0 );
		a += ( r==3 ? 1 : 0 );
		a += ( r==4 ? 1 : 0 );
		b += ( r==5 ? 1 : 0 );
		b += ( r==6 ? 1 : 0 );
		b += ( r==7 ? 1 : 0 );
		b += ( r==8 ? 1 : 0 );
		b += ( r==9 ? 1 : 0 );
		c += ( r==10 ? 1 : 0 );
		c += ( r==11 ? 1 : 0 );
		c += ( r==12 ? 1 : 0 );
		c += ( r==13 ? 1 : 0 );
		c += ( r==14 ? 1 : 0 );
		d += ( r==15 ? 1 : 0 );
		d += ( r==16 ? 1 : 0 );
		d += ( r==17 ? 1 : 0 );
		d += ( r==18 ? 1 : 0 );
		d += ( r==19 ? 1 : 0 );
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

enum SelectionEnum {
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE,
	SIX,
	SEVEN,
	EIGHT,
	NINE,
	TEN,
	ELEVEN,
	TWELVE,
	THIRTEEN,
	FOURTEEN,
	FIFTEEN,
	SIXTEEN,
	SEVENTEEN,
	EIGHTEEN,
	NINETEEN
};

void testSwitch( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;
	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		SelectionEnum se ( r < 5 ? ONE :
			( r < 10 ? TWO :
			( r < 15 ? THREE :
			FOUR ) ) );
		switch ( se )
		{
		case ONE:
			a++;
			break;
		case TWO:
			b++;
			break;
		case THREE:
			c++;
			break;
		case FOUR:
		default:
			d++;
			break;
		}
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

void testSwitchManyBranches( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;
	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		SelectionEnum se ( r == 0 ? ONE :
			( r == 1 ? TWO :
			( r == 2 ? THREE :
			( r == 3 ? FOUR :
			( r == 4 ? FIVE :
			( r == 5 ? SIX :
			( r == 6 ? SEVEN :
			( r == 7 ? EIGHT :
			( r == 8 ? NINE :
			( r == 9 ? TEN :
			( r == 10 ? ELEVEN :
			( r == 11 ? TWELVE :
			( r == 12 ? THIRTEEN :
			( r == 13 ? FOURTEEN :
			( r == 14 ? FIFTEEN :
			( r == 15 ? SIXTEEN :
			( r == 16 ? SEVENTEEN :
			( r == 17 ? EIGHTEEN :
			( r == 18 ? NINETEEN : NINETEEN )))))))))))))))))));
		switch ( se )
		{
		case ONE:
			a++;
			break;
		case TWO:
			a++;
			break;
		case THREE:
			a++;
			break;
		case FOUR:
			a++;
			break;
		case FIVE:
			a++;
			break;
		case SIX:
			b++;
			break;
		case SEVEN:
			b++;
			break;
		case EIGHT:
			b++;
			break;
		case NINE:
			b++;
			break;
		case TEN:
			b++;
			break;
		case ELEVEN:
			c++;
			break;
		case TWELVE:
			c++;
			break;
		case THIRTEEN:
			c++;
			break;
		case FOURTEEN:
			c++;
			break;
		case FIFTEEN:
			c++;
			break;
		case SIXTEEN:
			d++;
			break;
		case SEVENTEEN:
			d++;
			break;
		case EIGHTEEN:
			d++;
			break;
		case NINETEEN:
			d++;
			break;
		default:
			d++;
			break;
		}
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

void testQuickest( int random_numbers[] )
{
	int r = 0,a = 0,b = 0,c =0,d = 0;
	int * output_array[4] = { &a,&b,&c,&d };
	size_t offset ( 0 );
	for(int i = 0 ; i < NUM_RUNS; i++)
	{
		r = random_numbers[ i % NUM_RANDOM_NUMBERS ];
		offset = r%4;
		*(output_array[offset]) = *(output_array[offset])+1;
	}

	// do something with a,b,c,d..
	if ( a+b+c+d != NUM_RUNS )
		printf("Totals don't add up!");
}

#define TIME_FUNCTION(a,b) \
{ \
	int before_time = 0, after_time = 0; \
	before_time = time(NULL); \
	a( random_numbers ); \
	after_time = time(NULL); \
	printf("%s took %d seconds\n",b,(after_time-before_time)); \
}

int compareInt(const void *a, const void *b) 
{ 
	const int *ia = (const int *)a; 
	const int *ib = (const int *)b;
	return *ia  - *ib; 
} 

int main()
{
	// pseudo random
	srand(0);

	int random_numbers[NUM_RANDOM_NUMBERS] = {0};
	for(size_t i = 0 ; i < NUM_RANDOM_NUMBERS; i ++)
		random_numbers[i] = rand() % 20;
	
	printf("Unsorted random numbers:\n\n");
	TIME_FUNCTION(testIfEvenDistribution,"If statements, even distribution");
	TIME_FUNCTION(testManyIfsEvenDistribution, "If statements, Many branches, even distribution");
	TIME_FUNCTION(testIfUnevenLuckyDistribution,"If statements, uneven ( lucky ) distribution");
	TIME_FUNCTION(testIfUnevenUnluckyDistribution,"If statements, uneven ( unlucky ) distribution");
	TIME_FUNCTION(testSwitch,"Switch statements, even distribution");
	TIME_FUNCTION(testSwitchManyBranches, "Switch statements, Many branches, even distribution");
	TIME_FUNCTION(testNoIf,"Without branching, even distribution");
	TIME_FUNCTION(testNoIfManyOptions, "Without branching, many options");
	TIME_FUNCTION(testQuickest, "Quickest solution I have come up with");

	qsort(random_numbers, NUM_RANDOM_NUMBERS, sizeof(int), compareInt);
	printf("\nSorted random numbers:\n\n");
	TIME_FUNCTION(testIfEvenDistribution,"If statements, even distribution");
	TIME_FUNCTION(testManyIfsEvenDistribution, "If statements, Many branches, even distribution");
	TIME_FUNCTION(testIfUnevenLuckyDistribution,"If statements, uneven ( lucky ) distribution");
	TIME_FUNCTION(testIfUnevenUnluckyDistribution,"If statements, uneven ( unlucky ) distribution");
	TIME_FUNCTION(testSwitch,"Switch statements, even distribution");
	TIME_FUNCTION(testSwitchManyBranches, "Switch statements, Many branches, even distribution");
	TIME_FUNCTION(testNoIf,"Without branching, even distribution");
	TIME_FUNCTION(testNoIfManyOptions, "Without branching, many options");
	TIME_FUNCTION(testQuickest, "Quickest solution I have come up with");
}

