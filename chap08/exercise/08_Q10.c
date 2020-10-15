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

	puts("���Ʈ-������(�˻� ���ڿ��� ������ �ε��� ��ȯ)");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);

	idx = bf_matchr(s1, s2);
	
	if(idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ڿ� match�մϴ�.\n", idx);

	return 0;
}