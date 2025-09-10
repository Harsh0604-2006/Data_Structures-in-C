#include <stdlib.h>
#include <stdio.h>
struct list_node
{
    struct list_node *prev;
    int data;
    struct list_node *next;
};
struct list_node *head;
struct list_node *create_dLL(struct list_node *head)
{
    int num;
    struct list_node *ptr, *preptr, *newnode;
    printf("Enter the to be inserted:");
    scanf("%d", &num);

    while (num != -1)
    {
        newnode = (struct list_node *)malloc(sizeof(struct list_node));
        if (head == NULL)
        {

            newnode->data = num;
            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;
            ptr = head;
        }
        else
        {
            ptr = head;

            newnode->data = num;
            newnode->next = NULL;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
            newnode->prev = ptr;
        }
        printf("Enter the to be inserted:");
        scanf("%d", &num);
    }
    return head;
}
struct list_node *insert_end(struct list_node *head)
{
    int val;
    struct list_node *ptr, *newnode;
    ptr = head;
    newnode = (struct list_node *)malloc(sizeof(struct list_node));

    printf("Enter the to be inserted:");
    scanf("%d", &val);
    newnode->data = val;
    newnode->next = NULL;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = newnode;
    newnode->prev = ptr;
    return head;
}
void display()
{
    struct list_node *ptr;
    ptr = head;
    printf("Linked List created: ");
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d->", ptr->data);
}
int main()
{
    head = create_dLL(head);
    display();
    head = insert_end(head);
    display();
}
