// Create an icecream eating contest problem protected by a semaphore lock. Use globalvariables icecreamremaining.
// get each person to count money from his wallet for the icecream payment which can take one to
// 2 seconds during which other person can acquire the salesman to sell him icecream.Redo the
// coding to accommodate this condition in your threads as well.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 10
#define NUM_ICECREAM 10

int icecreamremaining = NUM_ICECREAM;

sem_t lock;

void* eaticecream(void* threadid)
{
	int tid = (int)threadid;
	int money = rand() % 2 + 1;
	printf("Person %d is eating icecream for %d seconds \n", tid, money);
	sleep(money);
	sem_wait(&lock);
	if (icecreamremaining > 0)
	{
		icecreamremaining--;
		printf("Person %d is eating icecream. Remaining icecream %d \n", tid, icecreamremaining);
	}
	else
	{
		printf("Person %d is waiting for icecream \n", tid);
	}
	
	sem_post(&lock);
}

int main()
{
	pthread_t threads[NUM_THREADS];
	sem_init(&lock, 0, 1);
	int rc;
	int t;
	for (t = 0; t < NUM_THREADS; t++)
	{
		printf("In main: creating thread %d \n", t);
		rc = pthread_create(&threads[t], NULL, eaticecream, (void*)t);
		if (rc)
		{
			printf("ERROR; return code from pthread_create() is %d \n", rc);
			exit(-1);
		}
		
	}
	
	pthread_exit(NULL);
}






