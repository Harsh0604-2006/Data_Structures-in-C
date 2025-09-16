#include <stdlib.h>
#include <stdio.h>
#define max 4
int rear = -1;
int front = -1;
int arr[max];
int peek;
void enqueue()
{
    int val;
    printf("Enter the no to be enqueued\n");
    scanf("%d", &val);
    peek = front;
    if (rear == max - 1)
    {
        printf("queue overflow");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        arr[rear] = val;
    }
    else
    {
        rear++;
        arr[rear] = val;
    }
}
void dequeue()
{

    printf("Dequeueing\n");
    if (front == -1)
    {
        printf("queue underflow");
    }
    else
    {
        front++;
        peek = front;
    }
}
void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue empty");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d---", arr[i]);
        }
        printf("peek is;%d ", arr[front]);
    }
}
int main()
{
    enqueue();
    enqueue();
    enqueue();

    dequeue();
    display();
}