#include <stdio.h>

int str_ncmp(const char *s1, const char *s2, size_t n)
{
	while(*s1 && *s2 && n) {
		if(*s1 != *s2)
			break;
		s1++;
		s2++;
		n--;
	}
	if(!n) return 0;
	else if(*s1 > *s2) return 1;
	return -1;
}

int main(void)
{
	char st[128];
	puts("\"STRING\"�� ó�� 3���� ���ڿ� ���մϴ�.");
	puts("\"XXXX\"�� �Է��ϸ� �����մϴ�.");
	while(1) {
		printf("���ڿ� st : ");
		scanf("%s", st);
		if(str_ncmp("XXXX", st, 3) == 0)
			break;
		printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
	}

	return 0;
}