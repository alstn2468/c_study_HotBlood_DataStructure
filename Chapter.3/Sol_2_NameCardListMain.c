#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
	List list;
	NameCard * pcard;
	ListInit(&list);

	pcard = MakeNameCard("People1", "010-1111-1111");
	LInsert(&list, pcard);

	pcard = MakeNameCard("People2", "010-2222-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("People3", "010-3333-3333");
	LInsert(&list, pcard);

	// 초기 정보 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}
	printf("\n");

	// People1의 정보를 조회하여 출력
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "People1"))
		{
			ShowNameCardInfo(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "People1"))
				{
					ShowNameCardInfo(pcard);
					break;
				}
			}
		}
	}
	printf("\n");

	// People2의 정보를 조회하여 변경
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "People2"))
		{
			ChangePhoneNum(pcard, "010-4444-4444");
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "People2"))
				{
					ChangePhoneNum(pcard, "010-4444-4444");
					break;
				}
			}
		}
	}

	// People3의 정보를 조회하여 삭제
	if (LFirst(&list, &pcard))
	{
		if (!NameCompare(pcard, "People3"))
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (!NameCompare(pcard, "People3"))
				{
					pcard = LRemove(&list);
					free(pcard);
					break;
				}
			}
		}
	}

	// 최종 정보 출력
	printf("현재 데이터의 수 : %d\n", LCount(&list));

	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}

	return 0;
}
