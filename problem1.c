#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include <unistd.h>

int sum[2];
int randnum()
{
	time_t t;
	srand((unsigned) time(&t));
	return (rand() % 6)+1;
}
void* raju(void* arg)
{

	sum[0]=0;
	int n=5;
	while(n--)
	{
		int x=randnum();
		printf("[raju] %d\n",x);
		sum[1]+=x;
		sleep(1);
	}

}

void* saju(void* arg)
{

	sum[1]=0;
	int n=5;
	while(n--)
	{
		int x=randnum();
		printf("[saju] %d\n",x);
		sum[1]+=x;
		sleep(1);
	}

}
int main()
{
	pthread_t pt, ct;

	

	
	while(sum[0]==sum[1])
	{
		pthread_create(&pt, NULL, &raju, NULL);
		sleep(1);
		pthread_create(&ct, NULL, &saju, NULL);
		pthread_join(pt, NULL);
		pthread_join(ct, NULL);
		printf("tie\n");
	}
	if(sum[0]>sum[1])
		printf("raju won\n");
	else
		printf("saju won\n");


	return 0;
}