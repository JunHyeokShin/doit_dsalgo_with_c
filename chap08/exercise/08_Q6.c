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

	printf("���ڿ� : ");
	scanf("%s", str);

	printf("�˻��� ���� : ");
	scanf("%s", tmp);
	ch = tmp[0];

	if((idx = str_rchr(str, ch)) == NULL)
		printf("���� '%c'��(��) ���ڿ��� �����ϴ�.\n", ch);
	else
		printf("���� '%c'��(��) %d��°�� �ֽ��ϴ�.\n", ch, (idx - str) + 1);


	return 0;
}