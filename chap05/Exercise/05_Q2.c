#include <stdio.h>

int gcd(int a, int b)
{
	int c;
	while(b)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

int main(void)
{
	int x, y;

	puts("�� ������ �ִ� ������� ���մϴ�.");
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &y);
	printf("�ִ������� %d�Դϴ�.\n", gcd(x, y));

	return 0;
}