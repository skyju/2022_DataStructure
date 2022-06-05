#ifndef _LINKEDLIST_
#define _LINKEDLIST_

typedef struct GraphVertexType
{
    int vertexI;
    int weight;
} Vertex_Infor;

typedef struct LinkedListGraphVertexType
{
    Vertex_Infor data;
    struct LinkedListGraphVertexType *pLink;
} Vertex;

typedef struct LinkedListType
{
    int currentVertexCount;
    Vertex headerVertex;
} LinkedList;

typedef struct DirectLinkedGraphType
{
    int maxVertexCount; // 최대 버텍스 개수
    LinkedList **ppAdjEdge; // 엣지 저장을 위한 연결 리스트 포인터의 배열
} DirectLinkedGraph;

// 그래프 생성 - 엣지는 0개인 상태로 버텍스들만
LinkedList *createLinkedList();

Vertex *createVertex(Vertex element);
int addVertex(LinkedList *pList, int position, Vertex element);
int removeVertex(LinkedList *pList, int position);
int getVertexID(LinkedList *pList, int position);

void deleteLinkedListGraph(LinkedList *pList);
int getGraphVertexCount(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif