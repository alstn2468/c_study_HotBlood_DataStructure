#include <stdio.h>
#include "ArrayList.h"

int main()
{
	/* ArrayList의 생성 및 초기화 */
	List list;
	int data;
	ListInit(&list);
	int sum;

	/* 1부터 9 까지 데이터 저장 */
	for (int i = 0; i <= 8; i++)
	{
		LInsert(&list, i + 1);
	}

	/* 저장된 데이터의 전체 합 출력 */
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))	// 첫 번째 데이터 조회
	{
		printf("%d ", data);
		sum = data;

		while (LNext(&list, &data))	// 두 번째 이후의 데이터 조회
		{
			printf("%d ", data);
			sum += data;
		}

		printf("\n");
		printf("데이터들의 합 : %d\n", sum);
	}
	printf("\n\n");

	/* 2의 배수와 3의배수 삭제 */
	if (LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);

		while (LNext(&list, &data))
		{
			if (data % 2 == 0 || data % 3 == 0)
				LRemove(&list);
		}
	}

	/* 삭제 후 남은 데이터 전체 출력 */
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &data))
	{
		printf("%d ", data);

		while (LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");

	return 0;
}
