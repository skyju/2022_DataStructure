#include "circularList.h"
#include "circularList.c"

int main(void) {
	CircularList *list = NULL;

	// 원형 리스트 생성
	list = createCircularList();

	if (list) {
		printf("----------------\n");
		printf("원형 리스트 생성완료!\n");
		printf("----------------\n");
		printf("\n\n");

		CircularListNode node;

		// 2. 원소 추가 진행
		node.data = 10000;
		addCLElement(list, 0, node);
		node.data = 23451234;
		addCLElement(list, 1, node);
		node.data = -232;
		addCLElement(list, 2, node);
		node.data = 234;
		addCLElement(list, 3, node);
		node.data = 425933;
		addCLElement(list, 4, node);
		node.data = 121;
		addCLElement(list, 5, node);
		printf("----------------\n");
		printf("원소 6개 추가\n");
		printf("----------------\n");
		printf("\n\n");

		printf("invalid index error 발생시키기\n");
		node.data = 111;
		addCLElement(list, 7, node);

		displayCircularList(list);
		printf("\n\n");

		// 3. 원소 삭제 진행
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeCLElement(list, 0);
		displayCircularList(list);
		printf("\n\n");
		
		printf("----------------\n");
		printf("2번째 원소 삭제!\n");
		printf("----------------\n");
		removeCLElement(list, 2);
		displayCircularList(list);
		printf("\n\n");

		printf("----------------\n");
		printf("1번째 원소 1로 대체!\n");
		printf("----------------\n");
		node.data = 1;
		replaceCLElement(list, 1, node);
		displayCircularList(list);
		printf("\n\n");
		

		// 4. 특정 인덱스 원소 가져와서 출력해보기
		printf("----------------\n");
		printf("%d번째 원소 확인: %d\n", 0, getCLElement(list, 0)->data);
		printf("----------------\n");
		printf("\n\n");
		
		printf("----------------\n");
		printf("원소 3개 추가\n");
		printf("3번에 1 넣은 후\n");
		printf("4번에 1111넣은 후\n");
		printf("5번에 -9999추가\n");
		printf("----------------\n");
		node.data = 1;
		addCLElement(list, 3, node);
		node.data = 1111;
		addCLElement(list, 4, node);
		node.data = -9999;
		addCLElement(list, 5, node);
		displayCircularList(list);
		printf("\n\n");

		// 원소 하나 삭제
		printf("----------------\n");
		printf("0번째 원소 삭제!\n");
		printf("----------------\n");
		removeCLElement(list, 0);
		displayCircularList(list);
		printf("\n\n");

		printf("----------------\n");
		printf("현재 리스트의 길이? : %d\n", getCircularListLength(list));
		printf("----------------\n");
		printf("\n\n");

		printf("----------------\n");
		printf("리스트 초기화 진행\n");
		printf("----------------\n");
		clearCircularList(list);
		displayCircularList(list);
		printf("\n\n");

		printf("----------------\n"); 
		printf("원형 리스트 삭제 진행\n");
		printf("----------------\n");
		deleteCircularList(&list);
		if (list) {
			printf("리스트 삭제 안됐음!\n");
		} else {
			printf("리스트 삭제 완료!\n");
		}
	}
	//system("leaks a.out");
}