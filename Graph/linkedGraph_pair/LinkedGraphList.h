#ifndef LINKED_GRAPH_LIST_H
#define LINKED_GRAPH_LIST_H

#include "./linkedNode.h"

typedef enum e_type
{
	DIRECTED = 1,
	UNDIRECTED = -1
} t_type;

typedef struct LinkedGraphType
{
	int			maxVertexCount;
	int			currentVertexCount;
	t_type		graphType;
	LinkedList	**ppAdjEdge;
	int			*pVertex;
} LinkedGraph;

LinkedGraph *createLinkedGraph(int maxVertexCount);
LinkedGraph *createLinkedDirectedGraph(int maxVertexCount);

void deleteLinkedGraph(LinkedGraph *pGraph);

int isEmptyLG(LinkedGraph *pGraph);

int addVertexLG(LinkedGraph *pGraph, int vertexID);

int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight);

int checkVertexValid(LinkedGraph *pGraph, int vertexID);

int removeVertexLG(LinkedGraph *pGraph, int vertexID);

int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

void displayLinkedGraph(LinkedGraph *pGraph);

#endif