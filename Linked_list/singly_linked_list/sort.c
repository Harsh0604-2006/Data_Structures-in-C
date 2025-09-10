#include <stdio.h>
#include <stdlib.h>

struct list_node
{
    int data;
    struct list_node *link;
};
struct list_node *head = NULL;
struct list_node *create(struct list_node *start)
{
    int num;
    struct list_node *newnode;
    struct list_node *ptr = NULL;

    printf("Enter the data:\n");

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
            ptr->link = newnode;
            newnode->data = num;
            newnode->link = NULL;
            ptr = newnode;
        }
        printf("Enter the data:\n");

        scanf("%d", &num);
    }
    return start;
}
struct list_node sort(struct list_node *head)
{
    struct list_node *ptr, *preptr;
    preptr = head;
    ptr = preptr;
    int temp;
    while (preptr->link != NULL)
    {
        ptr = preptr->link;
        while (ptr != NULL)
        {

            if (ptr->data < preptr->data)
            {
                temp = ptr->data;
                ptr->data = preptr->data;
                preptr->data = temp;
            }
            ptr = ptr->link;
            preptr = ptr;
        }
        preptr = preptr->link;
    }
    return head;
}
void display(struct list_node *start)
{
    struct list_node *ptr;
    ptr = start;
    while (ptr != NULL)
    {

        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
}
int main()
{
    head = create(head);
    create(head);
    display(head);
    head = sort(head);
    sort(head);
    display(head);
}
