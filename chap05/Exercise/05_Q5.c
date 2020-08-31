#include <stdio.h>
#include "IntStack.h"

void recur3(int n)
{
	IntStack s;
	int temp;
	
	Initialize(&s, 100);

	while(1) {
		while(n > 0) {
			Push(&s, n);
			n = n - 1;
		}
		while(!IsEmpty(&s)) {
			temp = n;
			Pop(&s, &n);
			if(n - 2 > 0) {
				if(n - 2 == temp) {
					printf("%d\n", n);
				} else {
					Push(&s, n);
					n = n - 2;
					break;
				}
			} else {
				printf("%d\n", n);
			}
		}
		if(IsEmpty(&s)) {
			break;
		}
	}
	Terminate(&s);
}

int main(void)
{
	int n;

	printf("정수를 입력하세요 : ");
	scanf("%d", &n);

	recur3(n);

	return 0;
}