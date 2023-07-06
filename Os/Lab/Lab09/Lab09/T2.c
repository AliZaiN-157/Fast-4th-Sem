//Imagine you are designing a ticketing system for a popular concert.The system will have multiple ticket
//sellers, each running on a separate thread.To prevent overselling, you need to ensure that no two sellers
//can sell the same ticket at the same time.How would you use semaphores in C to ensure that only one
//ticket seller can access the ticket database at a time, while the others wait until the resource becomes
//available ? (Create a code based implementation)

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* ticket_seller(void* arg)
{
	int* id = (int*)arg;
	sem_wait(&sem);
	printf("Ticket sold by seller %d \n", *id);
	sem_post(&sem);
}

int main()
{
	sem_init(&sem, 0, 1);
	pthread_t t1, t2, t3;
	int id1 = 1, id2 = 2, id3 = 3;
	pthread_create(&t1, NULL, ticket_seller, &id1);
	pthread_create(&t2, NULL, ticket_seller, &id2);
	pthread_create(&t3, NULL, ticket_seller, &id3);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	sem_destroy(&sem);
	return 0;
}