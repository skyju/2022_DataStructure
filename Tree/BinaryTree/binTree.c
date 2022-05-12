#include "binTree.h"

BinTree* makeBinTree(BinTreeNode rootNode)
{
	BinTree* tree;
	tree = (BinTree *)malloc(sizeof(BinTree));
	if (!tree)
	{
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	BinTreeNode *node;
	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node) {
		printf("[error] Memory allocate failed.\n");
		free(tree);
		return (NULL);
	}
	*node = rootNode;
	tree->pRootNode = node;
	tree->pRootNode->pLeftChild = NULL;
	tree->pRootNode->pRightChild = NULL;
	return (tree);
}

BinTreeNode* getRootNodeBT(BinTree* pBinTree)
{
	if (!pBinTree) {
		printf("[error] Binary Tree is Null.\n");
		return (NULL);
	}
	return (pBinTree->pRootNode);
}

BinTreeNode* insertLeftChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode) {
		printf("[error] Parent Node is Null.\n");
		return (NULL);
	}
	BinTreeNode *node;
	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node) {
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	pParentNode->pLeftChild = node;
	return (node);
}

BinTreeNode* insertRightChildNodeBT(BinTreeNode* pParentNode, BinTreeNode element)
{
	if (!pParentNode) {
		printf("[error] Parent Node is Null.\n");
		return (NULL);
	}
	BinTreeNode *node;
	node = (BinTreeNode *)malloc(sizeof(BinTreeNode));
	if (!node) {
		printf("[error] Memory allocate failed.\n");
		return (NULL);
	}
	node->data = element.data;
	node->pLeftChild = NULL;
	node->pRightChild = NULL;
	pParentNode->pRightChild = node;
	return (node);
}

BinTreeNode* getLeftChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode) {
		printf("[error] Node is Null.\n");
		return (NULL);
	}
	return (pNode->pLeftChild);
}

BinTreeNode* getRightChildNodeBT(BinTreeNode* pNode)
{
	if (!pNode) {
		printf("[error] Node is Null.\n");
		return (NULL);
	}
	return (pNode->pRightChild);
}

void deleteBinTree(BinTree* pBinTree)
{
	if (!pBinTree) {
		printf("[error] Binary Tree is Null.\n");
		return;
	}
	deleteBinTreeNode(pBinTree->pRootNode);
}

void deleteBinTreeNode(BinTreeNode* pNode)
{
	if (!pNode)
		return;
	deleteBinTreeNode(pNode->pLeftChild);
	deleteBinTreeNode(pNode->pRightChild);
	free(pNode);
	pNode = NULL;
}