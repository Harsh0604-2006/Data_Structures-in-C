#include <stdio.h>
#include <stdlib.h>
struct list_node
{
    int data;
    struct list_node *link;
};
struct list_node *head = NULL;
struct list_node *create(struct list_node *head)
{

    struct list_node *newnode, *ptr;
    int num;
    printf("Enter the data:\n ");
    scanf("%d", &num);
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

            newnode->data = num;
            newnode->link = NULL;
            ptr->link = newnode;
            ptr = newnode;
        }
        printf("Enter the data:\n ");
        scanf("%d", &num);
    }
    return head;
}

struct list_node *create_before(struct list_node *head)
{
    int bval, num;
    struct list_node *ptr, *preptr, *newnode;
    printf("Enter the no to be added");
    scanf("%d", &num);
    printf("Enter the number where we have to add before it");
    scanf("%d", &bval);
    newnode = (struct list_node *)malloc(sizeof(struct list_node));
    newnode->data = num;
    ptr = head;
    while (ptr->data != bval)
    {
        preptr = ptr;
        ptr = ptr->link;
    }
    preptr->link = newnode;
    newnode->link = ptr;
    return head;
}
void display(struct list_node *start)
{

    while (start != NULL)
    {
        printf("%d->", start->data);
        start = start->link;
    }
}
int main()
{
    head = create(head);
    display(head);
    head = create_before(head);
    display(head);
}