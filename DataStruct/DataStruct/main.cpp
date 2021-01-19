#include "LinearL.h"
#include "SeqStack.h"
#include <vld.h>

int main()
{
#if 0
	SeqList list;	
	int i = list.length;
	Insert(&list, 3.0, 0);
	//Print(&list);
	Insert(&list, 4, 0);
	//Print(&list);
	Insert(&list, 5, 0);
	//Print(&list);
	Insert(&list, 6, 0);
	Insert(&list, 9, 5);
	Print(&list);
	Delete(&list,0);
	Print(&list);	
	cout << Locate(&list, 1) << endl;
#endif

#if 0
	//测试单向链表
	LinkList head = InitLinkList();
	PrintLinkList(head);
	InsertLinkList(head, 11, 1);
	InsertLinkList(head, 12, 2);
	InsertLinkList(head, 13, 3);
	InsertLinkList(head, 14, 4);
	InsertLinkList(head, 15, 5);		
	PrintLinkList(head);

	InsertLinkList(head, 23, 3);
	PrintLinkList(head);
	InsertLinkList(head, 17, 7);
	PrintLinkList(head);
	cout <<"长度："<< LengthLinkList(head) << endl;
	cout << "元素位置：" << LocateLinkList(head, 11)<<endl;
	DeleteLinkList(head, 5);
	DeleteLinkList(head, 1);
	DeleteLinkList(head, 1);
	DeleteLinkList(head, 1);
	DeleteLinkList(head, 1);
	DeleteLinkList(head, 1);
	DeleteLinkList(head, 1);
	//DeleteLinkList(head, 1);
	cout << "长度：" << LengthLinkList(head) << endl;
	DestroyLinkList(head);
#endif

#if 0
	SeqStk stk;
	InitStack(&stk);
	PrintStack(&stk);
	cout << "是否为空栈：" << EmptyStack(&stk) << endl;
	Push(&stk, 4);
	Push(&stk, 5);
	Push(&stk, 6);
	PrintStack(&stk);
	Pop(&stk);
	PrintStack(&stk);
#endif

	LkStk ls;
	InitStack(&ls);
	Push(&ls, 5);
	Push(&ls, 6);
	Push(&ls, 7);
	Push(&ls, 8);
	Pop(&ls);

	PrintLStack(&ls);

	system("pause");
	return 0;
}