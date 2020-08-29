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
	printf("정수를 입력하세요 : ");
	scanf("%d", &x);
	recur2(x);

	return 0;
}

/*
recur2함수의 매개변수 n이 4일 때

1. 하향식 분석

recur2(4) = 				recur2(2); 4; recur2(3);
recur2(2) = recur2(0); 2; recur2(1); / 						recur2(3) = recur2(1); 3; recur2(2);
recur2(1) = recur2(-1); 1; recur2(0); / recur2(1) = recur2(-1); 1; recur2(0); / recur2(2) = recur2(0); 2; recur2(1);
recur2(1) = 																	recur2(-1); 1; recur2(0);

result : 2, 1, 4, 1, 3, 2, 1

2. 상향식 분석

recur2(1) = recur2(-1); 1; recur2(0); = 1
recur2(2) = recur2(0); 2; recur2(1); = 2, 1
recur2(3) = recur2(1); 3; recur2(2); = 1, 3, 2, 1
recur2(4) = recur2(2); 4; recur2(3); = 2, 1, 4, 1, 3, 2, 1
*/