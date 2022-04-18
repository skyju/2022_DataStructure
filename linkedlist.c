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
int addLLElement(LinkedList* list, int index, ListNode element) {
	ListNode* prev_Node; // 이전 노드 (index - 1)
	ListNode* new_Node; // 생성 노드

	if (list == NULL) {
		printf("[error : addLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount) {
		printf("[error : addLLElement] Invalid index.\n");
		return (FALSE);
	}
	new_Node = (ListNode*)malloc(sizeof(ListNode));
	if (!new_Node) {
		printf("[error : addLLElement] Memory allocation failed.\n");
		return (FALSE);
	}
		
	// 이전 노드 setting
	// index이 0인 경우 때문에 우선 헤더 노드 주소값을 넣어놓음
	prev_Node = &(list->head);
	for (int i = 0; i < index; i++) {
		prev_Node = prev_Node->next;
	}
	
	// 생성 노드 할당 및 새로운 연결해주기
	*new_Node = element;
	new_Node->next = prev_Node->next;
	prev_Node->next = new_Node;
	list->currentElementCount += 1;
	
	return (TRUE);
}

// 3. 원소 삭제 함수
int removeLLElement(LinkedList* list, int index) {
	ListNode* prev_Node; // 이전 노드 (index - 1)
	ListNode* del_Node; // 삭제할 노드

	if (list == NULL) {
		printf("[error : removeLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : removeLLElement] Invalid index.\n");
		return (FALSE);
	}
	
	// 노드 삭제 및 새로운 연결해주기
	prev_Node = &(list->head);
	if (index == 0) {
		list->head = *(prev_Node->next);
		free(prev_Node->next);
	} else {
		for (int i = 0 ; i < index; i++) {
			prev_Node = prev_Node->next;
		}
		del_Node = prev_Node->next;
		prev_Node->next = del_Node->next;
		free(del_Node);
	}
	list->currentElementCount -= 1;

	return (TRUE);
}

// 4. 연결 리스트에서 특정 인덱스의 원소를 가져오는 함수
ListNode* getLLElement(LinkedList* list, int index) {
	ListNode* result = NULL;

	if (list == NULL) {
		printf("[error : getLLElement] LinkedList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : getLLElement] Invalid index.\n");
		return (NULL);
	}
	
	result = &(list->head);
	for (int i = 0; i < index; i++) {
		result = result->next;
	}

	return (result);
}

// 5. 연결 리스트의 정보 출력 함수
void displayLinkedList(LinkedList* list) {
	ListNode* tmp = NULL;

	if (list == NULL) {
		printf("[error : displayLinkedList] LinkedList is Null.\n");
		return ;
	}

	printf("Current Element Count : %d\n", list->currentElementCount);
	printf("----[element display]----\n");
	tmp = &(list->head);
	for (int i = 0; i < list->currentElementCount; i++) {
		tmp = tmp->next;
		printf("[%d]'s element : %d\n", i, tmp->data);
	}
}

// 6. 연결 리스트 초기화 함수
void clearLinkedList(LinkedList* list) {
	if (list == NULL) {
		printf("[error : clearLinkedList] LinkedList is Null.\n");
		return ;
	}
	while (list->head.next) {
		ListNode *tmp = &(list->head);
		list->head = *(list->head.next);
		free(tmp->next);
	}
	list->currentElementCount = 0;
}

// 7. 연결 리스트의 길이를 리턴하는 함수
int getLinkedListLength(LinkedList* list) {
	if (list == NULL) {
		printf("[error : getLinkedListLength] LinkedList is Null.\n");
		return (FALSE);
	}
	return (list->currentElementCount);
}

// 8. 연결 리스트 삭제 함수
void deleteLinkedList(LinkedList** list) {
	if (list == NULL) {
		printf("[error : deleteLinkedList] LinkedList is Null.\n");
		return ;
	}
	free(*list);
	*list = NULL;
}