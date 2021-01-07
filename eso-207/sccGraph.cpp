#include<iostream>
using namespace std;
#define ll long long

ll N = 100010; // size of stack

struct stack
{
    ll A[100010];
    ll top = 0;
};

bool isEmpty(stack *s)
{
    return s->top == 0;
}

bool isFull(stack *s)
{
    return s->top == N;
}

ll pop(stack *s)
{
    if(!isEmpty(s))
    {
        ll x = s->A[s->top];
        s->top--;
        return x;
    }
    else return -1;
} 

void push(stack *s, ll v)
{
    if(!isFull(s))
    {
        s->top++;
        s->A[s->top] = v;
    }
}

struct node
{
    ll data;
    node *ptr;
};
 
struct vertexNode
{
    node *head;
};
 
struct Graph
{
    ll v;
    vertexNode *w; 
};

node* createNode(ll val)
{
    node *newNode = (node*)malloc(sizeof(ll));
    newNode->data = val;
    newNode->ptr = NULL;
    return newNode;
}

Graph* createGraph(ll n)
{
    Graph *G = (Graph*)malloc(sizeof(ll));
    G->v = n;
    G->w = new vertexNode[n+1];
    for(ll i = 0; i < n+1; i++)
        G->w[i].head = NULL;
    return G;
}

void adjList(Graph *G, ll u, ll v)
{
    node *newNode2 = createNode(v);
    node *temp = (node*)malloc(sizeof(ll));
    if(G->w[u].head == NULL)
        G->w[u].head = newNode2;
    else
    {
        newNode2->ptr = G->w[u].head;
        G->w[u].head = newNode2;
    }
}

void DFS_visit(Graph *G, ll i, ll *visited, stack *s)
{
    while(G->w[i].head != NULL)
    {
        ll v = G->w[i].head->data;
        if(visited[v] == 0)
        {
            visited[v] = 1;
            DFS_visit(G, v, visited, s);
        }
        G->w[i].head = G->w[i].head->ptr;
    }
    push(s, i);
}

ll len = 0;

void findSCC(Graph *GR, ll i, ll *visited)
{
    visited[i] = 1;
    while(GR->w[i].head != NULL)
    {
        ll v = GR->w[i].head->data;
        if(visited[v] == 0)
        {
            len++;
            findSCC(GR, v, visited);
        }
        GR->w[i].head = GR->w[i].head->ptr;
    }
}

int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        ll V, E;
        cin >> V >> E;
        Graph *G = createGraph(V);
        stack s;
        Graph *GR = createGraph(V);
        ll a, b;
        for(ll i = 0; i < E; i++)
        {
            cin >> a >> b;
            adjList(G, a, b);
            adjList(GR, b, a);
        }

        ll visited[V] = {0};
        for(ll i = 0; i < V; i++)
            if(visited[i] == 0)
            {
                visited[i] = 1;
                DFS_visit(G, i, visited, &s);
            }
        ll prev = 0;
        for(ll i = 0; i < V; i++)
            visited[i] = 0;
        while(!isEmpty(&s))
        {
            ll x = pop(&s);
            if(visited[x] == 0)
            {
                len++;
                findSCC(GR, x, visited);
                if(len > prev) prev = len;
                len = 0;
            }
        }
        cout << prev << endl;
    }
   return 0;
}

