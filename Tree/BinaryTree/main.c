#include "binTree.h"
/*
int main(){

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
	//deleteBinTree(tree);

}
*/

int main(void)
{
    BinTreeNode element;
    element.data = 'A';
    BinTree *pBinTree = makeBinTree(element); // A 삽입
    BinTreeNode* pParentNode = pBinTree->pRootNode; // 부모가 A
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // B 삽입
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // C 삽입
    pParentNode = pBinTree->pRootNode->pLeftChild; // 부모가 B
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // D 삽입
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // E 삽입
    pParentNode = pBinTree->pRootNode->pRightChild; // 부모가 C
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // F 삽입
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // G 삽입
    pParentNode = pBinTree->pRootNode->pLeftChild->pLeftChild; // 부모가 D
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // H 삽입
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // I 삽입
    pParentNode = pBinTree->pRootNode->pLeftChild->pRightChild; // 부모가 E
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // J 삽입
    pParentNode = pBinTree->pRootNode->pRightChild->pLeftChild;// 부모가 F
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // K 삽입
    pParentNode = pBinTree->pRootNode->pRightChild->pRightChild;// 부모가 G
    element.data++;
    insertLeftChildNodeBT(pParentNode, element); // L 삽입
    element.data++;
    insertRightChildNodeBT(pParentNode, element); // M 삽입

	
    SearchPreorder(pBinTree);
    printf("\n");
    SearchInorder(pBinTree);
    printf("\n");
    SearchPostorder(pBinTree);
    printf("\n");
	
	
	/*
	traversePreorder(pBinTree->pRootNode);
    printf("\n");
    traverseInorder(pBinTree->pRootNode);
    printf("\n");
    traversePostorder(pBinTree->pRootNode);
    printf("\n");
	*/

	deleteBinTree(pBinTree);
}