#ifndef _DATASTRUCT_SEQSTACK
#define _DATASTRUCT_SEQSTACK
#include <iostream>
using std::cout;
using std::endl;

//=============栈的顺序实现=========================================
//顺序栈由一个一维数组和一个记录栈顶位置的变量来实现
/*
* 下溢：空栈时，top=0，此时做出栈运算。
* 上溢：栈满时，再进行进栈操作。
*/
const int maxsize = 6;
typedef struct seqstack
{
	double data[maxsize];//一维数组
	int top;  //标识栈顶元素，0代表空栈，范围0到maxsize-1
}SeqStk;

//初始化
int InitStack(SeqStk *stk)
{
	stk->data[maxsize] = {0.0};
	stk->top = 0;
	return 1;
}
//判断空栈
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
//进栈
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
		cout << "栈满" << endl;
		return 0;//栈满
	}
}
int Pop(SeqStk *stk)
{
	if (EmptyStack(stk) == 1)
	{
		return 0;//空栈,下溢
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
		return 0;//空栈
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
	cout << "栈长度：" << stk->top << endl;
}

//=============栈的链式实现=========================================
/*
链栈可以用带头结点的单链表实现，LS指向链表的头结点，首结点是栈顶元素。LS->next指向栈顶结点。尾结点为栈底结点。
不用预先考虑容量大小。
*/
typedef struct nodeT
{
	double data;
	struct nodeT *next;
}LkStk;

void InitStack(LkStk *LS)
{
	//初始化
	LS = (LkStk*)malloc(sizeof(LkStk));
	LS->data = 0;
	LS->next = NULL;		//建立一个空栈
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
	//建立一个临时结点，分配内存
	LkStk *temp;
	temp = (LkStk*)malloc(sizeof(LkStk));
	temp->data = data;
	temp->next = LS->next;
	LS->next = temp;
}
int Pop(LkStk *LS)
{
	//临时指针指向被删除结点
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
//打印
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