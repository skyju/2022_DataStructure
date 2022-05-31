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
    int currentCount;
    Vertex headerVertex;
} LinkedList;

LinkedList *createLinkedListGraph();

Vertex *createVertex(Vertex element);
int addVertex(LinkedList *pList, int position, Vertex element);
int removeVertex(LinkedList *pList, int position);
int getVertexI(LinkedList *pList, int position);

void deleteLinkedListGraph(LinkedList *pList);
int getGraphVertexCount(LinkedList *pList);

#endif

#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif