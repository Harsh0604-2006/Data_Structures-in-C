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
struct list *insert_beg(struct list *head)
{
    int num;
    struct list *ptr, *preptr, *newnode;
    printf("Enter the number to insert\n");
    scanf("%d", &num);
    newnode = (struct list *)malloc(sizeof(struct list));
    newnode->data = num;
    ptr = head;
    while (ptr->link != head)
    {
        ptr = ptr->link;
    }
    ptr->link = newnode;
    newnode->link = head;
    head = newnode;
}
void display()

{
    struct list *ptr;
    ptr = head;
    while (ptr->link != head)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }

    printf("%d", ptr->data);
}
int main()
{
    head = create_LL(head);
    display();
    head = insert_beg(head);
    display();
}