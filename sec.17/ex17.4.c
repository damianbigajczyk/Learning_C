#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN 60

bool newClient(double x);
Position timeOfClient(long when);

int main(int argc, char **argv)
{
	Queue q[2];
	Position temp;
	int hour;
	int perHour;
	long cycle, limCycle;
	long sendBack = 0;
	long customers[] = {0, 0};
	long served[] = {0, 0};
	long sumQueue[] = {0, 0};
	int waitTime[] = {0, 0};
	double avgPerClient;
	long timeQueue[] = {0, 0};

	InitQueue(&q[0]);
	InitQueue(&q[1]);

	srand((unsigned int) time(0));
	puts("********* Simulation Queue **********");
	fputs("Enter time of simulation in hours: ", stdout);
	scanf("%d", &hour);
	limCycle = MIN * hour;
	fputs("Enter the average of clients per hour: ", stdout);
	scanf("%d", &perHour);
	avgPerClient = MIN / perHour;

	for (cycle = 0; cycle < limCycle; cycle++) {
		if (newClient(avgPerClient)) {
			if (FullQueue(&q[0]) && FullQueue(&q[1]))
				sendBack++;
			else {
				temp = timeOfClient(cycle);
				if (FullQueue(&q[0])) {
					Set(temp, &q[1]);
					customers[1]++;
				} else if (FullQueue(&q[1])) {
					Set(temp, &q[0]);
					customers[0]++;
				} else {
					int a = rand() % 2;
					Set(temp, &q[a]);
					customers[a]++;
				}
			}
		}
		if (waitTime[0] <= 0 && !EmptyQueue(&q[0])) {
			Detach(&temp, &q[0]);
			waitTime[0] = temp.timeRequest;
			timeQueue[0] += cycle - temp.start;
			served[0]++;
		} else if (waitTime[1] <= 0 && !EmptyQueue(&q[1])) {
			Detach(&temp, &q[1]);
			waitTime[1] = temp.timeRequest;
			timeQueue[1] += cycle - temp.start;
			served[1]++;
		}
		if (waitTime > 0) {
			waitTime[0]--;
			waitTime[1]--;
		}
		sumQueue[0] += CountAmount(&q[0]);
		sumQueue[1] += CountAmount(&q[1]);
	}
	if (customers > 0) {
		printf("Queued_1 customers: %ld\t\t", customers[0]);
		printf("Queued_2 customers: %ld\n", customers[1]);
		printf("Served_1 customers: %ld\t\t", served[0]);
		printf("Served_2 customers: %ld\n", served[1]);
		printf("Served customers: %ld\n", served[0] + served[1]);
		printf("Send back customers: %ld\n", sendBack);
		printf("Average lenght of queue_1: %.2f\t\t\t",
				(double) sumQueue[0] / limCycle);
		printf("Average lenght of queue_2: %.2f\n",
				(double) sumQueue[1] / limCycle);
		printf("Average waiting time_1: %.2f minutes\t\t",
				(double) timeQueue[0] / served[0]);
		printf("Average waiting time_2: %.2f minutes\n",
				(double) timeQueue[1] / served[1]);
	} else
		puts("No clients");
	ClearQueue(&q[0]);
	ClearQueue(&q[1]);
	puts("See you!");

	return 0;
}
bool newClient(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}
Position timeOfClient(long when)
{
	Position client;
	client.timeRequest = rand() % 3 + 1;
	client.start = when;
	return client;
}
