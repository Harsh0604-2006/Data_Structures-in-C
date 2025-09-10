#include <stdlib.h>
#include <stdio.h>
struct list_node
{
    int data;
    struct list_node *link;
};

struct list_node *head = NULL;

struct list_node *create_LL(struct list_node *head)
{
    int num;
    struct list_node *newnode, *ptr;

    printf("Enter the number to be inserted\n");
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
        printf("Enter the number to be inserted\n");
        scanf("%d", &num);
    }
    return head;
}
struct list_node *delete_before(struct list_node *head)
{
    struct list_node *ptr, *preptr, *prepreptr;
    ptr = head;
    preptr = ptr;
    int val;
    printf("Enter the number to be deleted before\n");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        prepreptr = preptr;
        preptr = ptr;
        ptr = ptr->link;
    }
    prepreptr->link = ptr;
    free(preptr);
    return head;
}
void display(struct list_node *head)
{
    printf("Linked list is: ");
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->link;
    }
}
int main()
{
    head = create_LL(head);
    display(head);
    head = delete_before(head);
    display(head);
}