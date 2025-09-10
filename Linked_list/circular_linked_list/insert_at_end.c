#include <stdlib.h>
#include <stdio.h>
struct list
{
    int data;
    struct list *link;
};
struct list *head = NULL;
struct list *create(struct list *head)
{
    int num;
    struct list *ptr, *newnode;
    printf("Enter the number to create the linked list");
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
        printf("Enter the number to create the linked list");
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
struct list *end(struct list *head)
{
    int val;

    struct list *ptr, *newnode;
    ptr = head;
    printf("Enter the number to inserted");
    scanf("%d", &val);
    newnode = (struct list *)malloc(sizeof(struct list));
    newnode->data = val;
    while (ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    newnode->link = head;
    return head;
}
int main()
{
    head = create(head);
    display();
    head = end(head);
    display();
}