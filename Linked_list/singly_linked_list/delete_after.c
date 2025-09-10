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
    int num;
    struct list_node *ptr, *newnode;
    printf("Enter the number\n");
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
        printf("Enter the number\n");
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
struct list_node *delete_after(struct list_node *head)
{
    int num;
    printf("Enter the value to be deleted after\n");
    scanf("%d", &num);
    struct list_node *ptr, *preptr;

    ptr = head;
    preptr = ptr;
    while (preptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->link;
    }
    preptr->link = ptr->link;
    free(ptr);
    return head;
}
int main()
{
    head = create_LL(head);
    display(head);
    head = delete_after(head);
    display(head);
}