//You need to synchronize customers at boarding lounge of an airport using semaphore.where there are
//10 customers, each needs to weight his luggage, get it checkedand get a boarding pass.During each
//task passengers are too bored that they sleep, weighting luggage takes 4 seconds sleep, security
//check for luggage needs 7 seconds sleep and getting boarding pass needs 3 seconds sleep.
// use the sleep function to simulate the time taken for each task.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* customer(void* arg)
{
	int* id = (int*)arg;
	sem_wait(&sem);
	printf("Customer %d is waiting for his turn\n", *id);
	printf("Customer %d is weighting his luggage\n", *id);
	sleep(4);
	printf("Customer %d is getting his luggage checked\n", *id);
	sleep(7);
	printf("Customer %d is getting his boarding pass\n", *id);
	sleep(3);
	printf("Customer %d is done with his tasks\n", *id);
	sem_post(&sem);
}

int main()
{
	int i;
	pthread_t tid[10];
	sem_init(&sem, 0, 3);
	for (i = 0; i < 10; i++)
	{
		int* id = (int*)malloc(sizeof(int));
		*id = i + 1;
		pthread_create(&tid[i], NULL, customer, id);
	}
	for (i = 0; i < 10; i++)
	{
		pthread_join(tid[i], NULL);
	}
	sem_destroy(&sem);
	return 0;
}
