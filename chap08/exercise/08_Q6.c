#include <stdio.h>

char *str_rchr(const char *s, int c)
{
	const char *p = NULL;

	c = (char)c;
	while(1) {
		if(*s == c)
			p = s;
		if(*s == '\0')
			break;
		s++;
	}
	return (char *)p;
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

	if((idx = str_rchr(str, ch)) == NULL)
		printf("문자 '%c'은(는) 문자열에 없습니다.\n", ch);
	else
		printf("문자 '%c'은(는) %d번째에 있습니다.\n", ch, (idx - str) + 1);


	return 0;
}