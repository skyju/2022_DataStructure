#include "binTree.h"

// 이진 탐색을 위해서는 정렬이 되어있어야 함
// 따라서 정렬되어있음을 가정한다.
BinTreeNode *recursive_binSearch(BinTreeNode *node, BinTreeNode element)
{
	if (node->data < element.data)
	{ // 값이 첫 노드 값보다 크면, 오른쪽만 보면됨
		if (node->pRightChild == NULL)
			return (NULL);
		return (recursive_binSearch(node->pRightChild, element));
	}
	else if (node->data > element.data)
	{
		if (node->pLeftChild->data > element.data)
			return (NULL);
		return (recursive_binSearch(node->pLeftChild, element));
	}
	else
	{
		return (node);
	}
}

BinTreeNode *searchBinaryTree(BinTree *binTree, BinTreeNode element)
{
	if (!binTree || !(binTree->pRootNode))
	{
		printf("[error] Tree is Null.\n");
		return (NULL);
	}
	return (recursive_binSearch(binTree->pRootNode, element));
}

BinTreeNode *recursive_binInsert(BinTreeNode *node, BinTreeNode element)
{
	if (element.data < node->data)
	{
		if (node->pLeftChild == NULL)
			node = insertLeftChildNodeBT(node, element);
		else
			node = recursive_binInsert(node->pLeftChild, element);
	}
	else if (element.data > node->data)
	{
		if (node->pRightChild == NULL)
			node = insertRightChildNodeBT(node, element);
		else
			node = recursive_binInsert(node->pRightChild, element);
	}
	return (node);
}

int insertBinaryTree(BinTree *binTree, BinTreeNode element)
{
	if (!binTree || !(binTree->pRootNode))
	{
		printf("[error] Tree is Null.\n");
		return (FALSE);
	}
	if (searchBinaryTree(binTree, element) != NULL)
	{
		printf("[error] The element already exists.\n");
		return (FALSE);
	}
	if (recursive_binInsert(binTree->pRootNode, element) == NULL)
	{
		printf("[error] Insert Failed.\n");
		return (FALSE);
	}
	return (TRUE);
}

int deleteBinaryTree(BinTree *binTree, BinTreeNode element)
{
	if (!binTree || !(binTree->pRootNode))
	{
		printf("[error] Tree is Null.\n");
		return (FALSE);
	}
	BinTreeNode *parent;
	BinTreeNode *node;

	node = searchBinaryTree(binTree, element);
	parent = getParentNodeBT(binTree->pRootNode, element);
	if (node == NULL)
	{
		printf("[error] Node not found.\n");
		return (FALSE);
	}
	// 1. 자식이 없는 노드
	if (!(node->pLeftChild) && !(node->pRightChild))
	{
		if ((parent->pLeftChild)->data == node->data)
			parent->pLeftChild = NULL;
		else
			parent->pRightChild = NULL;
		free(node);
	}
	// 2. 왼쪽 자식만 있는 경우
	else if (node->pLeftChild != NULL && node->pRightChild == NULL)
	{
		if (parent->pLeftChild->data == node->data)
			parent->pLeftChild = node->pLeftChild;
		else
			parent->pRightChild = node->pLeftChild;
		free(node);
	}
	// 3. 오른쪽 자식만 있는 경우
	else if (node->pLeftChild == NULL && node->pRightChild != NULL)
	{
		if (parent->pLeftChild->data == node->data)
			parent->pLeftChild = node->pRightChild;
		else
			parent->pRightChild = node->pRightChild;
		free(node);
	}
	// 4. 모두 있는 경우
	else
	{
		if (node->pRightChild->pLeftChild == NULL) //다음 값의 왼쪽 노드가 없으면
		{
			node->data = node->pRightChild->data; //삭제할 노드에 다음값 복사
			if (node->pRightChild->pRightChild != NULL)
				node->pRightChild = node->pRightChild->pRightChild;
			else
				node->pRightChild = NULL;
		}
		else
		{
			BinTreeNode* tmp = node->pRightChild;
			BinTreeNode *tmp_parent;
			while (tmp->pLeftChild) // 가장 깊은 왼쪽이 다음 값
				tmp = tmp->pLeftChild;
			node->data = tmp->data;
			tmp_parent = getParentNodeBT(binTree->pRootNode, *tmp);
			if (tmp->pRightChild)
				tmp_parent->pLeftChild = tmp->pRightChild;
			else
				tmp_parent->pLeftChild = NULL;
		}
		free(node->pLeftChild);
	}
	return (TRUE);
}
