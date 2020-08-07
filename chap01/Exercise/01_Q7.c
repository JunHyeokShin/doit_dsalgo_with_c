#include <stdio.h>

int main(void)
{
	int i, n;
	int sum;
	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 : ");
	scanf("%d", &n);
	sum = 0;
	for(i = 1; i <= n; i++) {
		sum += i;
		if(i != n)
			printf("%d + ", i);
		else
			printf("%d = %d", i, sum);
	}
}