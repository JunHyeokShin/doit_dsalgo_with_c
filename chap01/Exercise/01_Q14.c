#include <stdio.h>

int main(void)
{
	int i, j;
	int n;

	printf("�簢���� ����մϴ�.\n");
	printf("�Է��� �� : ");
	scanf("%d", &n);

	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n; j++)
			printf("* ");
		putchar('\n');
	}

	return 0;
}