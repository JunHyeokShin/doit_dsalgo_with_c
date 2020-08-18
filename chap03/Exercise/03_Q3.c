#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[])
{
	int i, count = 0;

	for(i = 0; i < n; i++)
		if(a[i] == key)
			idx[count++] = i;
	return count;
}

int main(void)
{
	int i, nx, ky;
	int no;
	int *x;
	int *idx;

	puts("���� �˻�");
	printf("��ڼ� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));
	idx = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("�˻� �� : ");
	scanf("%d", &ky);

	no = search_idx(x, nx, ky, idx);

	if(no == 0)
		puts("��ġ�ϴ� ��Ұ� �����ϴ�.");
	else {
		printf("��ġ�ϴ� ��� ������ %d���Դϴ�.\n", no);
		for(i = 0; i < no; i++)
			printf("x[%d] ", idx[i]);
	}

	free(x);
	free(idx);

	return 0;
}