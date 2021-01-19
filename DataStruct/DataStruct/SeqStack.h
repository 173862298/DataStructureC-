#ifndef _DATASTRUCT_SEQSTACK
#define _DATASTRUCT_SEQSTACK
#include <iostream>
using std::cout;
using std::endl;

//=============ջ��˳��ʵ��=========================================
//˳��ջ��һ��һά�����һ����¼ջ��λ�õı�����ʵ��
/*
* ���磺��ջʱ��top=0����ʱ����ջ���㡣
* ���磺ջ��ʱ���ٽ��н�ջ������
*/
const int maxsize = 6;
typedef struct seqstack
{
	double data[maxsize];//һά����
	int top;  //��ʶջ��Ԫ�أ�0�����ջ����Χ0��maxsize-1
}SeqStk;

//��ʼ��
int InitStack(SeqStk *stk)
{
	stk->data[maxsize] = {0.0};
	stk->top = 0;
	return 1;
}
//�жϿ�ջ
int EmptyStack(SeqStk *stk)
{
	if (stk->top == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
//��ջ
int Push(SeqStk *stk, double x)
{
	if (stk->top < maxsize-1)
	{
		stk->data[stk->top] = x;
		stk->top++;
		return 1;
	}
	else
	{
		cout << "ջ��" << endl;
		return 0;//ջ��
	}
}
int Pop(SeqStk *stk)
{
	if (EmptyStack(stk) == 1)
	{
		return 0;//��ջ,����
	}
	else
	{
		stk->data[stk->top] = 0;
		stk->top--;
		return 1;
	}
}
double GetTop(SeqStk *stk)
{
	if (EmptyStack(stk) == 1)
	{
		return 0;//��ջ
	}
	else
	{
		return stk->data[stk->top];
	}
}

void PrintStack(SeqStk *stk)
{
	for (auto var : stk->data)
	{
		cout << var << ",";
	}
	cout << endl;
	cout << "ջ���ȣ�" << stk->top << endl;
}

//=============ջ����ʽʵ��=========================================
/*
��ջ�����ô�ͷ���ĵ�����ʵ�֣�LSָ�������ͷ��㣬�׽����ջ��Ԫ�ء�LS->nextָ��ջ����㡣β���Ϊջ�׽�㡣
����Ԥ�ȿ���������С��
*/
typedef struct nodeT
{
	double data;
	struct nodeT *next;
}LkStk;

void InitStack(LkStk *LS)
{
	//��ʼ��
	LS = (LkStk*)malloc(sizeof(LkStk));
	LS->data = 0;
	LS->next = NULL;		//����һ����ջ
}
int EmptyStack(LkStk *LS)
{
	if (LS->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Push(LkStk *LS, double data)
{
	//����һ����ʱ��㣬�����ڴ�
	LkStk *temp;
	temp = (LkStk*)malloc(sizeof(LkStk));
	temp->data = data;
	temp->next = LS->next;
	LS->next = temp;
}
int Pop(LkStk *LS)
{
	//��ʱָ��ָ��ɾ�����
	LkStk *temp;
	if (!EmptyStack(LS))
	{
		temp = LS->next;
		LS->next = temp->next;
		free(temp);
		temp = NULL;
		return 1;
	}
	else
	{
		return 0;
	}
}
double GetTop(LkStk *LS)
{
	if (!EmptyStack(LS))
	{
		return LS->next->data;
	}
	else
	{
		return NULL;
	}
}
//��ӡ
void PrintLStack(LkStk *LS)
{
	LkStk *temp = LS;	
	
	while (temp->next != NULL)
	{	
		temp = temp->next;
		cout << temp->data << endl;		
	}
	cout << "end" << endl;
}

#endif