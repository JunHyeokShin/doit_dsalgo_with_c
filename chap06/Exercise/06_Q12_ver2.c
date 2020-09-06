#include <stdio.h>
#include <stdlib.h>

int shell(int a[], int n)
{
	int i, j, h;
	int count = 0;

	for(h = 1; h < n / 9; h = h * 3 + 1)
		;
	for(; h > 0; h /= 3)
		for(i = h; i < n; i++) {
			int tmp = a[i];
			for(j = i - h; j >= 0 && a[j] > tmp; j -= h) {
				a[j + h] = a[j];
				count++;
			}
			a[j + h] = tmp;
			count++;
		}
	return count;
}

int main(void)
{
	int i, nx;
	int count;
	int *x;

	puts("�� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	count = shell(x, nx);
	puts("������������ �����߽��ϴ�.");

	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	printf("����� �̵� Ƚ���� %dȸ �Դϴ�.\n", count);

	free(x);
	return 0;
}