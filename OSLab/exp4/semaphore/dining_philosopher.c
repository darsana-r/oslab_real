#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

sem_t chopstick[5];

void eat(int ph){
	printf("Philosopher %d is eating\n",ph);
}

void *philos(void *args){
	int ph=*(int *)args;
	printf("Philosopher %d is trying to eat\n",ph);
	printf("Philosopher %d is trying to pick left chopstick\n",ph);
	sem_wait(&chopstick[ph]);
	printf("Philosopher %d took the left chopstick\n",ph);
	printf("Philosopher %d is trying to pick right chopstick\n",ph);
	sem_wait(&chopstick[(ph+1)%5]);
	printf("Philosopher %d took the right chopstick\n",ph);
	eat(ph);
	sleep(2);

	printf("Philosopher %d is trying to putdown left chopstick\n",ph);
	sem_post(&chopstick[ph]);
	printf("Philosopher %d putdown the left chopstick\n",ph);
	printf("Philosopher %d is trying to putdown right chopstick\n",ph);
	sem_post(&chopstick[(ph+1)%5]);
	printf("Philosopher %d putdown the right chopstick\n",ph);
}

int main(){
	int n[5];
	pthread_t T[5];
	for(int i=0;i<5;i++){
		sem_init(&chopstick[i],0,1);
	}
	for(int i=0;i<5;i++){
		n[i]=i;
		pthread_create(&T[i],NULL,philos,&n[i]);
	}

	for(int i=0;i<5;i++){
		pthread_join(T[i],NULL);
	}
}

/*
OUTPUT

pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/semaphore$ gcc dining_philosopher.c -lpthread
pkd22it027@user-HP-280-G3-MT:~/Desktop/OSLab/exp4/semaphore$ ./a.out
Philosopher 1 is trying to eat
Philosopher 1 is trying to pick left chopstick
Philosopher 4 is trying to eat
Philosopher 4 is trying to pick left chopstick
Philosopher 3 is trying to eat
Philosopher 4 took the left chopstick
Philosopher 4 is trying to pick right chopstick
Philosopher 4 took the right chopstick
Philosopher 4 is eating
Philosopher 1 took the left chopstick
Philosopher 1 is trying to pick right chopstick
Philosopher 1 took the right chopstick
Philosopher 1 is eating
Philosopher 0 is trying to eat
Philosopher 0 is trying to pick left chopstick
Philosopher 2 is trying to eat
Philosopher 2 is trying to pick left chopstick
Philosopher 3 is trying to pick left chopstick
Philosopher 3 took the left chopstick
Philosopher 3 is trying to pick right chopstick
Philosopher 1 is trying to putdown left chopstick
Philosopher 1 putdown the left chopstick
Philosopher 1 is trying to putdown right chopstick
Philosopher 4 is trying to putdown left chopstick
Philosopher 1 putdown the right chopstick
Philosopher 2 took the left chopstick
Philosopher 2 is trying to pick right chopstick
Philosopher 3 took the right chopstick
Philosopher 3 is eating
Philosopher 4 putdown the left chopstick
Philosopher 4 is trying to putdown right chopstick
Philosopher 4 putdown the right chopstick
Philosopher 0 took the left chopstick
Philosopher 0 is trying to pick right chopstick
Philosopher 0 took the right chopstick
Philosopher 0 is eating
Philosopher 3 is trying to putdown left chopstick
Philosopher 0 is trying to putdown left chopstick
Philosopher 0 putdown the left chopstick
Philosopher 0 is trying to putdown right chopstick
Philosopher 0 putdown the right chopstick
Philosopher 2 took the right chopstick
Philosopher 2 is eating
Philosopher 3 putdown the left chopstick
Philosopher 3 is trying to putdown right chopstick
Philosopher 3 putdown the right chopstick
Philosopher 2 is trying to putdown left chopstick
Philosopher 2 putdown the left chopstick
Philosopher 2 is trying to putdown right chopstick
Philosopher 2 putdown the right chopstick
      
*/
