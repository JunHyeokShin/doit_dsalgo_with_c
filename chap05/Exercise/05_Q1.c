#include <stdio.h>

int factorial(int n)
{
	int fact = 1;

	while(n > 1)
		fact *= n--;
	return fact;
}

int main(void)
{
	int x;

	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	printf("%d의 factorial은 %d입니다.\n", x, factorial(x));

	return 0;
}