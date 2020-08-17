#include <stdio.h>

typedef struct {
	int y;
	int m;
	int d;
} Date;

Date After(Date x, int n);
Date Before(Date x, int n);

int mdays[2][12] = {
	{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int isleap(int y)
{
	return y % 4 == 0 && y % 100 != 0 || y % 400 == 0;
}

Date DateOf(int y, int m, int d)	//y�� m�� d���� ��Ÿ���� ����ü�� ��ȯ�ϴ� �Լ�
{
	Date temp;

	temp.y = y;
	temp.m = m;
	temp.d = d;

	return temp;
}

Date After(Date x, int n)	//��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
{
	if(n < 0)
		return Before(x, -n);

	x.d += n;
	while(x.d > mdays[isleap(x.y)][x.m - 1]) {
		x.d -= mdays[isleap(x.y)][x.m - 1];
		if(++x.m > 12) {
			x.y++;
			x.m = 1;
		}
	}
	return x;
}

Date Before(Date x, int n)	//��¥ x�� n�� ���� ��¥�� ��ȯ�ϴ� �Լ�
{
	if(n < 0)
		return After(x, -n);
	
	x.d -= n;
	while(x.d < 1) {
		if(--x.m < 1) {
			x.y--;
			x.m = 12;
		}
		x.d += mdays[isleap(x.y)][x.m - 1];
	}
	return x;
}

void Print(Date x)
{
	int y = x.y;
	int m = x.m;
	int d = x.d;

	printf("%04d�� %02d�� %02d��\n", x.y, x.m, x.d);
}

int main(void)
{
	int n;
	int y, m, d;
	Date x;

	printf("��¥�� �Է��ϼ���.\n");
	printf("�� : "); scanf("%d", &y);
	printf("�� : "); scanf("%d", &m);
	printf("�� : "); scanf("%d", &d);

	x = DateOf(y, m, d);

	printf("��ĥ ��/���� ��¥�� ���ұ��? : ");
	scanf("%d", &n);

	printf("%d�� ���� ��¥ : ", n); Print(After(x, n));
	printf("%d�� ���� ��¥ : ", n); Print(Before(x, n));

	return 0;
}