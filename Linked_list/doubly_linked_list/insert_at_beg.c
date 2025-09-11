#include <stdlib.h>
#include <stdio.h>
struct list_node
{
    struct list_node *next;
    struct list_node *prev;
    int data;
};

struct list_node *head = NULL;
struct list_node *create_dll(struct list_node *head)
{
    int num;
    struct list_node *ptr, *newnode;
    printf("Enter the number to be inserted");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct list_node *)malloc(sizeof(struct list_node));
        newnode->data = num;
        if (head == NULL)
        {

            newnode->next = NULL;
            newnode->prev = NULL;
            head = newnode;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->prev = ptr;
            newnode->next = NULL;
        }
        printf("Enter the number to be inserted");
        scanf("%d", &num);
    }
    return head;
}
struct list_node insert_at_beg(struct list_node *head)
{
}

void display()
{
    struct list_node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("%d->", ptr->data);
}
int main()
{
    head = create_dll(head);
    display();
}