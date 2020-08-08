//왼쪽 아래가 직각인 이등변 삼각형을 출력합니다.
#include <stdio.h>

int main(void)
{
	int i, j, n;
	do {
		printf("몇 단 삼각형입니까? : ");
		scanf("%d", &n);
	} while(n <= 0);
	for(i = 1; i <= n; i++) {
		for(j = 1; j <= i; j++)
			printf("* ");
		putchar('\n');
	}

	return 0;
}