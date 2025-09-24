#include <stdio.h>
#include <stdlib.h>
struct list_node
{

    int data;
    struct list_node *next;
};

struct list_node *rear = NULL;
struct list_node *front = NULL;
void create()
{
    front = rear = NULL;
}
void enqueue()
{
    int val;

    struct list_node *newrecord;
    newrecord = (struct list_node *)malloc(sizeof(struct list_node));

    printf("Enter the data ");
    scanf("%d", &newrecord->data);

    if (rear == NULL)
    {
        rear = newrecord;
        front = newrecord;
        newrecord->next = NULL;
    }
    else
    {
        rear->next = newrecord;

        rear = newrecord;
        newrecord->next = NULL;
    }
}
void deque()
{
    if (front == NULL)
    {
        printf("Queue Underflow");
        return;
    }
    struct list_node *temp;
    temp = front;
    front = front->next;
    free(temp);
    if (front == NULL)
        rear = NULL;
}
void display()
{
    struct list_node *temp = front;
    if (temp == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    enqueue();
    enqueue();
    display();
    deque();
    display();
}