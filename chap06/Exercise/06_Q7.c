#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)

void selection(int a[], int n)
{
	int i, j, k;

	for(i = 0; i < n - 1; i++) {
		int min = i;

		for(j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;

		printf("%*.*s%*.*s\n", i * 2 + 2, 1, "*", (min - i) * 2, 1, "+");
		for(k = 0; k < n; k++)
			printf("%2d", a[k]);
		putchar('\n');
		
		swap(int, a[i], a[min]);
	}
	putchar('\n');
	for(k = 0; k < n; k++)
		printf("%2d", a[k]);
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

	selection(x, nx);

	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}