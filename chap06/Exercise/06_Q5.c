#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

void bubble(int a[], int n)
{
	int k = 0, i = 0, m;
	int count1 = 0, count2 = 0;
	while(k < n - 1) {
		int j;
		int last = n - 1;

		printf("�н�%d:\n", ++i);
		for(j = n - 1; j > k; j--) {
			for(m = 0; m < j; m++)
				printf(" %d", a[m]);
			printf("%c", a[j - 1] > a[j] ? '+' : '-');
			for(m = j; m < n; m++)
				printf("%d ", a[m]);
			putchar('\n');

			count1++;
			if(a[j - 1] > a[j]) {
				count2++;
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		}
		k = last;
	}
	printf("�񱳸� %dȸ �߽��ϴ�.\n", count1);
	printf("��ȯ�� %dȸ �߽��ϴ�.\n", count2);
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}