#include	<pthread.h>
#include	<stdio.h>
#include	<unistd.h>

void	*test_fun(void *vargp)
{
	int *i_in;

	i_in = (int *)vargp;
	printf("in thr\n");
	printf("my i_in[%d]\n", *i_in);
	return NULL;
}

int	main(void)
{
	pthread_t	tid;
	int	i;

	i = 100;

	printf("bef thr\n");
	pthread_create(&tid, NULL, test_fun, (void *)&i);
	pthread_join(tid, NULL);
	printf("aft thr\n");
	return (0);
}
