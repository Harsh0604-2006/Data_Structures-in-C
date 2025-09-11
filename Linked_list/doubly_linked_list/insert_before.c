#include <stdio.h>
#include <stdlib.h>
struct list_node
{
    struct list_node *prev;
    struct list_node *next;
    int data;
};
struct list_node *head = NULL;
struct list_node *create_dLL(struct list_node *head)
{
    int val;
    struct list_node *ptr, *newnode;

    printf("Enter the number\n");
    scanf("%d", &val);

    while (val != -1)
    {
        newnode = (struct list_node *)malloc(sizeof(struct list_node));
        if (head == NULL)
        {
            newnode->data = val;
            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;
        }

        else
        {
            ptr = head;
            newnode->data = val;
            newnode->next = NULL;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            newnode->prev = ptr;
            ptr->next = newnode;
        }
        printf("Enter the number\n");
        scanf("%d", &val);
    }

    return head;
}
struct list_node *insert_before(struct list_node *head)
{
    int val, num;
    struct list_node *ptr, *newnode, *preptr;
    newnode = (struct list_node *)malloc(sizeof(struct list_node));
    ptr = head;
    preptr = ptr;
    printf("Enter the number to be added\n");
    scanf("%d", &val);
    printf("Enter the number to be added before what\n");
    scanf("%d", &num);
    while (ptr->data != num)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    newnode->data = val;
    newnode->next = ptr;
    newnode->prev = ptr->prev;
    ptr->prev->next = newnode;
    ptr->prev = newnode;
    return head;
}
void display()
{
    struct list_node *ptr;
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    head = create_dLL(head);
    display();
    head = insert_before(head);
    display();
}