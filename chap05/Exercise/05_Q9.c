#include <stdio.h>
#include "IntStack.h"

int flag_a[8];
int flag_b[15];
int flag_c[15];
int pos[8];

void print(void)
{
	int i;

	for (i = 0; i < 8; i++)
		printf("%2d", pos[i]);
	putchar('\n');
}

void set(int i)
{
	int j = 0, gotoTop;
	IntStack jstk;
	Initialize(&jstk, 8);

	while (1) {
		gotoTop = 0;
		while(j < 8) {
			if (!flag_a[j] && !flag_b[i + j] && !flag_c[i - j + 7]) {
				pos[i] = j;					
				if (i == 7)
					print();
				else {
					flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 1;
					i++;
					Push(&jstk, j);
					j = 0;
					gotoTop = 1;
					break;
				}
			}
			j++;
		}
		if(gotoTop == 1)
			continue;
		if (--i == -1) return;
		Pop(&jstk, &j);
		flag_a[j] = flag_b[i + j] = flag_c[i - j + 7] = 0;
		j++;
	}
	Terminate(&jstk);
}

int main(void)
{
	int i;

	for (i = 0; i < 8; i++)
		flag_a[i] = 0;
	for (i = 0; i < 15; i++)
		flag_b[i] = flag_c[i] = 0;

	set(0);

	return 0;
}