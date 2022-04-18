#include "linkedlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	LinkedList *list = NULL;

	// 총 8개의 함수 TEST 진행

	// 1. 연결 리스트 생성
	list = createLinkedList();

	if (list) {
		printf("----------------\n");
		printf("연결 리스트 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		ListNode node;

		// 2. 원소 추가 진행
		node.data = 10000;
		addLLElement(list, 0, node);
		node.data = 23451234;
		addLLElement(list, 1, node);
		node.data = -232;
		addLLElement(list, 2, node);
		node.data = 234;
		addLLElement(list, 3, node);
		node.data = 425933;
		addLLElement(list, 4, node);
		node.data = 121;
		addLLElement(list, 5, node);
		printf("----------------\n");
		printf("원소 6개 추가\n");
		printf("----------------\n");
		printf("\n\n");

		// 5. 정보 출력
		displayLinkedList(list);
		printf("\n\n");

		// 3. 원소 삭제 진행
		printf("----------------\n");
		printf("1 INDEX 원소 삭제!\n");
		printf("----------------\n");
		removeLLElement(list, 1);
		printf("\n\n");

		// 5. 정보 출력
		displayLinkedList(list);
		printf("\n\n");

		printf("----------------\n");
		printf("2 INDEX 원소 삭제!\n");
		printf("----------------\n");
		removeLLElement(list, 2);
		// 5. 정보 출력
		displayLinkedList(list);
		printf("\n\n");

		// 4. 특정 인덱스 원소 가져와서 출력해보기
		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 2, getLLElement(list, 2)->data);
		printf("----------------\n");
		printf("\n\n");

		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 0, getLLElement(list, 0)->data);
		printf("----------------\n");
		printf("\n\n");

		// 원소 하나 더 삭제
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeLLElement(list, 0);
		displayLinkedList(list);
		printf("\n\n");

		// 원소 대체
		printf("----------------\n");
		printf("0번째 원소 대체!\n");
		printf("----------------\n");
		node.data=22;
		replaceLLElement(list, 0, node);
		displayLinkedList(list);
		printf("\n\n");

		// 8. 현재 연결 리스트의 길이 확인
		printf("----------------\n");
		printf("현재 연결리스트의 길이? : %d\n", getLinkedListLength(list));
		printf("----------------\n");
		printf("\n\n");

		// 7. 연결 리스트 초기화 진행
		printf("----------------\n");
		printf("연결 리스트 초기화 진행\n");
		printf("----------------\n");
		clearLinkedList(list);
		displayLinkedList(list);
		printf("\n\n");

		// 9. 연결 리스트 삭제 진행
		printf("----------------\n");
		printf("연결 리스트 삭제 진행\n");
		printf("----------------\n");
		deleteLinkedList(&list);
		if (list) {
			printf("연결 리스트 삭제 안됐음!\n");
		} else {
			printf("연결 리스트 삭제 완료!\n");
		}
	}
}