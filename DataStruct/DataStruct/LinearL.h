#ifndef LINEAR_SEQUENCE
#define LINEAR_SEQUENCE
#include <iostream>
using namespace std;

// 线性表的顺序存储
const int MaxSize = 100;
typedef struct
{
	double data[MaxSize];
	int length = 0;//表的实际长度
}SeqList;

void Insert(SeqList *L, double x, int i)
{
	//在第i个元素之前插入x
	if (i<0 || i>L->length)
	{
		return;
	}
	if (L->length == MaxSize)
	{
		return;
	}
	for (int j = L->length; j>=i; j--)
	{		
		L->data[j] = L->data[j-1];
	}
	L->data[i] = x;
	L->length++;
}
void Delete(SeqList *L, int i)
{
	//删除第i个元素
	if (i < 0 || i >= L->length)
	{
		return;
	}
	for (int j = i; j < L->length-1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
}
int Locate(SeqList *L, double x)
{
	//定位数据x的位置，找不到-1
	for (int i = 0; i < L->length; i++)
	{
		if (L->data[i] == x)
		{
			return i;
		}
	}
	return -1;
}
void Print(SeqList *L)
{
	for (int i = 0; i < L->length; i++)
	{
		cout << L->data[i] << endl;
	}
	cout << "------------------------" << endl;
}
//----线性表的链式存储-----------------------------------
typedef struct node
{
	double data;  //数据域
	struct node * next;  //指针域，指向下一个节点
}Node,*LinkList;

//初始化链表，头结点为空，一个空链表仅有一个头结点
LinkList InitLinkList()  
{
	LinkList head;
	head = (LinkList)malloc(sizeof(Node));
	head->data = 0.0;
	head->next = NULL;
	return head;
}


//求表长
int LengthLinkList(LinkList head)
{
	Node *p = head;//读取链表，不操作链表，用临时变量p
	int cnt = 0;
	while (p->next != NULL)
	{
		cnt++;
		p = p->next;
	}
	return cnt;
}
void DestroyLinkList(LinkList head)
{
	int len = LengthLinkList(head);
	if (len == 0)
	{
		free(head);
		head = nullptr;
	}

}
//给定一个序号i，查询第i个数据
Node * GetLinkList(LinkList head, int i)
{
	int cnt = 0;
	Node *p = head;
	while (p->next != NULL)
	{
		cnt++;
		p = p->next;
		if (cnt == i)
		{
			return p;
		}
		
	}
	return NULL;
}
//找出元素的位置
int LocateLinkList(LinkList head, double x)
{
	int cnt = 0, ypos = 0;
	Node * p = head;
	while (p->next != NULL)
	{
		cnt++;
		p = p->next;
		if (p->data == x)
		{
			ypos = cnt;
			return ypos;
		}		
	}
	return ypos;
}
//插入
void InsertLinkList(LinkList head, double x, int i)
{
	if (i < 0 || i > LengthLinkList(head)+ 1)
	{
		printf("\a");
		return;
	}
	Node *p = head;
	Node *n = NULL;
	int cnt = 1;
	
	for (; cnt <= i; cnt++)
	{		
		if (cnt == i)
		{
			n = (LinkList)malloc(sizeof(Node));
			n->data = x;
			//最末
			if (p->next == NULL)
			{
				p->next = n;
				n->next = NULL;
				return;
			}
			else
			{				
				n->next = p->next;
				p->next = n;
				return;
			}			
		}
		p = p->next;
	}	
}
//删除第i个节点
void DeleteLinkList(LinkList head, int i)
{
	if (i < 0 || i > LengthLinkList(head) )
	{
		printf("\a");
		return;
	}
	int cnt = 0;
	Node *p = head;
	Node *d = nullptr;
	while (p->next != NULL)
	{
		cnt++;		
		if (cnt == i)
		{
			d = p->next;
			p->next = d->next;
			free(d);
			d = nullptr;
			return;
		}
		p = p->next;
	}
	d = nullptr;
}
//dayin
void PrintLinkList(LinkList head)
{
	Node *p = head;
	int cnt = 0;
	while (p->next != NULL)
	{
		cnt++;
		p = p->next;
		cout << p->data << endl;
	}

	cout << "链表长度为：" << cnt << " ，end。" << endl;	
}


#endif