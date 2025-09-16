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
struct list_node *delete_before(struct list_node *head)
{
    struct list_node *ptr = head, *temp = ptr->prev;
    int val;
    printf("ENter the value to be deleted after");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    if (ptr->data != val)
    {
        printf("value not found");
    }
    else
    {

        temp->prev->next = ptr;
        ptr->prev = temp->prev;

        free(temp);
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
    head = delete_before(head);
    display();
}