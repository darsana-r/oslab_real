#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

int shared=1;
sem_t sem;

void *thread_increment(void *args){
	sem_wait(&sem);
	int local=shared;
	printf("Thread1 reads the value of shared variable as : %d\n",local);
	sleep(1);
	local=local+1;
	printf("Thread1 updates the value to %d\n",local);
	shared=local;
	sem_post(&sem);
}

void *thread_decrement(void *args){
	sem_wait(&sem);
	int local=shared;
	printf("Thread2 reads the value of shared variable as : %d\n",local);
	sleep(1);
	local=local-1;;
	printf("Thread2 updates the value to %d\n",local);
	shared=local;
	sem_post(&sem);
}

int main(){
	sem_init(&sem,0,1);
	pthread_t t1,t2;
	printf("Initial value of shared variable :%d\n",shared);
	pthread_create(&t1,NULL,thread_increment,NULL);
	pthread_create(&t2,NULL,thread_decrement,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	printf("Final value of shared variable :%d\n",shared);
	sem_destroy(&sem);	
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/semaphore$ gcc semaphore_4b.c -lpthread
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/semaphore$ ./a.out
Initial value of shared variable :1
Thread1 reads the value of shared variable as : 1
Thread1 updates the value to 2
Thread2 reads the value of shared variable as : 2
Thread2 updates the value to 1
Final value of shared variable :1

*/
