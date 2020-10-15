#include <stdio.h>

int bf_matchr(const char txt[], const char pat[])
{
	int pt = 0;
	int pp = 0;
	while(txt[pt] != '\0' && pat[pp] != '\0') {
		if(txt[pt] == pat[pp]) {
			pt++;
			pp++;
		} else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}
	if(pat[pp] == '\0')
		return pt;
	return -1;
}

int main(void)
{
	int idx;
	char s1[256];
	char s2[256];

	puts("브루트-포스법(검색 문자열의 마지막 인덱스 반환)");
	printf("텍스트 : ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s", s2);

	idx = bf_matchr(s1, s2);
	
	if(idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자와 match합니다.\n", idx);

	return 0;
}