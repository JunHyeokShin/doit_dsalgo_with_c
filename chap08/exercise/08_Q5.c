#include <stdio.h>
#include <string.h>

char *str_chr(const char *s, int c)
{
	c = (char)c;
	while(*s != c) {
		if(*s == '\0')
			return NULL;
		s++;
	}
	return (char *)s;
}

int main(void)
{
	char str[64];
	char tmp[64];
	int ch;
	char *idx;

	printf("문자열 : ");
	scanf("%s", str);

	printf("검색할 문자 : ");
	scanf("%s", tmp);
	ch = tmp[0];

	if((idx = str_chr(str, ch)) == NULL)
		printf("문자 '%c'은(는) 문자열에 없습니다.\n", ch);
	else
		printf("문자 '%c'은(는) %d번째에 있습니다.\n", ch, (idx - str) + 1);


	return 0;
}