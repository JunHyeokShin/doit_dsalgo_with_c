#include <stdio.h>
#include <stdlib.h>

void insertion(int a[], int n)
{
	int i, j;

	a[0] = -1;
	for(i = 2; i < n; i++) {
		int tmp = a[i];
		for(j = i; a[j - 1] > tmp; j--)
			a[j] = a[j - 1];
		a[j] = tmp;
	}
}

int main(void)
{
	int i, nx;
	int *x;		

	puts("�ܼ� ���� ����");
	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));

	for (i = 1; i < nx + 1; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	insertion(x, nx + 1);				

	puts("������������ �����߽��ϴ�.");
	for (i = 1; i < nx + 1; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}