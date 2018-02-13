#include <stdio.h>

typedef struct _empInfo
{
	int empNum;	// 직원의 고유번호
	int age;	// 직원의 나이
}	EmpInfo;

int main()
{
	EmpInfo empInfoArr[1000];
	EmpInfo ei;
	int eNum;

	printf("사번과 나이 입력 : ");
	scanf("%d %d", &(ei.empNum), &(ei.age));
	empInfoArr[ei.empNum] = ei;

	printf("확인하고 싶은 직원의 사번 입력 : ");
	scanf("%d", &eNum);

	ei = empInfoArr[eNum];
	printf("사번 %d, 나이 %d \n", ei.empNum, ei.age);

	return 0;
}
