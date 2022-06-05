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

//그래프생성
LinkedGraph *createLinkedGraph(int maxVertexCount);
LinkedGraph *createLinkedDirectedGraph(int maxVertexCount);

//그래프 삭제
void deleteLinkedGraph(LinkedGraph *pGraph);
int isEmptyLG(LinkedGraph *pGraph);

//버텍스추가
int addVertexLG(LinkedGraph *pGraph, int vertexID);

//간선 추가
int addEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID, int weight);
int checkVertexValid(LinkedGraph *pGraph, int vertexID);

//버텍스 삭제
int removeVertexLG(LinkedGraph *pGraph, int vertexID);

//간선 삭제
int removeEdgeLG(LinkedGraph *pGraph, int fromVertexID, int toVertexID);

//그래프 보기
void displayLinkedGraph(LinkedGraph *pGraph);

#endif