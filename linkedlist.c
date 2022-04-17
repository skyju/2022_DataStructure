#include "linkedlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 1. 연결 리스트 생성 함수
LinkedList* createLinkedList() {
	LinkedList *result = NULL;

	result = (LinkedList *)malloc(sizeof(LinkedList));
	if (!result) {
		printf("[error : createLinkedList] Memory allocation failed.\n");
		return (NULL);
	}

	//초기화 진행
	result->currentElementCount = 0;
	//0으로 초기화 (garbage값 오류 문제 해결을 위해)
	memset(result, 0, sizeof(LinkedList));
	
	return (result);
}

// 2. 원소 추가 함수
// 이전노드와 해당 인덱스 사이의 연결을 끊고 새로운 노드를 사이에 끼워야함!
int addLLElement(LinkedList* pList, int position, ListNode element) {
	ListNode* prev_Node; // 이전 노드 (position - 1)
	ListNode* new_Node; // 생성 노드

	if (pList == NULL) {
		printf("[error : addLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (position < 0 || position > pList->currentElementCount) {
		printf("[error : addLLElement] Invalid position.\n");
		return (FALSE);
	}
	new_Node = (ListNode*)malloc(sizeof(ListNode));
	if (!new_Node) {
		printf("[error : addLLElement] Memory allocation failed.\n");
		return (FALSE);
	}
		
	// 이전 노드 setting
	// position이 0인 경우 때문에 우선 헤더 노드 주소값을 넣어놓음
	prev_Node = &(pList->headerNode);
	for (int i = 0; i < position; i++) {
		prev_Node = prev_Node->pLink;
	}
	
	// 생성 노드 할당 및 새로운 연결해주기
	*new_Node = element;
	new_Node->pLink = prev_Node->pLink;
	prev_Node->pLink = new_Node;
	pList->currentElementCount += 1;
	
	return (TRUE);
}

// 3. 원소 삭제 함수
int removeLLElement(LinkedList* pList, int position) {
	ListNode* prev_Node; // 이전 노드 (position - 1)
	ListNode* del_Node; // 삭제할 노드

	if (pList == NULL) {
		printf("[error : removeLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (position < 0 || position >= pList->currentElementCount) {
		printf("[error : removeLLElement] Invalid position.\n");
		return (FALSE);
	}
	
	// 노드 삭제 및 새로운 연결해주기
	prev_Node = &(pList->headerNode);
	if (position == 0) {
		pList->headerNode = *(prev_Node->pLink);
		free(prev_Node->pLink);
	} else {
		for (int i = 0 ; i < position - 1; i++) {
			prev_Node = prev_Node->pLink;
		}
		del_Node = prev_Node->pLink;
		prev_Node->pLink = del_Node->pLink;
		free(del_Node);
	}
	pList->currentElementCount -= 1;
	
	return (TRUE);
}

// 4. 연결 리스트에서 특정 인덱스의 원소를 가져오는 함수
ListNode* getLLElement(LinkedList* pList, int position) {
	ListNode* result = NULL;

	if (pList == NULL) {
		printf("[error : getLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (position < 0 || position >= pList->currentElementCount) {
		printf("[error : getLLElement] Invalid position.\n");
		return (NULL);
	}
	
	result = &(pList->headerNode);
	for (int i = 0; i < position; i++) {
		result = result->pLink;
	}

	return (result);
}

// 5. 연결 리스트의 정보 출력 함수
void displayLinkedList(LinkedList* pList) {
	if (pList == NULL) {
		printf("[error : displayLinkedList] LinkedList is Null.\n");
		return ;
	}
	printf("Current Element Count : %d\n", pList->currentElementCount);
	printf("----[element display]----\n");
	for (int i = 0; i < pList->currentElementCount; i++) {
		printf("[%d]'s element : %d\n", i, getLLElement(pList, i)->data);
	}
}

// 6. 연결 리스트 초기화 함수
void clearLinkedList(LinkedList* pList) {
	if (pList == NULL) {
		printf("[error : clearLinkedList] LinkedList is Null.\n");
		return ;
	}
	while (pList->headerNode.pLink) {
		ListNode *tmp = &(pList->headerNode);
		pList->headerNode = *(pList->headerNode.pLink);
		free(tmp->pLink);
	}
	pList->currentElementCount = 0;
}

// 7. 연결 리스트의 길이를 리턴하는 함수
int getLinkedListLength(LinkedList* pList) {
	if (pList == NULL) {
		printf("[error : getLinkedListLength] LinkedList is Null.\n");
		return (FALSE);
	}
	return (pList->currentElementCount);
}

// 8. 연결 리스트 삭제 함수
void deleteLinkedList(LinkedList** pList) {
	if (pList == NULL) {
		printf("[error : deleteLinkedList] LinkedList is Null.\n");
		return ;
	}
	free(*pList);
	*pList = NULL;
}