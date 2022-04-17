#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"

int main(void) {
	ArrayList *pList = NULL;

	// 총 9개의 함수 TEST 진행

	// 1. 배열 리스트 생성
	pList = createArrayList(6);

	if (pList) {
		printf("----------------\n");
		printf("배열 리스트 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		ArrayListNode node;

		// 2. 원소 추가 진행
		node.data = 10000;
		addALElement(pList, 0, node);
		node.data = 23451234;
		addALElement(pList, 1, node);
		node.data = -232;
		addALElement(pList, 2, node);
		node.data = 234;
		addALElement(pList, 3, node);
		printf("----------------\n");
		printf("원소 4개 추가\n");
		printf("----------------\n");
		printf("\n\n");

		// 5. 정보 출력
		displayArrayList(pList);
		printf("\n\n");

		// 3. 원소 삭제 진행
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeALElement(pList, 0);
		printf("\n\n");

		// 5. 정보 출력
		displayArrayList(pList);
		printf("\n\n");

		// 4. 특정 인덱스 원소 가져와서 출력해보기
		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 0, getALElement(pList, 0)->data);
		printf("----------------\n");
		printf("\n\n");

		// 6. 배열 리스트가 찼는지 확인
		if (isArrayListFull(pList)) {
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
		addALElement(pList, 3, node);
		node.data = 1111;
		addALElement(pList, 4, node);
		node.data = -9999;
		addALElement(pList, 5, node);
		displayArrayList(pList);
		printf("\n\n");

		if (isArrayListFull(pList)) {
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
		removeALElement(pList, 0);
		displayArrayList(pList);
		printf("\n\n");

		// 8. 현재 배열 리스트의 길이 확인
		printf("----------------\n");
		printf("현재 배열리스트의 길이? : %d\n", getArrayListLength(pList));
		printf("----------------\n");
		printf("\n\n");

		// 7. 배열 리스트 초기화 진행
		printf("----------------\n");
		printf("배열 리스트 초기화 진행\n");
		printf("----------------\n");
		clearArrayList(pList);
		displayArrayList(pList);
		printf("\n\n");

		// 9. 배열 리스트 삭제 진행
		printf("----------------\n");
		printf("배열 리스트 삭제 진행\n");
		printf("----------------\n");
		deleteArrayList(&pList);
		if (pList) {
			printf("배열 리스트 삭제 안됐음!\n");
		} else {
			printf("배열 리스트 삭제 완료!\n");
		}
	}
}