#include <stdio.h>

void spira(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n - i; j++)
			printf("  ");
		for(j = 1; j <= 2 * i - 1; j++)
			printf("* ");
		putchar('\n');
	}
}

int main(void)
{
	int n;

	printf("�Ƕ�̵带 ����մϴ�.\n");
	do {
		printf("���� : ");
		scanf("%d", &n);
	} while(n <= 0);

	spira(n);
}