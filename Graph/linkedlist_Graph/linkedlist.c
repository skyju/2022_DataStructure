#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist_Graph.h"

LinkedList *createLinkedList()
{
    return ((LinkedList *)calloc(sizeof(LinkedList), 1));
}

Vertex *createVertex(Vertex element)
{
    Vertex *newVertex = calloc(sizeof(Vertex), 1);
    *newVertex = element;
    return (newVertex);
}

int addVertex(LinkedList *pList, int position, Vertex element)
{
    int i = 0;
    Vertex *pNewVertex = NULL;
    Vertex *pPreVertex = NULL;

    if (!pList || position < 0 || position > pList->currentVertexCount)
        return (FALSE);

    pNewVertex = createVertex(element);
    pPreVertex = &(pList->headerVertex);

    for (i = 0; i < position; i++)
        pPreVertex = pPreVertex->pLink;
    pNewVertex->pLink = pPreVertex->pLink;
    pPreVertex->pLink = pNewVertex;
    pList->currentVertexCount++;
    return (TRUE);
}

int removeVertex(LinkedList *pList, int position)
{
    int i = 0;
    Vertex *pDelVertex = NULL;
    Vertex *pPreVertex = NULL;

    pPreVertex = &(pList->headerVertex);
    for (i = 0; i < position; i++)
        pPreVertex = pPreVertex->pLink;
    pDelVertex = pPreVertex->pLink;
    pPreVertex->pLink = pDelVertex->pLink;
    free(pDelVertex);
    pList->currentVertexCount--;
    return (TRUE);
}

int getVertexID(LinkedList *pList, int position)
{
    int i = 0;

    Vertex *pCurVertex = &(pList->headerVertex);
    for (i = 0; i <= position; i++)
        pCurVertex = pCurVertex->pLink;

    return pCurVertex->data.vertexI;
}

void deleteLinkedListGraph(LinkedList *pList)
{
    Vertex *pDelVertex = NULL;
    Vertex *pPreVertex = pList->headerVertex.pLink;
    while (pPreVertex != NULL)
    {
        pDelVertex = pPreVertex;
        pPreVertex = pPreVertex->pLink;

        free(pDelVertex);
    }
    free(pList);
}

int getGraphVertexCount(LinkedList *pList)
{
    if (NULL != pList)
    {
        return pList->currentVertexCount;
    }
    return 0;
}
