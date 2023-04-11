#include	<sys/time.h>
#include	<stdio.h>

int	main(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	printf("msec: %ld\n", time.tv_usec/1000);
	gettimeofday(&time, NULL);
	printf("msec: %ld\n", time.tv_usec/1000);
	return (0);
}
