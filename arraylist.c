#include "arraylist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// 1. 배열 리스트 생성 함수
ArrayList* createArrayList(int maxElementCount) {
	ArrayList *result = NULL;

	if (maxElementCount <= 0) {
		printf("[error : createArrayList] Invalid size.\n");
		return (NULL);
	}
	result = (ArrayList*)malloc(sizeof(ArrayList*));
	if (!result) {
		printf("[error : createArrayList] Memory allocation failed.\n");
		return (NULL);
	}

	// 초기화 진행
	result->maxElementCount = maxElementCount;
	result->currentElementCount = 0;
	result->pElement = (ArrayListNode *)malloc(sizeof(ArrayListNode) * maxElementCount);
	if (!result->pElement) {
		free(result);
		printf("[error : createArrayList] Memory allocation failed.\n");
		return (NULL);
	}

	//배열 만들고 0으로 초기화 (garbage값 오류 문제 해결을 위해)
	memset(result->pElement, 0, sizeof(ArrayListNode) * maxElementCount);
	
	return (result);
}

// 2. 원소 추가 함수
// 주의 할 점: 이어져야 한다는 특징 때문에 기존 원소의 이동이 필요하다는 점 유의하여 구현
int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	if (pList == NULL) {
		printf("[error : addALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (isArrayListFull(pList)) {
		printf("[error : addALElement] Exceeds array size.\n");
		return (FALSE);
	}
	if (position < 0 || position > pList->currentElementCount) {
		printf("[error : addALElement] Invalid position.\n");
		return (FALSE);
	}

	//shift
	for (int i = pList->currentElementCount - 1; i >= position; i--) {
		pList->pElement[i + 1] = pList->pElement[i];
	}
	pList->pElement[position] = element;
	pList->currentElementCount += 1;

	return (TRUE);
}

// 3. 원소 삭제 함수
int removeALElement(ArrayList* pList, int position) {
	if (pList == NULL) {
		printf("[error : removeALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (position < 0 || position >= pList->currentElementCount) {
		printf("[error : removeALElement] Invalid position.\n");
		return (FALSE);
	}

	//shift
	for (int i = position; i < pList->currentElementCount; i++) {
		pList->pElement[i] = pList->pElement[i + 1];
	}
	pList->currentElementCount -= 1;
	
	return (TRUE);
}

// 4. 배열 리스트에서 특정 인덱스의 원소를 가져오는 함수
ArrayListNode* getALElement(ArrayList* pList, int position) {
	ArrayListNode* result = NULL;

	if (pList == NULL) {
		printf("[error : getALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (position < 0 || position >= pList->currentElementCount) {
		printf("[error : getALElement] Invalid position.\n");
		return (NULL);
	}
	
	result = &(pList->pElement[position]);
	return (result);
}

// 5. 배열 리스트의 정보 출력 함수
void displayArrayList(ArrayList* pList) {
	if (pList == NULL) {
		printf("[error : displayArrayList] ArrayList is Null.\n");
		return ;
	}
	printf("Max Element size : %d\n", pList->maxElementCount);
	printf("Current Element Count : %d\n", pList->currentElementCount);
	printf("----[element display]----\n");
	for (int i = 0; i < pList->currentElementCount; i++) {
		printf("[%d]'s element : %d\n", i, getALElement(pList, i)->data);
	}
}

// 6. 배열 리스트가 찼는지 확인하는 함수
int isArrayListFull(ArrayList* pList) {
	if (pList == NULL) {
		printf("[error : isArrayListFull] ArrayList is Null.\n");
		return (FALSE);
	}
	if (pList->currentElementCount == pList->maxElementCount) {
		return (TRUE);
	}
	return (FALSE);
}

// 7. 배열 리스트 초기화 함수
void clearArrayList(ArrayList* pList) {
	if (pList == NULL) {
		printf("[error : clearArrayList] ArrayList is Null.\n");
		return ;
	}
	memset(pList->pElement, 0, sizeof(ArrayListNode) * pList->currentElementCount);
	pList->currentElementCount = 0; 
}

// 8. 배열 리스트의 길이를 리턴하는 함수
int getArrayListLength(ArrayList* pList) {
	if (pList == NULL) {
		printf("[error : getArrayListLength] ArrayList is Null.\n");
		return (FALSE);
	}
	return (pList->currentElementCount);
}

// 9. 배열 리스트 삭제 함수
void deleteArrayList(ArrayList** pList) {
	if (pList == NULL) {
		printf("[error : deleteArrayList] ArrayList is Null.\n");
		return ;
	}
	free((*pList)->pElement);
	free(*pList);
	*pList = NULL;
}