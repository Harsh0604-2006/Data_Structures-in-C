#include <stdlib.h>
#include <stdio.h>

struct list_node
{

    int data;
    struct list_node *link;
};

struct list_node *head = NULL;
struct list_node *create(struct list_node *head)
{
    int num;
    struct list_node *newnode;
    struct list_node *ptr;
    printf("Creating a linked list");
    printf("Enter the data\n");
    scanf("%d", &num);
    head = NULL;
    while (num != -1)
    {
        newnode = (struct list_node *)malloc(sizeof(struct list_node));

        if (head == NULL)
        {
            newnode->data = num;
            newnode->link = NULL;
            head = newnode;
            ptr = newnode;
        }
        else
        {
            ptr->link = newnode;
            newnode->data = num;
            newnode->link = NULL;
            ptr = newnode;
        }
        printf("Enter the data\n");
        scanf("%d", &num);
    }
    return head;
}
void *display(struct list_node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
}
struct list_node *create6(struct list_node *head)
{
    int num, input;
    struct list_node *ptr, *preptr;
    struct list_node *newnode;

    ptr = head;
    printf("Enter the number after which do you have to add");
    scanf("%d", &num);
    printf("Enter the data");
    scanf("%d", &input);
    newnode = (struct list_node *)malloc(sizeof(struct list_node));
    newnode->data = input;
    ptr = head;
    preptr = ptr;
    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->link;
    }

    preptr->link = newnode;
    newnode->link = ptr;
    return head;
}
int main()
{

    head = create(head);
    display(head);
    head = create6(head);
    display(head);
}
