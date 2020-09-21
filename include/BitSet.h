//��Ʈ ���� ���� BitSet(���)
#ifndef ___BitSet
#define ___BitSet

typedef unsigned long BitSet;				//������ ��Ÿ���� �ڷ���

#define BitSetNull (BitSet)0				//������
#define BitSetBits 32						//��ȿ ��Ʈ ��
#define SetOf(no) ((BitSet)1 << (no))		//���� {no}

//--- ���� s�� n�� �ִ��� Ȯ�� ---
int IsMember(BitSet s, int n);

//--- ���� s�� n�� �߰� ---
void Add(BitSet *s, int n);

//--- ���� s���� n�� ���� ---
void Remove(BitSet *s, int n);

//--- ���� s�� ���� ������ ��ȯ ---
int Size(BitSet s);

//--- ���� s�� ��� ���Ҹ� ��� ---
void Print(BitSet s);

//--- ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����) ---
void PrintLn(BitSet s);

#endif