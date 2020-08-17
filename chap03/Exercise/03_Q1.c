#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key)
{
	int i;
	a[n] = key;
	for(i = 0; i < n; i++)
		if(a[i] == key)
			return i == n ? -1 : i;
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;
	puts("���� �˻�(���ʹ�)");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx + 1, sizeof(int));
	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	printf("�˻��� : ");
	scanf("%d", &ky);
	idx = search(x, nx, ky);
	if(idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);

	return 0;
}