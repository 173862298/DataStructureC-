#pragma once
#include <iostream>


/*��������  ������ */
typedef struct binarynode
{
	char data;
	struct binarynode *lchild, *rchild;
}BNode;
int iLeafNums = 0;


void Preorder(BNode *root)
{
	//�������
	if (root == NULL)
	{
		return;
	}
	std::cout << root->data ;
	Preorder(root->lchild);
	Preorder(root->rchild);
}

void Midorder(BNode *root)
{
	//�������
	if (root == NULL)
	{
		return;
	}
	Midorder(root->lchild);
	std::cout << root->data ;
	Midorder(root->rchild);
}

void Postorder(BNode *root)
{
	//�������
	if (root == NULL)
	{
		return;
	}
	Postorder(root->lchild);
	Postorder(root->rchild);
	std::cout << root->data ;
}

void GetLeafNum(BNode *root)
{
	//��ȡ����Ҷ�ӽ�����Ŀ	
	if (root == NULL)
	{
		return ;
	}
	if (root->lchild == NULL&& root->rchild == NULL)
	{
		iLeafNums += 1;
	}
	GetLeafNum(root->lchild);
	GetLeafNum(root->rchild);
	
}
int GetHeight(BNode *root)
{
	//��ȡ�������  
	int iHeight = 0;
	if (root != NULL)
	{
		iHeight += 1;
		int isum = GetHeight(root->lchild);
		int isum2 = GetHeight(root->rchild);
		if (isum > isum2)
		{
			iHeight += isum;
		}
		else
		{
			iHeight += isum2;
		}
	}
		
	return iHeight;
}


