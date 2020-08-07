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
	printf("����1�� �Է��ϼ��� : ");
	scanf("%d", &num1);
	printf("����2�� �Է��ϼ��� : ");
	scanf("%d", &num2);

	printf("����1, ����2 ������ ��� ������ ���� %d�Դϴ�.\n", sumof(num1, num2));
	return 0;
}