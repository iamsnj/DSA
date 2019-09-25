#include <iostream>
#include <string>

using namespace std;

struct stack
{
    string A;
    int top = 0;
};

bool operand(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

bool isEmpty(stack *s)
{
    return s->top == 0;
}

bool isFull(stack *s, int n)
{
    return s->top == n;
}

void push(stack *s, int v, int n)
{
    if(!isFull(s, n))
    {
        s->top ++;
        s->A[s->top] = v;
    }
}

char pop(stack *s)
{
    if(!isEmpty(s))
    {
        char x = s->A[s->top];
        s->top --;
        return x;
    }
    return '\0';
}

char top(stack *s)
{
    if(!isEmpty(s))
        return s->A[s->top];
    return '\0';
}

bool checkBrackets(char ch)
{
    return (ch == ')' || ch == '(');
}

bool higherPrecedence(char c1, char c2)
{
    if(checkBrackets(c1))
        return false;
    if(c1 == '^')
    {
        if(c2 == '^')
            return false;
        return true;
    }
    if((c1 == '*' || c1 == '/') && c2 != '^')
        return true;
    if((c1 == '+' || c1 == '-') && (c2 == '+' || c2 == '-'))
        return true;
    return false;
}

void infix(stack *s, string in, char *ans, int n)
{
    char x;
    int i = 0, j = 0;
    while(i < n)
    {
        if(operand(in[i]))
        {
            ans[j] = in[i];
            j++;
        }
        else
        {
            if(!checkBrackets(in[i]))
            {
                while(!isEmpty(s) && higherPrecedence(top(s), in[i])) // top(s) >= s.A[i] in precedence
                {
                    x = pop(s);
                    ans[j] = x;
                    j++;
                }
            }
            push(s, in[i], n);
        }
        if(in[i] == ')')
        {
            x = pop(s);
            while(x != '(')
            {
                x = pop(s);
                if(x != '(')
                {
                    ans[j] = x;
                    j++;
                }
            }
        }
        i++;
    }
    while(!isEmpty(s))
    {
        x = pop(s);
        ans[j] = x;
        j++;
    }
}

int main()
{
    int n;
    stack s;
    string in;
    cin>> in;
    n = in.size();
    int count_brc = 0; // count brackets in input string
    for(int i = 0; i < n; i++)
        if(in[i] == ')' || in[i] == '(')
            count_brc++;
    char ans[n-count_brc];
    infix(&s, in, ans, n);
    for(int i = 0; i < n-count_brc; i++)
        cout<<ans[i];
    return 0;
}