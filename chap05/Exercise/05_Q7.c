#include <stdio.h>
#include "IntStack.h"

void move(int no, int x, int y)
{
	IntStack s1, s2, s3;

	Initialize(&s1, 100);
	Initialize(&s2, 100);
	Initialize(&s3, 100);

	while(1) {
		while(no > 1) {
			Push(&s1, no);
			Push(&s2, x);
			Push(&s3, y);
			no = no - 1;
			y = 6 - x - y;
		}
		printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);
		if(!IsEmpty(&s1)) {
			Pop(&s1, &no);
			Pop(&s2, &x);
			Pop(&s3, &y);
			printf("원반[%d]를(을) %d 기둥에서 %d 기둥으로 옮김\n", no, x, y);
			no = no - 1;
			x = 6 - x - y;
		} else {
			break;
		}
	}
	Terminate(&s1); Terminate(&s2); Terminate(&s3);
}

int main(void)
{
	int n;
	printf("하노이의 탑\n원반 개수 : ");
	scanf("%d", &n);
	move(n, 1, 3);

	return 0;
}