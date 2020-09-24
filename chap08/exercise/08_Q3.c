#include <stdio.h>

void swap_str(char *x, char *y)
{
	char *temp;
	while(*x && *y) {
		char t = *x;
		*x++ = *y;
		*y++ = t;
	}
	if(*x) {
		temp = x;
		while(*x)
			*y++ = *x++;
		*temp = *y = '\0';
	} else if(*y) {
		temp = y;
		while(*y)
			*x++ = *y++;
		*temp = *x = '\0';
	} else {
		*x = *y = '\0';
	}
}

int main(void)
{
	char s1[128], s2[128];

	printf("문자열 S1 : "); scanf("%s", s1);
	printf("문자열 S2 : "); scanf("%s", s2);

	swap_str(s1, s2);

	puts("두 문자열을 교환했습니다.\n");
	printf("문자열 S1 : %s\n", s1);
	printf("문자열 S2 : %s\n", s2);

	return 0;
}