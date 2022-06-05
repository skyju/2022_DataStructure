#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_Graph.h"

// 그래프 생성
DirectLinkedGraph *createDirectLinkedGraph(int maxVertexCount)
{
    DirectLinkedGraph *pReturn = NULL;

    if (maxVertexCount <= 0)
    {
        printf("Invalid Node count.\n");
        return (NULL);
    }
    pReturn = (DirectLinkedGraph *)malloc(sizeof(DirectLinkedGraph));
    if (!pReturn)
    {
        printf("Memory Allocation failed.\n");
        return (NULL);
    }
    pReturn->maxVertexCount = maxVertexCount;
    pReturn->ppAdjEdge = (LinkedList **)malloc(sizeof(LinkedList *) * maxVertexCount);
    if (pReturn->ppAdjEdge == NULL)
    {
        printf("Memory Allocation failed.\n");
        free(pReturn);
        return (NULL);
    }
    //노드 개수만큼 linked list 만들기
    for (int i = 0; i < maxVertexCount; i++)
    {
        pReturn->ppAdjEdge[i] = createLinkedList();
        if (pReturn->ppAdjEdge[i] == NULL)
        {
            printf("Memory Allocation failed.\n");
            free(pReturn->ppAdjEdge);
            free(pReturn);
            return NULL;
        }
    }
    return (pReturn);
}

// 유효한 노드인지 체크
int checkVertexValid(DirectLinkedGraph *pGraph, int node)
{
    if (pGraph != NULL && node >= 0 && node < pGraph->maxVertexCount)
        return 1;
    else
        return 0;
}

// 간선 추가하기
int addEdgeDLG(DirectLinkedGraph *pGraph, int fromNode, int toNode)
{
    int ret = 0;
    Vertex toVertex;

    if (pGraph != NULL
        && checkVertexValid(pGraph, fromNode)
        && checkVertexValid(pGraph, toNode)
        && (fromNode != toNode)) //자기 자신과의 연결 불가
        toVertex = 
        addVertex(pGraph->ppAdjEdge[fromNode], 0, toNode);
    else
        ret = -1;
    return ret;
}

// 간선 끊기 (삭제하기)
int removeEdgeDLG(DirectLinkedGraph *pGraph, int fromNode, int toNode)
{
    int ret = -1;
    int i = 0;
    int count = 0;
    LinkedList *pList = NULL;

    if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode))
    {
        pList = pGraph->ppAdjEdge[fromNode];
        count = getLinkedListLength(pList);
        for (i = 0; i < count; i++)
        {
            if (getLinkedListData(pList, i) == toNode)
            {
                removeLinkedListData(pList, i);
                ret = 0;
                break;
            }
        }
    }
    else // 해당하는 간선이 없는 경우 (삭제에 실패한 경우)
        ret = -1;
    return ret;
}

// 간선 가져오기
int getEdgeDLG(DirectLinkedGraph *pGraph, int fromNode, int toNode)
{
    int ret = 0;
    LinkedList *pList = NULL;
    int i = 0, count = 0;

    if (pGraph != NULL && checkVertexValid(pGraph, fromNode) && checkVertexValid(pGraph, toNode))
    {
        pList = pGraph->ppAdjEdge[fromNode];
        count = getLinkedListLength(pList);
        for (i = 0; i < count; i++)
        {
            if (getLinkedListData(pList, i) == toNode)
            {
                ret = 1;
                break;
            }
        }
    }
    return ret;
}

// 그래프 보여주기
void displayGraphDLG(DirectLinkedGraph *pGraph)
{
    int count = 0;

    if (pGraph != NULL)
    {
        count = pGraph->maxVertexCount;
        for (int i = 0; i < count; i++)
        {
            for (int j = 0; j < count; j++)
            {
                if (getEdgeDLG(pGraph, i, j))
                    printf("1 ");
                else
                    printf("0 ");
            }
            printf("\n");
        }
    }
}

// 그래프 삭제하기
void deleteGraphDLG(DirectLinkedGraph *pGraph)
{
    int i = 0;

    if (pGraph != NULL)
    {
        for (i = 0; i < pGraph->maxVertexCount; i++)
        {
            deleteLinkedList(pGraph->ppAdjEdge[i]);
        }
        if (pGraph->ppAdjEdge != NULL)
            free(pGraph->ppAdjEdge);
        free(pGraph);
    }
}

int main(int argc, char *argv[])
{
    int maxVertexCount = 6;
    DirectLinkedGraph *pG2 = createDirectLinkedGraph(maxVertexCount);
    if (pG2 != NULL)
    {
        addEdgeDLG(pG2, 0, 1);
        addEdgeDLG(pG2, 1, 2);
        addEdgeDLG(pG2, 2, 0);
        addEdgeDLG(pG2, 2, 3);
        addEdgeDLG(pG2, 3, 2);
        addEdgeDLG(pG2, 3, 4);
        addEdgeDLG(pG2, 4, 5);
        addEdgeDLG(pG2, 5, 3);

        printf("G2: 방향그래프\n");
        displayGraphDLG(pG2);
        deleteGraphDLG(pG2);
    }

    return 0;
}

/*

 int findGraphNodePosition(LinkedList* pList, int vertexID)
 {
 int i = 0, position = 0;
 ListNode* pNode = NULL;

 if (pList != NULL) {
 pNode = pList->headerNode.pLink;
 while(pNode != NULL) {
 if (pNode->data.vertexID == vertexID) {
 return position;
 }

 pNode = pNode->pLink;
 position++;
 }
 }

 return -1;
 }



 int getEdgeCountLG( DirectLinkedGraph* pGraph) {
 int ret = 0;

 if (pGraph != NULL) {
 ret = pGraph->currentEdgeCount;
 }

 return ret;
 }


 int getVertexCountLG( DirectLinkedGraph* pGraph) {
 int ret = 0;

 if (pGraph != NULL) {
 ret = pGraph->currentVertexCount;
 }

 return ret;
 }

 int getMaxVertexCountLG( DirectLinkedGraph* pGraph)
 {
 int ret = 0;

 if (pGraph != NULL) {
 ret = pGraph->nodeCount;
 }

 return ret;
 }

 int getGraphTypeLG( DirectLinkedGraph* pGraph)
 {
 int ret = 0;

 if (pGraph != NULL) {
 ret = pGraph->graphType;
 }

 return ret;
 }

 int isEmptyLG( DirectLinkedGraph* pGraph)
 {
 int ret = TRUE;

 if (pGraph != NULL) {
 if (pGraph->currentVertexCount > 0) {
 ret = FALSE;
 }
 }

 return ret;
 }



 void deleteGraphNode(LinkedList* pList, int delVertexID)
 {
 int i = 0, position = 0;
 ListNode* pNode = NULL;

 position = findGraphNodePosition(pList, delVertexID);
 if (position >= 0) {
 removeLLElement(pList, position);
 }
 }
 */
