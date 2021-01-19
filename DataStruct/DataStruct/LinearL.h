#ifndef LINEAR_SEQUENCE
#define LINEAR_SEQUENCE
#include <iostream>
using namespace std;

// ���Ա��˳��洢
const int MaxSize = 100;
typedef struct
{
	double data[MaxSize];
	int length = 0;//���ʵ�ʳ���
}SeqList;

void Insert(SeqList *L, double x, int i)
{
	//�ڵ�i��Ԫ��֮ǰ����x
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
	//ɾ����i��Ԫ��
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
	//��λ����x��λ�ã��Ҳ���-1
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
//----���Ա����ʽ�洢-----------------------------------
typedef struct node
{
	double data;  //������
	struct node * next;  //ָ����ָ����һ���ڵ�
}Node,*LinkList;

//��ʼ������ͷ���Ϊ�գ�һ�����������һ��ͷ���
LinkList InitLinkList()  
{
	LinkList head;
	head = (LinkList)malloc(sizeof(Node));
	head->data = 0.0;
	head->next = NULL;
	return head;
}


//���
int LengthLinkList(LinkList head)
{
	Node *p = head;//��ȡ������������������ʱ����p
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
//����һ�����i����ѯ��i������
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
//�ҳ�Ԫ�ص�λ��
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
//����
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
			//��ĩ
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
//ɾ����i���ڵ�
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

	cout << "������Ϊ��" << cnt << " ��end��" << endl;	
}


#endif