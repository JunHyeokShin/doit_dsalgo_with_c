#include <stdio.h>

void recur2(int n)
{
	if(n > 0) {
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}

int main(void)
{
	int x;
	printf("������ �Է��ϼ��� : ");
	scanf("%d", &x);
	recur2(x);

	return 0;
}

/*
recur2�Լ��� �Ű����� n�� 4�� ��

1. ����� �м�

recur2(4) = 				recur2(2); 4; recur2(3);
recur2(2) = recur2(0); 2; recur2(1); / 						recur2(3) = recur2(1); 3; recur2(2);
recur2(1) = recur2(-1); 1; recur2(0); / recur2(1) = recur2(-1); 1; recur2(0); / recur2(2) = recur2(0); 2; recur2(1);
recur2(1) = 																	recur2(-1); 1; recur2(0);

result : 2, 1, 4, 1, 3, 2, 1

2. ����� �м�

recur2(1) = recur2(-1); 1; recur2(0); = 1
recur2(2) = recur2(0); 2; recur2(1); = 2, 1
recur2(3) = recur2(1); 3; recur2(2); = 1, 3, 2, 1
recur2(4) = recur2(2); 4; recur2(3); = 2, 1, 4, 1, 3, 2, 1
*/