#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

//--- �ܼ� ���� ���� ---
void selection(int a[], int n)
{
	int i, j;
	for(i = 0; i < n - 1; i++) {
		int min = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min])
				min = j;
		swap(int, a[i], a[min]);
	}
}

int main(void)
{
	int i, nx;
	int *x;				//�迭�� ù ��° ��ҿ� ���� ������

	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	//����� ������ nx�� int�� �迭�� ����

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	selection(x, nx);				//�迭 x�� �ܼ� ���� ����

	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						//�迭 ����

	return 0;
}