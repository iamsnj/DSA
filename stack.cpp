#include<iostream>
using namespace std;

int N = 100000; // size of stack

struct stack
{
    int A[100000];
    int top = 0;
};

bool isEmpty(stack *s)
{
    return s->top == 0;
}

bool isFull(stack *s)
{
    return s->top == N;
}

int pop(stack *s)
{
    if(!isEmpty(s))
    {
        int x = s->A[s->top];
        s->top--;
        return x;
    }
    else return -1;
} 

void push(stack *s, int v)
{
    if(!isFull(s))
    {
        s->top++;
        s->A[s->top] = v;
    }
}

int topVal(stack *s)
{
    if(!isEmpty(s))
        return s->A[s->top];
    else return -1;
}

int main()
{
    int n;
    cin >> n;
    stack s;
    int arr[n];
    // s.A = (int*)malloc(n * sizeof(int)); // initialize the stack
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        push(&s, arr[i]);
    }
    cout<<pop(&s);
    return 0;
}