#include<iostream>
using namespace std;
 
struct node
{
	int data;
	struct node *ptr;
};
 
struct vertexNode
{
	struct node *head;
};
 
struct Graph
{
	int v;
	struct vertexNode *w; 
};

node* createNode(int val)
{
	struct node *newNode = (node*)malloc(sizeof(int));
	newNode->data = val;
	newNode->ptr = NULL;
	return newNode;
}

Graph* createGraph(int n)
{
	struct Graph *G = (Graph*)malloc(sizeof(int));
	G->v = n;
	G->w = new vertexNode[n+1];
	for(int i = 0; i < n+1; i++)
		G->w[i].head = NULL;
	return G;
}

void adjList(Graph *G, int u, int v)
{
	node *newNode2 = createNode(v);
	node *temp = (node*)malloc(sizeof(int));
	if(G->w[u].head == NULL)
		G->w[u].head = newNode2;
	else
	{
		newNode2->ptr = G->w[u].head;
		G->w[u].head = newNode2;
	}
}
 
int main()
{
	int V, E;
	cin >> V >> E;
	struct Graph *G = createGraph(V);
  int a, b;
	for(int i = 0; i < E; i++)
	{
		cin >> a >> b;
		adjList(G, a, b);
	}
	
	for(int i = 0; i < V; i++)
	{
		cout<<"V("<<i<<") -> {  ";
		while(G->w[i].head != NULL)
		{
			cout << G->w[i].head->data << "  ";
			G->w[i].head = G->w[i].head->ptr;
		}
		cout<<"}\n";
	}
}
