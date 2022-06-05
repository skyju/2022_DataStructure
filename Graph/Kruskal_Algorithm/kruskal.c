#include "heap.h"
#include "./LinkedGraphList.h"
#include <stdio.h>

// 크러스칼 : 엣지기준

// 엣지의 웨이트를 민힙에 insert
Heap *to_heap(LinkedGraph *graph)
{
	ListNode *vertex;
	Heap *edgeHeap;
	HeapNode tmp;

	if (!graph)
	{
		printf("graph is null.\n");
		return (NULL);
	}
	edgeHeap = createHeap(graph->maxVertexCount);

	for (int i = 0; i < graph->maxVertexCount; i++)
	{
		vertex = &(graph->ppAdjEdge[i]->headerNode);
		tmp.vertexID_1 = i;
		while (vertex->pLink != NULL)
		{ // i번째 vertex가 가지고 있는 엣지를 순회
			tmp.vertexID_2 = (*vertex).data.vertexID;
			tmp.weight = (*vertex).data.weight;
			insertMinHeap_weight(edgeHeap, tmp);
			vertex = vertex->pLink;
		}
	}
	return (edgeHeap);
}

void *kruskal(LinkedGraph *graph)
{
	Heap *edgeHeap;
	HeapNode *node;

	if (!graph)
		printf("graph is null.\n");
	edgeHeap = to_heap(graph);

	// 1. max count 만큼 1,2,3,4,5 - 숫자배열
	int arr[edgeHeap->currentElementCount];
	for (int i = 0; i < edgeHeap->currentElementCount; i++)
		arr[i] = i;
	
	int count = edgeHeap->currentElementCount;
	// 2. peek_zero(), -> weight가 작은순으로 나옴-> ID1을 부모로 보고 ID2를 1로 바꿈?
	for (int i = 0; i < count; i++)
	{
		node = pop_zero(edgeHeap);
		int v = node->vertexID_1;
		if (v != arr[v])
		{
			arr[v] = node->vertexID_2;
		}
		else
			continue;
		;
	}

	int sum;
	sum = 0;
	for (int i = 0; i < count; i++)
		sum += arr[i];
	printf("최단경로: %d\n", sum);
}


int main()
{
	LinkedGraph *graph = createLinkedGraph(10);
	ListNode node;
	printf("======================UNDIRECTED LinkedGraph TEST======================\n");

	printf("======================PUSH 0 to 9======================\n");
	addVertexLG(graph, 0);
	addVertexLG(graph, 1);
	addVertexLG(graph, 2);
	addVertexLG(graph, 3);
	addVertexLG(graph, 4);
	addVertexLG(graph, 5);
	addVertexLG(graph, 6);
	addVertexLG(graph, 7);
	addVertexLG(graph, 8);
	addVertexLG(graph, 9);

	printf("Now, Vertex Count = %d\n", graph->currentVertexCount);
	printf("======================MAKE EDGE TEST======================\n");
	addEdgeLG(graph, 0, 2);
	addEdgeLG(graph, 0, 4);
	addEdgeLG(graph, 0, 6);
	addEdgeLG(graph, 0, 8);
	addEdgeLG(graph, 1, 3);
	addEdgeLG(graph, 1, 5);
	addEdgeLG(graph, 1, 7);
	addEdgeLG(graph, 1, 9);
	addEdgeLG(graph, 2, 4);

	printf("======================DISPLAY======================\n");
	displayLinkedGraph(graph);
	kruskal(graph);
}
