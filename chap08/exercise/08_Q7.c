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
	puts("\"STRING\"의 처음 3개의 문자와 비교합니다.");
	puts("\"XXXX\"를 입력하면 종료합니다.");
	while(1) {
		printf("문자열 st : ");
		scanf("%s", st);
		if(str_ncmp("XXXX", st, 3) == 0)
			break;
		printf("str_ncmp(\"STRING\", st, 3) = %d\n", str_ncmp("STRING", st, 3));
	}

	return 0;
}