#include <stdio.h>

int main(void)
{
	int n;
	int digits = 0;

	do{
		printf("양의 정수 : ");
		scanf("%d", &n);
	} while(n <= 0);

	while(n > 0) {
		n /= 10;
		digits++;
	}

	printf("이 수는 %d자리입니다.\n", digits);

	return 0;
}