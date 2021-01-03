#include <iostream>
using namespace std;
#define ll long long

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

node *createNode(ll val)
{
    node *newNode = (node *)malloc(sizeof(ll));
    newNode->data = val;
    newNode->ptr = NULL;
    return newNode;
}

Graph *createGraph(ll n)
{
    Graph *G = (Graph *)malloc(sizeof(ll));
    G->v = n;
    G->w = new vertexNode[n + 1];
    for (ll i = 0; i < n + 1; i++)
        G->w[i].head = NULL;
    return G;
}

void adjList(Graph *G, ll u, ll v)
{
    node *newNode2 = createNode(v);
    node *newNode1 = createNode(u);
    node *temp = (node *)malloc(sizeof(ll));
    if (G->w[u].head == NULL)
        G->w[u].head = newNode2;
    else
    {
        newNode2->ptr = G->w[u].head;
        G->w[u].head = newNode2;
    }
    if (G->w[v].head == NULL)
        G->w[v].head = newNode1;
    else
    {
        newNode1->ptr = G->w[v].head;
        G->w[v].head = newNode1;
    }
}

ll bipartite(Graph *G, ll *vis, ll i)
{
    while(G->w[i].head != NULL)
    {
        ll u1;
        u1 = G->w[i].head->data;
        if(vis[i] == 0)
        {
            if(u1 == 0)
                return 0;
            vis[u1] = 1;
        }
        else if(vis[i] == 1)
        {
            if(u1 == 1)
                return 0;
            vis[u1] = 1;
        }
        else // vis[i] = -1
        {
            if(vis[u1] == 0)
                vis[i] = 1;
            else if(vis[u1] == 1)
                vis[i] = 0;
            else
                vis[i] = 0;
            
        }
    }
    return 1;
}

int main()
{
    ll s;
    cin >> s;
    while(s--)
    {
        ll V, E, a, b;
        cin >> V >> E;
        Graph *G = createGraph(V+1);
        for(ll i = 0; i < E; i++)
        {
            cin >> a >> b;
            adjList(G, a, b);
        }
        ll vis[V+1];
        for(ll i = 1; i <= V+1; i++)
            vis[i] = -1;
        vis[1] = 0;
        while(G->w[1].head != NULL)
        {
            ll v = G->w[1].head->data;
            vis[v] = 1;
            G->w[1].head = G->w[1].head->ptr;
        }
        ll ans, cnt = 0;
        for(ll i = 2; i <= V+1; i++)
        {
            ans = bipartite(G, vis, i);
            if(ans)
                cnt++;
        }
        if(cnt == V)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
