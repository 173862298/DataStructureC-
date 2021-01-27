#include "LinearL.h"
#include "SeqStack.h"
#include "Tree.h"
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

#if 0
	LkStk ls;
	InitStack(&ls);
	Push(&ls, 5);
	Push(&ls, 6);
	Push(&ls, 7);
	Push(&ls, 8);
	Pop(&ls);

	PrintLStack(&ls);
#endif
	
	//二叉树
	BNode node1 = { 'a',NULL,NULL };
	BNode node2 = { 'b',NULL,NULL };
	BNode node3 = { 'c',NULL,NULL };
	BNode node4 = { 'd',NULL,NULL };
	BNode node5 = { 'e',NULL,NULL };
	BNode node6 = { 'f',NULL,NULL };
	BNode node7 = { 'g',NULL,NULL };
	BNode node8 = { 'h',NULL,NULL };

	node1.lchild = &node2;
	node1.rchild = &node6;
	node2.rchild = &node3;
	node3.lchild = &node4;
	node3.rchild = &node5;
	node6.rchild = &node7;
	node7.lchild = &node8;

	//Preorder(&node1);
	//Midorder(&node1);
	Postorder(&node1);
	std::cout << std::endl;
	
	
	std::cout << GetHeight(&node1) << std::endl;

	system("pause");
	return 0;
}