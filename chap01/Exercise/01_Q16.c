#include <stdio.h>

void triangleLB(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++)
			printf("* ");
		putchar('\n');
	}
}

void triangleLU(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n - i + 1; j++)
			printf("* ");
		putchar('\n');
	}
}

void triangleRU(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i - 1; j++)
			printf("  ");
		for(j = 1; j <= n - i + 1; j++)
			printf("* ");
		putchar('\n');
	}
}

void triangleRB(int n)
{
	int i, j;
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= n - i; j++)
			printf("  ");
		for(j = 1; j <= i; j++)
			printf("* ");
		putchar('\n');
	}
}

int main(void)
{
	int n;
	
	printf("직각 이등변 삼각형을 출력합니다.\n");
	do {
		printf("크기 : ");
		scanf("%d", &n);
	} while(n <= 0);

	triangleLB(n); printf("\n");
	triangleLU(n); printf("\n");
	triangleRU(n); printf("\n");
	triangleRB(n); printf("\n");

	return 0;
}