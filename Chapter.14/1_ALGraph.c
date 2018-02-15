#include <stdio.h>
#include "ALGraph.h"
#include "DLinkedList.h"

int WhoIsPrecede(int data1, int data2);

/* 그래프의 초기화 */
void GraphInit(ALGraph * pg, int nv)
{
	int i;

	/* 정점의 수에 해당하는 길이와 리스트 배열을 생성 */
	pg->adjList = (List*)malloc(sizeof(List) * nv);	// 간선정보를 저장할 리스트 생성

	pg->numV = nv;	// 정점의 수는 nv에 저장된 값으로 결정
	pg->numE = 0;	// 초기의 간선 수는 0개

	/* 정점의 수만큼 생성된 리스트를 초기화 */
	for (i = 0; i < nv; i++)
	{
		ListInit(&(pg->adjList[i]));
		SetSortRule(&(pg->adjList[i]), WhoIsPrecede);
	}
}

/* 그래프 리소스의 해제 */
void GraphDestroy(ALGraph * pg)
{
	if (pg->adjList != NULL)
		free(pg->adjList);
}

/* 간선의 추가 */
void AddEdge(ALGraph * pg, int fromV, int toV)
{
	LInsert(&(pg->adjList[fromV]), toV);
	LInsert(&(pg->adjList[toV]), fromV);
	pg->numE += 1;
}

/* 간선의 정보 출력 */
void ShowGraphEdgeInfo(ALGraph * pg)
{
	int i;
	int vx;

	for (i = 0; i < pg->numV; i++)
	{
		printf("%c와 연결된 정점 : ", i + 65);

		if (LFirst(&(pg->adjList[i]), &vx))
		{
			printf("%c ", vx + 65);

			while (LNext(&(pg->adjList[i]), &vx))
				printf("%c ", vx + 65);
		}
		printf("\n");
	}
}

int WhoIsPrecede(int data1, int data2)
{
	if (data1 < data2)
		return 0;
	else
		return 1;
}
