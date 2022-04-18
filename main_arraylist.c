#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main(void) {
	ArrayList *list = NULL;

	// 총 9개의 함수 TEST 진행

	// 1. 배열 리스트 생성
	list = createArrayList(6);

	if (list) {
		printf("----------------\n");
		printf("배열 리스트 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		ArrayListNode node;

		// 2. 원소 추가 진행
		node.data = 10000;
		addALElement(list, 0, node);
		node.data = 23451234;
		addALElement(list, 1, node);
		node.data = -232;
		addALElement(list, 2, node);
		node.data = 234;
		addALElement(list, 3, node);
		node.data = 425933;
		addALElement(list, 4, node);
		node.data = 121;
		addALElement(list, 5, node);
		printf("----------------\n");
		printf("원소 6개 추가\n");
		printf("----------------\n");
		printf("\n\n");

		printf("invalid index error 발생시키기\n");
		node.data = 111;
		addALElement(list, 7, node);

		// 5. 정보 출력
		displayArrayList(list);
		printf("\n\n");

		// 3. 원소 삭제 진행
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeALElement(list, 0);
		
		// 5. 정보 출력
		displayArrayList(list);
		printf("\n\n");
		
		printf("2번째 원소 삭제!\n");
		removeALElement(list, 2);
		printf("\n\n");

		// 5. 정보 출력
		displayArrayList(list);
		printf("\n\n");

		// 4. 특정 인덱스 원소 가져와서 출력해보기
		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 0, getALElement(list, 0)->data);
		printf("----------------\n");
		printf("\n\n");

		// 6. 배열 리스트가 찼는지 확인
		if (isArrayListFull(list)) {
			printf("----------------\n");
			printf("배열 리스트가 꽉 찼습니다!\n");
			printf("----------------\n");
			printf("\n\n");
		} else {
			printf("----------------\n");
			printf("아직 배열 리스트가 다 차지 않았습니다.\n");
			printf("----------------\n");
			printf("\n\n");
		}
		
		// 꽉 채우고 다시 test
		printf("----------------\n");
		printf("원소 3개 추가\n");
		printf("----------------\n");
		node.data = 1;
		addALElement(list, 3, node);
		node.data = 1111;
		addALElement(list, 4, node);
		node.data = -9999;
		addALElement(list, 5, node);
		displayArrayList(list);
		printf("\n\n");

		if (isArrayListFull(list)) {
			printf("----------------\n");
			printf("배열 리스트가 꽉 찼습니다!\n");
			printf("----------------\n");
			printf("\n\n");
		} else {
			printf("----------------\n");
			printf("아직 배열 리스트가 다 차지 않았습니다.\n");
			printf("----------------\n");
			printf("\n\n");
		}

		// 원소 하나 삭제
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeALElement(list, 0);
		displayArrayList(list);
		printf("\n\n");

		// 8. 현재 배열 리스트의 길이 확인
		printf("----------------\n");
		printf("현재 배열리스트의 길이? : %d\n", getArrayListLength(list));
		printf("----------------\n");
		printf("\n\n");

		// 7. 배열 리스트 초기화 진행
		printf("----------------\n");
		printf("배열 리스트 초기화 진행\n");
		printf("----------------\n");
		clearArrayList(list);
		displayArrayList(list);
		printf("\n\n");

		// 9. 배열 리스트 삭제 진행
		printf("----------------\n");
		printf("배열 리스트 삭제 진행\n");
		printf("----------------\n");
		deleteArrayList(&list);
		if (list) {
			printf("배열 리스트 삭제 안됐음!\n");
		} else {
			printf("배열 리스트 삭제 완료!\n");
		}
	}
}