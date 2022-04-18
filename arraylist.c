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
	result = (ArrayList*)malloc(sizeof(ArrayList *));
	if (!result) {
		printf("[error : createArrayList] Memory allocation failed.\n");
		return (NULL);
	}

	// 초기화 진행
	result->maxElementCount = maxElementCount;
	result->currentElementCount = 0;
	result->array = (ArrayListNode *)malloc(sizeof(ArrayListNode *) * maxElementCount);
	if (!result->array) {
		free(result);
		printf("[error : createArrayList] Memory allocation failed.\n");
		return (NULL);
	}

	//배열 만들고 0으로 초기화 (garbage값 오류 문제 해결을 위해)
	memset(result->array, 0, sizeof(ArrayListNode *) * maxElementCount);
	
	return (result);
}

// 추가: 원소 대체 함수
int replaceALElement(ArrayList* list, int index, ArrayListNode element)
{
	if (list == NULL) {
		printf("[error : replaceALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : replaceALElement] Invalid index.\n");
		return (FALSE);
	}
	list->array[index] = element;

	return (TRUE);
}

// 2. 원소 추가 함수
// 주의 할 점: 이어져야 한다는 특징 때문에 기존 원소의 이동이 필요하다는 점 유의하여 구현
int addALElement(ArrayList* list, int index, ArrayListNode element) {
	if (list == NULL) {
		printf("[error : addALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (isArrayListFull(list)) {
		printf("[error : addALElement] Exceeds array size.\n");
		return (FALSE);
	}
	if (index < 0 || index > list->currentElementCount) {
		printf("[error : addALElement] Invalid index.\n");
		return (FALSE);
	}

	//shift
	for (int i = list->currentElementCount - 1; i >= index; i--) {
		list->array[i + 1] = list->array[i];
	}
	list->array[index] = element;
	list->currentElementCount += 1;

	return (TRUE);
}

// 3. 원소 삭제 함수
int removeALElement(ArrayList* list, int index) {
	if (list == NULL) {
		printf("[error : removeALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : removeALElement] Invalid index.\n");
		return (FALSE);
	}

	//shift
	for (int i = index; i < list->currentElementCount; i++) {
		list->array[i] = list->array[i + 1];
	}
	list->currentElementCount -= 1;
	
	return (TRUE);
}

// 4. 배열 리스트에서 특정 인덱스의 원소를 가져오는 함수
ArrayListNode* getALElement(ArrayList* list, int index) {
	ArrayListNode* result = NULL;

	if (list == NULL) {
		printf("[error : getALElement] ArrayList is Null.\n");
		return (FALSE);
	}
	if (index < 0 || index >= list->currentElementCount) {
		printf("[error : getALElement] Invalid index.\n");
		return (NULL);
	}
	
	result = &(list->array[index]);
	return (result);
}

// 5. 배열 리스트의 정보 출력 함수
void displayArrayList(ArrayList* list) {
	if (list == NULL) {
		printf("[error : displayArrayList] ArrayList is Null.\n");
		return ;
	}
	printf("Max Element size : %d\n", list->maxElementCount);
	printf("Current Element Count : %d\n", list->currentElementCount);
	printf("----[element display]----\n");
	for (int i = 0; i < list->currentElementCount; i++) {
		printf("[%d]'s element : %d\n", i, getALElement(list, i)->data);
	}
}

// 6. 배열 리스트가 찼는지 확인하는 함수
int isArrayListFull(ArrayList* list) {
	if (list == NULL) {
		printf("[error : isArrayListFull] ArrayList is Null.\n");
		return (FALSE);
	}
	if (list->currentElementCount == list->maxElementCount) {
		return (TRUE);
	}
	return (FALSE);
}

// 7. 배열 리스트 초기화 함수
void clearArrayList(ArrayList* list) {
	if (list == NULL) {
		printf("[error : clearArrayList] ArrayList is Null.\n");
		return ;
	}
	memset(list->array, 0, sizeof(ArrayListNode *) * list->currentElementCount);
	list->currentElementCount = 0; 
}

// 8. 배열 리스트의 길이를 리턴하는 함수
int getArrayListLength(ArrayList* list) {
	if (list == NULL) {
		printf("[error : getArrayListLength] ArrayList is Null.\n");
		return (FALSE);
	}
	return (list->currentElementCount);
}

// 9. 배열 리스트 삭제 함수
void deleteArrayList(ArrayList** list) {
	if (list == NULL) {
		printf("[error : deleteArrayList] ArrayList is Null.\n");
		return ;
	}
	free((*list)->array);
	free(*list);
	*list = NULL;
}
