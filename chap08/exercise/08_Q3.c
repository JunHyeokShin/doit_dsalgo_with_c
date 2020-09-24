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

	printf("���ڿ� S1 : "); scanf("%s", s1);
	printf("���ڿ� S2 : "); scanf("%s", s2);

	swap_str(s1, s2);

	puts("�� ���ڿ��� ��ȯ�߽��ϴ�.\n");
	printf("���ڿ� S1 : %s\n", s1);
	printf("���ڿ� S2 : %s\n", s2);

	return 0;
}