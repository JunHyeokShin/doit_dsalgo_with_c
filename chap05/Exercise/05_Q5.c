#include <stdio.h>
#include "IntStack.h"

void recur3(int n)
{
	int sw = 0;
	IntStack s1, s2;

	Initialize(&s1, 100); Initialize(&s2, 100);

	while(1) {
		if(n > 0) {
			Push(&s1, n);
			Push(&s2, sw);

			if(sw == 0)
				n = n - 1;
			else if(sw == 1) {
				n = n - 2;
				sw = 0;
			}
			continue;
		}
		do {
			Pop(&s1, &n);
			Pop(&s2, &sw);
			sw++;

			if(sw == 2) {
				printf("%d\n",  n);
				if(IsEmpty(&s1))
					return;
			}
		} while(sw == 2);
	}

	Terminate(&s1); Terminate(&s2);
}

int main(void)
{
	int x;

	printf("정수를 입력하세요 : ");
	scanf("%d", &x);

	recur3(x);

	return 0;
}