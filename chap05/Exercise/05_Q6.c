#include <stdio.h>

void move(int no, int x, int y)
{
	if(no > 1)
		move(no - 1, x , 6 - x - y);
	printf("����[%d]��(��) %c ��տ��� %c ������� �ű�\n", no, x + 64, y + 64);
	if(no > 1)
		move(no - 1, 6 - x - y, y);
}

int main(void)
{
	int n;
	printf("�ϳ����� ž\n���� ���� : ");
	scanf("%d", &n);
	move(n, 1, 3);

	return 0;
}