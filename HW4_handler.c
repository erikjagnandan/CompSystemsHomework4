#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

void sleepFunc(){
	printf("Entering sleepFunc\n");
	sleep(2);
	printf("Exiting sleepFunc Without Terminating\n");
}

void handler(){
	printf("Received Signal\n");
}

int main(){
	pthread_t tid1, tid2, tid3;
	signal(SIGINT, handler);
	pthread_create(&tid1, 0, (void*)sleepFunc, 0);
	pthread_create(&tid2, 0, (void*)sleepFunc, 0);
	pthread_create(&tid3, 0, (void*)sleepFunc, 0);
	sleep(1);
	pthread_kill(tid3, SIGINT);
	sleep(1);
	printf("Main Thread Exiting Without Terminating\n");
}
