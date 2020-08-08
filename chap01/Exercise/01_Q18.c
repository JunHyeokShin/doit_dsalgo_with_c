#include <stdio.h>

void nrpira(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i - 1; j++)
			printf("  ");
		for(j = 1; j <= (n - i) * 2 + 1; j++)
			printf("%d ", i % 10);
		putchar('\n');
	}
}

int main(void)
{
	int n;

	printf("역 숫자 피라미드를 출력합니다.\n");
	do {
		printf("층수 : ");
		scanf("%d", &n);
	} while(n <= 0);

	nrpira(n);
}