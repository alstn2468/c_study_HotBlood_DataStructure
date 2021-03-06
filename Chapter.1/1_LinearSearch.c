#include <stdio.h>

/* 순차 탐색 알고리즘이 적용된 함수 */
int LSearch(int ar[], int len, int target)
{
	int i;

	for (i = 0; i < len; i++)
	{
		if (ar[i] == target)
			return i;		  // 찾은 대상의 인덱스 값 반환
	}
	return -1;				// 찾지 못햇음을 의미 하는 값 반환
}

int main()
{
	int arr[] = { 3, 5, 2, 4, 9 };
	int idx;

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 4);

	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	idx = LSearch(arr, sizeof(arr) / sizeof(int), 7);

	if (idx == -1)
		printf("탐색 실패\n");
	else
		printf("타겟 저장 인덱스 : %d\n", idx);

	// 최악의 경우 시간 복잡도 T(n) = n	, O(n)
	// 평균의 경우 시간 복잡도 T(n) = (3 / 4) / n, O(n)

	return 0;
}
