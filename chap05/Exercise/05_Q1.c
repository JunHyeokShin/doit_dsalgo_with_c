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

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	printf("%d�� factorial�� %d�Դϴ�.\n", x, factorial(x));

	return 0;
}