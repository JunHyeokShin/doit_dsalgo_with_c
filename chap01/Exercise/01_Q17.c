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

	printf("피라미드를 출력합니다.\n");
	do {
		printf("층수 : ");
		scanf("%d", &n);
	} while(n <= 0);

	spira(n);
}