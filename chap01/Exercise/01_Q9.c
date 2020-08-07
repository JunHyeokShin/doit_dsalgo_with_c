#include <stdio.h>

int sumof(int a, int b)
{
	int sum_a, sum_b;
	int result;

	sum_a = (1 + a) * a / 2;
	sum_b = (1 + b) * b / 2;
	result = (sum_a <= sum_b) ? (sum_b - sum_a + a) : (sum_a - sum_b + b);

	return result;
}

int main(void)
{
	int num1, num2;
	printf("정수1을 입력하세요 : ");
	scanf("%d", &num1);
	printf("정수2를 입력하세요 : ");
	scanf("%d", &num2);

	printf("정수1, 정수2 사이의 모든 정수의 합은 %d입니다.\n", sumof(num1, num2));
	return 0;
}