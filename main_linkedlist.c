#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	LinkedList *pList = NULL;

	// 총 8개의 함수 TEST 진행

	// 1. 연결 리스트 생성
	pList = createLinkedList();

	printf("%d\n\n", pList->headerNode.data);

	if (pList) {
		printf("----------------\n");
		printf("연결 리스트 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		ListNode node;

		// 2. 원소 추가 진행
		node.data = 10000;
		addLLElement(pList, 0, node);
		node.data = 23451234;
		addLLElement(pList, 1, node);
		node.data = -232;
		addLLElement(pList, 2, node);
		node.data = 234;
		addLLElement(pList, 3, node);
		printf("----------------\n");
		printf("원소 4개 추가\n");
		printf("----------------\n");
		printf("\n\n");

		// 5. 정보 출력
		displayLinkedList(pList);
		printf("\n\n");

		// 3. 원소 삭제 진행
		printf("----------------\n");
		printf("1번째 원소 삭제!\n");
		printf("----------------\n");
		removeLLElement(pList, 1);
		printf("\n\n");

		// 5. 정보 출력
		displayLinkedList(pList);
		printf("\n\n");

		// 4. 특정 인덱스 원소 가져와서 출력해보기
		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 2, getLLElement(pList, 2)->data);
		printf("----------------\n");
		printf("\n\n");

		// 원소 하나 더 삭제
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeLLElement(pList, 0);
		displayLinkedList(pList);
		printf("\n\n");

		// 8. 현재 연결 리스트의 길이 확인
		printf("----------------\n");
		printf("현재 연결리스트의 길이? : %d\n", getLinkedListLength(pList));
		printf("----------------\n");
		printf("\n\n");

		// 7. 연결 리스트 초기화 진행
		printf("----------------\n");
		printf("연결 리스트 초기화 진행\n");
		printf("----------------\n");
		clearLinkedList(pList);
		displayLinkedList(pList);
		printf("\n\n");

		// 9. 연결 리스트 삭제 진행
		printf("----------------\n");
		printf("연결 리스트 삭제 진행\n");
		printf("----------------\n");
		deleteLinkedList(&pList);
		if (pList) {
			printf("연결 리스트 삭제 안됐음!\n");
		} else {
			printf("연결 리스트 삭제 완료!\n");
		}
	}
}