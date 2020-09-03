#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

int is_sorted(const int a[], int n)
{
	int i;
	for(i = n - 1; i > 0; i--)
		if(a[i - 1] > a[i])
			return 0;
	return 1;
}

int main(void)
{
	int i, nx, sorted;
	int *x;

	puts("���� ���� ����(�迭 ���� �˻�)");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	sorted = is_sorted(x, nx);

	if(sorted)
		puts("�迭�� ���ĵǾ� �ֽ��ϴ�.");
	else
		puts("�迭�� ���ĵǾ����� �ʽ��ϴ�.");

	free(x);

	return 0;
}