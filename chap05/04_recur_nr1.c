#include <stdio.h>

//--- �Լ� recur(���� ��͸� ����) ---
void recur(int n)
{
Top:
	if(n > 0) {
		recur(n - 1);
		printf("%d\n", n);
		n = n - 2;
		goto Top;
	}
}

int main(void)
{
	int x;

	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);

	recur(x);

	return 0;
}