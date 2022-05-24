#include "binTree.h"

int main()
{
	BinTree *pBinTree;
	BinTreeNode node;
	BinTreeNode *tmp;

	node.data = 3;
	pBinTree = makeBinTree(node);
	for (int i = 1; i <= 5; i++)
	{
		node.data = i;
		insertBinaryTree(pBinTree, node);
	}

	printf("rootNode->data == %d\n", pBinTree->pRootNode->data);
	SearchInorder(pBinTree);
	printf("\n");
	node.data = pBinTree->pRootNode->data;
	deleteBinaryTree(pBinTree, node);
	printf("rootNode->data == %d\n", pBinTree->pRootNode->data);
	SearchInorder(pBinTree);
	printf("\n");
	// node.data++;
	// tmp = searchNodeBST(pBinTree->pRootNode, node);
	// printf("tmp == %p\ntmp.data == %d\n", tmp, tmp->data);
	
	/*
	BinTree *tree = NULL;
	BinTreeNode node;

	node.data = 'A';
	tree = makeBinTree(node);

	node.data = 'B';
	insertLeftChildNodeBT(tree->pRootNode, node);

	node.data = 'C';
	insertRightChildNodeBT(tree->pRootNode, node);

	node.data = 'D';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild, node);

	node.data = 'E';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild, node);

	node.data = 'F';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild, node);

	node.data = 'G';
	insertRightChildNodeBT(tree->pRootNode->pRightChild, node);

	node.data = 'H';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);

	node.data = 'I';
	insertRightChildNodeBT(tree->pRootNode->pLeftChild->pLeftChild, node);

	node.data = 'J';
	insertLeftChildNodeBT(tree->pRootNode->pLeftChild->pRightChild, node);

	node.data = 'K';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pLeftChild, node);

	node.data = 'L';
	insertLeftChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);

	node.data = 'M';
	insertRightChildNodeBT(tree->pRootNode->pRightChild->pRightChild, node);

	SearchPreorder(tree);
	SearchInorder(tree);
	SearchPostorder(tree);
	deleteBinTree(tree);
	*/
}
