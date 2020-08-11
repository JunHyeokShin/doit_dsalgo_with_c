#include <stdio.h>
#include <stdlib.h>

void ary_rcopy(int a[], const int b[], int n)
{
	int i;
	for(i = 0; i < n; i++)
		a[i] = b[n - i - 1];
}

int main(void)

{
	int i, n;
	int *x, *y;

	printf("��� ������ �Է��ϼ��� : ");
	scanf("%d", &n);
	x = calloc(n, sizeof(int));
	y = calloc(n, sizeof(int));

	printf("��� ������ %d���� �迭�� ������ �����մϴ�.\n", n);
	for(i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	ary_rcopy(y, x, n);

	printf("�迭 x�� ��� ��Ҹ� �迭 y�� �����߽��ϴ�.\n");
	for(i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x);
	free(y);

	return 0;
}