#include <stdio.h>
#include <stdlib.h>

struct list
{
    int data;
    struct list *link;
};
struct list *head = NULL;
struct list *tail = NULL;
struct list *create_LL()
{
    int num;
    struct list *ptr, *preptr, *newnode;
    printf("Enter the number to insert\n");
    scanf("%d", &num);
    while (num != -1)
    {
        newnode = (struct list *)malloc(sizeof(struct list));
        newnode->data = num;
        if (head == NULL)
        {

            newnode->link = newnode;
            head = newnode;
        }
        else
        {
            ptr = head;
            while (ptr->link != head)
            {
                ptr = ptr->link;
            }
            ptr->link = newnode;
            newnode->link = head;
        }
        printf("Enter the number to insert\n");
        scanf("%d", &num);
    }
    return head;
}
void display()
{
    struct list *ptr;
    ptr = head;
    printf("Linked List: ");
    while (ptr->link != head)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("%d->", ptr->data);
}
struct list *delete_beg(struct list *head)
{
    struct list *ptr, *preptr;
    ptr = head;
    while (ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = head->link;
    preptr = ptr;
    free(head);
    head = ptr->link;
    return head;
}
int main()
{
    head = create_LL(head);
    display();
    head = delete_beg(head);
    display();
}