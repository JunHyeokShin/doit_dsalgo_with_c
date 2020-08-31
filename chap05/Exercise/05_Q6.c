#include <stdio.h>

void move(int no, int x, int y)
{
	if(no > 1)
		move(no - 1, x , 6 - x - y);
	printf("원반[%d]을(를) %c 기둥에서 %c 기둥으로 옮김\n", no, x + 64, y + 64);
	if(no > 1)
		move(no - 1, 6 - x - y, y);
}

int main(void)
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf("%d", &n);
	move(n, 1, 3);

	return 0;
}