#include <stdio.h>

// from에 꽂혀있는 num개의 원반을 by를 거쳐서 to로 이동
void HanoiTowerMove(int num, char from, char by, char to)
{
  // 이동할 원반의 수가 1개라면
	if (num == 1)
	{
		printf("원반1을 %c에서 %c로 이동\n", from, to);
	}
	else
	{
		HanoiTowerMove(num - 1, from, to, by);
		printf("원반%d를 %c에서 %c로 이동\n", num, from, to);
		HanoiTowerMove(num - 1, by, from, to);
	}
}

int main()
{
	// 막대 A의 원반 3개를 막대 B를 경유하여 막대 C로 옮기기
	HanoiTowerMove(3, 'A', 'B', 'C');

	return 0;
}
