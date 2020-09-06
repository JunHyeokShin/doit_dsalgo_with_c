//�迭�� ������ ���α׷�
#include <stdio.h>
#include <stdlib.h>

#define swap(type, x, y) do {type t = x; x = y; y = t;} while(0)

//--- �迭�� ������ �Լ� ---
void partition(int a[], int n)
{
	int i;
	int pl = 0;			//���� Ŀ��
	int pr = n - 1;		//������ Ŀ��
	int x = a[n / 2];	//�ǹ��� ��� ��Ҹ� �����մϴ�.
	do {
		while(a[pl] < x) pl++;
		while(a[pr] > x) pr--;
		if(pl <= pr) {
			swap(int, a[pl], a[pr]);
			pl++;
			pr--;
		}
	} while(pl <= pr);
	printf("�ǹ��� ���� %d�Դϴ�.\n", x);
	printf("�ǹ� ������ �׷�\n");				//�ǹ� ������ �׷�
	for(i = 0; i <= pl - 1; i++)			//a[0] ~ a[pl - 1]
		printf("%d ", a[i]);
	putchar('\n');
	if(pl > pr + 1) {
		printf("�ǹ��� ��ġ�ϴ� �׷�\n");		//�ǹ��� ���� �׷�
		for(i = pr + 1; i <= pl - 1; i++)	//a[pr + 1] ~ a[pl - 1]
			printf("%d ", a[i]);
		putchar('\n');
	}
	printf("�ǹ� �̻��� �׷�\n");				//�ǹ� �̻��� �׷�
	for(i = pr + 1; i < n; i++)				//a[pr + 1] ~ a[n - 1]
		printf("%d ", a[i]);
	putchar('\n');
}

int main(void)
{
	int i, nx;
	int *x;							//�迭�� ù ��° ��ҿ� ���� ������
	puts("�迭�� �����ϴ�.");
	printf("��� ���� : ");
	scanf("%d", &nx);
	x = calloc(nx, sizeof(int));	//����� ������ nx�� int�� �迭�� ����
	for(i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}
	partition(x, nx);				//�迭 x�� ����
	free(x);						//�迭�� ����

	return 0;
}