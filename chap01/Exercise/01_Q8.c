#include <stdio.h>

int main(void)
{
	int n, sum;
	puts("1���� n������ ���� ���մϴ�.");
	printf("n�� �� : ");
	scanf("%d", &n);
	sum = (1 + n) * n / 2;
	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

	return 0;
}