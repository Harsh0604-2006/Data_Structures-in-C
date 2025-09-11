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
struct list_node *delete_list(struct list_node *head)
{
    int val, num;
    struct list_node *ptr, *newnode;
    ptr = head;
    printf("Enter the number to be node to be deleted\n");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr->data == head->data)
    {

        ptr->next->prev == NULL;
        head = ptr->next;
        free(ptr);
    }
    else if (ptr->next == NULL)
    {
        ptr->prev->next = NULL;
        free(ptr);
    }
    else
    {
        ptr->prev->next = ptr->next;
        ptr->next->prev = ptr->prev;
        free(ptr);
    }

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
    head = delete_list(head);
    display();
}