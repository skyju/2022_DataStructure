#include "binTree.h"

// 1. 전위 순회
void SearchPreorder(BinTree* pBinTree)
{
	printf("==== pre order =====\n");
	PreOrderRecursive(pBinTree->pRootNode);
	printf("\n");
}
void PreOrderRecursive(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return;
	printf("%c ", pNode->data);
	PreOrderRecursive(pNode->pLeftChild);
	PreOrderRecursive(pNode->pRightChild);
}

// 2. 중위 순회
void SearchInorder(BinTree* pBinTree)
{
	printf("==== in order =====\n");
	InOrderRecursive(pBinTree->pRootNode);
	printf("\n");
}
void InOrderRecursive(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return;
	InOrderRecursive(pNode->pLeftChild);
	printf("%c ", pNode->data);
	InOrderRecursive(pNode->pRightChild);
}

// 3. 후위 순회
void SearchPostorder(BinTree* pBinTree)
{
	printf("==== post order =====\n");
	PostOrderRecursive(pBinTree->pRootNode);
	printf("\n");
}
void PostOrderRecursive(BinTreeNode* pNode)
{
	if (pNode == NULL)
		return;
	PostOrderRecursive(pNode->pLeftChild);
	PostOrderRecursive(pNode->pRightChild);
	printf("%c ", pNode->data);
}