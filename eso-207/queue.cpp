#include <iostream>
using namespace std;

int N = 100000; // size of the queue

struct queue
{
    int A[100000];
    int head;
    int tail;
};

bool isEmpty(queue *q)
{
    return q->head == q->tail;
}

bool isFull(queue *q)
{
    int i = q->tail;
    if (q->tail == N){
        i = 1;
    }else{
        i++;
    }
    return i == q->head;
}

void enQueue(queue *q, int x)
{
    if (!isFull(q))
    {
        q->A[q->tail] = x;
        if (q->tail == N){
            q->tail = 1;
        }else{
            q->tail++;
        }
    }
}

int deQueue(queue *q)
{
    int x;
    if (!isEmpty(q))
    {
        x = q->A[q->head];
        if (q->head == N){
            q->head = 1;
        }else{
            q->head ++;
        }
    }
    return x;
}

int main()
{
    queue q;
    q.head = 0;
    q.tail = 0;
    enQueue(&q, 1);
    cout << "head : " << q.head << endl;
    cout << "tail : " << q.tail << endl;
    cout << deQueue(&q) << endl;
    return 0;   
}