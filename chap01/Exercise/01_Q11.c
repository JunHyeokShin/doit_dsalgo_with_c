#include <stdio.h>

int main(void)
{
	int n;
	int digits = 0;

	do{
		printf("���� ���� : ");
		scanf("%d", &n);
	} while(n <= 0);

	while(n > 0) {
		n /= 10;
		digits++;
	}

	printf("�� ���� %d�ڸ��Դϴ�.\n", digits);

	return 0;
}