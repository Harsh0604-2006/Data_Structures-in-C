#include <stdio.h>
#include <stdlib.h>
struct list_node
{
    int data;
    struct list_node *link;
};
struct list_node *head = NULL;
struct list_node *create_LL(struct list_node *head)
{
    struct list_node *ptr, *newnode;
    int num;
    printf("Enter the num to be added to the linked list\n");
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
        printf("Enter the num to be added to the linked list\n");
        scanf("%d", &num);
    }
    return head;
}
void display(struct list_node *head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
}
struct list_node *delete_at_end(struct list_node *head)
{
    struct list_node *preptr, *ptr;
    ptr = head;

    while (ptr->link != NULL)
    {

        preptr = ptr;
        ptr = ptr->link;
    }

    preptr->link = NULL;
    free(ptr);

    return head;
}

int main()
{
    head = create_LL(head);
    display(head);
    printf("Deleting at the end\n");
    head = delete_at_end(head);
    display(head);
}