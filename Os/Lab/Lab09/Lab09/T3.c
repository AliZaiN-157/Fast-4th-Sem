// a.Create an icecream eating contest problem protected by a semaphore lock.Use global
// variables icecreamremaining.Create 3 threads for 3 persons to eat icecreams until all are
// finished.But only one person will be given icecreamcone at a time by the salesman.So restrict
// access to icecreams so that only one thread can decrement it by using a semaphor.So use
// sem_wait and Sem_post in thread.

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;
int icecreamremaining = 6;

void* eaticecream(void* arg)
{
	int* person = (int*)arg;
	sem_wait(&sem);
	if (icecreamremaining > 0)
	{
		printf("Person %d is eating icecream %d remaining %d \n", *person, icecreamremaining, icecreamremaining - 1);
		icecreamremaining--;
	}
	
	sem_post(&sem);
}

int main()
{
	sem_init(&sem, 0, 1);
	pthread_t p1, p2, p3;
	int person1 = 1, person2 = 2, person3 = 3;
	pthread_create(&p1, NULL, eaticecream, &person1);
	pthread_create(&p2, NULL, eaticecream, &person2);
	pthread_create(&p3, NULL, eaticecream, &person3);
	pthread_join(p1, NULL);
	pthread_join(p2, NULL);
	pthread_join(p3, NULL);
	sem_destroy(&sem);
	return 0;
}



