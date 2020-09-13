//���� ���� ���α׷�
#include <stdio.h>
#include <stdlib.h>

static int *buff;		//�۾��� �迭

//--- ���� ����(main) ---
static void __mergesort(int a[], int left, int right)
{
	if(left < right) {
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;
		__mergesort(a, left, center);			//�պκп� ���� ���� ����
		__mergesort(a, center + 1, right);		//�޺κп� ���� ���� ����
		for(i = left; i <= center; i++)
			buff[p++] = a[i];
		while(i <= right && j < p)
			a[k++] = (buff[j] <= a[i]) ? buff[j++] : a[i++];
		while(j < p)
			a[k++] = buff[j++];
	}
}

//--- ���� ���� �Լ� ---
int mergesort(int a[], int n)
{
	if((buff = calloc(n, sizeof(int))) == NULL)
		return -1;
	__mergesort(a, 0, n - 1);		//�迭 ��ü�� ���� ����
	free(buff);
	return 0;
}

int main(void)
{
	int i, nx;
	int *x;		//�迭�� ù ��° ��ҿ� ���� ������
	puts("���� ����");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));

	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	mergesort(x, nx);		//�迭 x�� ���� ����
	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);	//�迭�� ����

	return 0;
}