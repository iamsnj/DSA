#include <iostream>
using namespace std;

int N = 10000; // size of stack

struct stack
{
    int A[10000];
    int top = -1;
};

int isFull(stack *s)
{
    return s->top == N;
}

int isEmpty(stack *s)
{
    return s->top == -1;
}

int top(stack *s)
{
    if(!isEmpty(s))
        return s->A[s->top];
    return -1;
}

int pop(stack *s)
{
    if(!isEmpty(s))
    {
        int x = s->A[s->top];
        s->top--;
        return x;
    }
    return -1;
}

void push(stack *s, int v)
{
    if(!isFull(s))
    {
        s->top++;
        s->A[s->top] = v;
    }
}

void span(stack *s, int n, int *arr, int *ans)
{
    int h[n];
    for(int i = 0; i < n; i++)
    {
        while(!isEmpty(s) && arr[i] >= arr[top(s)])
            pop(s);
        if(isEmpty(s))
        {
            push(s, i);
            h[i] = i;
            ans[i] = i+1;
        }
        else
        {
            h[i] = top(s);
            push(s, i);
            ans[i] = i - h[i];
        }
    }
}

int main()
{
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif
    int street; // no. of testcases
    scanf("%d", &street);
    // cin>> street;
    while(street--)
    {
        int build;
        scanf("%d", &build);
        // cin >> build;
        stack s;
        int high[build];
        for(int i = 0; i < build; i++)
            scanf("%d", &high[i]);
        	// cin>> high[i];
        int ans[build];
        span(&s, build, high, ans);
        for(int i = 0; i < build; i++)
            printf("%d\n", ans[i]);
        	// cout<<ans[i]<<endl;
    }
    // cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n";
    return 0;
}