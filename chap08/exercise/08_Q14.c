#include <stdio.h>
#include <string.h>

char *str_rstr(const char *s1, const char *s2)
{
	int s1_len = strlen(s1);
	int s2_len = strlen(s2);
	int pt = s1_len - s2_len;
	int pp;

	while(pt >= 0) {
		pp = 0;
		while(s1[pt] == s2[pp]) {
			if(pp == s2_len - 1)
				return (char *)s1 + pt - pp;
			pp++;
			pt++;
		}
		pt = pt - pp - 1;
	}

	return NULL;
}

int main(void)
{
	char s1[256], s2[256];
	char *p;

	puts("str_rstr �Լ�");
	printf("�ؽ�Ʈ: ");
	scanf("%s", s1);
	printf("����: ");
	scanf("%s", s2);

	p = str_rstr(s1, s2);

	if (p == NULL)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
	else {
		int ofs = p - s1;
		printf("\n%s\n", s1);
		printf("%*s|\n", ofs, "");
		printf("%*s%s\n", ofs, "", s2);
	}

	return 0;
}