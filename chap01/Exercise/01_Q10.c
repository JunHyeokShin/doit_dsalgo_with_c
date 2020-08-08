#include <stdio.h>

int main(void)
{
	int a, b;

	printf("a의 값 : ");
	scanf("%d", &a);

	do {
		printf("b의 값 : ");
		scanf("%d", &b);
		if(b <= a)
			printf("a보다 큰 값을 입력하세요!\n");
	} while(b <= a);
	
	printf("b - a는 %d입니다.\n", b - a);

	return 0;
}