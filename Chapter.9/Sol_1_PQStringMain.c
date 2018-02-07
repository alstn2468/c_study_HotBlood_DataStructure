#include <stdio.h>
#include <string.h>
#include "PriorityQueue.h"

int DataPriorityComp(char * str1, char * str2)
{
	return strlen(str2) - strlen(str1);
}

int main()
{
	PQueue pq;
	PQueueInit(&pq, DataPriorityComp);

	PEnqueue(&pq, "Hello World!");
	PEnqueue(&pq, "Coding");
	PEnqueue(&pq, "C Language");
	PEnqueue(&pq, "Data Struct");
	PEnqueue(&pq, "Priority Queue");

	while (!PQIsEmpty(&pq))
		printf("%s \n", PDequeue(&pq));

	return 0;
}
