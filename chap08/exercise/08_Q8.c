#include <stdio.h>
#include <ctype.h>


int str_cmpic(const char *s1, const char *s2)
{
	while(toupper(*s1) == toupper(*s2)) {
		if(*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)toupper(*s1) - (unsigned char)toupper(*s2);
}

int str_ncmpic(const char *s1, const char *s2, size_t n)
{
	while(*s1 && *s2 && n) {
		if(toupper(*s1) != toupper(*s2))
			break;
		s1++;
		s2++;
		n--;
	}
	if(!n) return 0;
	else if(toupper(*s1) > toupper(*s2)) return 1;
	return -1;
}

int main(void)
{
	int n, retry;
	char s1[256], s2[256];

	puts("��/�ҹ��ڸ� �������� �ʴ� ���ڿ� ��");

	do {
		printf("s1 : "); scanf("%s", s1);
		printf("s2 : "); scanf("%s", s2);
		printf("�� ���ڼ� : "); scanf("%d", &n);

		printf("str_ncmp (\"%s\", \"%s\") = %d\n", s1, s2, str_cmpic(s1, s2));
		printf("str_ncmpic (\"%s\", \"%s\", %d) = %d\n", s1, s2, n, str_ncmpic(s1, s2, n));
		printf("�ٽ� �� ��? [0 �� No / 1 �� Yes] : ");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}