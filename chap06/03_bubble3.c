//���� ����
#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

//--- ���� ����(���� 3 : ��ĵ ������ �����մϴ�.) ---
void bubble(int a[], int n)
{
	int k = 0;		//a[k]���� ������ ��Ҵ� ������ ��ģ �����Դϴ�.
	while(k < n - 1) {
		int j;
		int last = n - 1;	//���������� ��ȯ�� ������ ��ġ�� �����մϴ�.
		for(j = n - 1; j > k; j--)
			if(a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				last = j;
			}
		k = last;
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

	bubble(x, nx);					//�迭 x�� ���� ����

	puts("������������ �����߽��ϴ�.");
	for(i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);						//�迭 ����

	return 0;
}