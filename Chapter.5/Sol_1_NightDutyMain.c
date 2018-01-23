#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

Employee * WhosNightDuty(List * plist, char * name, int day);
void ShowEmployeeInfo(Employee * emp);

int main()
{
	int i;
	Employee * pemp;

	/* List의 생성 및 초기화 */
	List list;
	ListInit(&list);

	/* 4명의 데이터 저장 */
	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 11111;
	strcpy(pemp->name, "Employee1");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 22222;
	strcpy(pemp->name, "Employee2");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 33333;
	strcpy(pemp->name, "Employee3");
	LInsert(&list, pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	pemp->empNum = 44444;
	strcpy(pemp->name, "Employee4");
	LInsert(&list, pemp);

	/* Employee1 뒤로 3일뒤 당직자는 ? */
	pemp = WhosNightDuty(&list, "Employee1", 3);
	ShowEmployeeInfo(pemp);  // Employee4

	/* Employee4 뒤로 15일뒤 당직자는 ? */
	pemp = WhosNightDuty(&list, "Employee4", 15);
	ShowEmployeeInfo(pemp);  // Employee3

	/* 할당된 메모리의 전체 소멸 */
	if (LFirst(&list, &pemp))
	{
		free(pemp);

		for (i = 0; i < LCount(&list) - 1; i++);
		{
			if (LNext(&list, &pemp))
				free(pemp);
		}
	}

	return 0;
}

Employee * WhosNightDuty(List * plist, char * name, int day)
{
	int i, num;
	Employee *ret;

	num = LCount(plist);

	/* 이름 찾기 */
	LFirst(plist, &ret);

	if (strcmp(ret->name, name) != 0)
	{
		for (i = 0; i < num - 1; i++)
		{
			LNext(plist, &ret);

			if (strcmp(ret->name, name) == 0)
				break;
		}
		if (i > num - 1)	// 해당하는 이름이 존재하지 않으면
			return NULL;
	}

	/* 그 뒤로 며칠 뒤 */
	for (i = 0; i < day; i++)
		LNext(plist, &ret);

	return ret;

}

void ShowEmployeeInfo(Employee * emp)
{
	printf("Employee name : %s \n", emp->name);
	printf("Employee number : %d \n", emp->empNum);
}
