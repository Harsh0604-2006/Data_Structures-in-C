#include <stdio.h>
#include <stdlib.h>
/*
pointer = (data_type *)malloc(number_of_elements * sizeof(data_type)); // malloc generalized
*/
struct node
{
    int data;
    struct node *link;
};
struct node *head = NULL;

struct node *create(struct node *start)
{
    struct node *new_node;
    int num;
    printf("Creating  a linkedlist\n");
    printf("Enter the data and to end type -1");
    scanf("%d", &num);
    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;

        if (start == NULL)
        {
            new_node->link = NULL;
            start = new_node;
        }
        else
        {
            new_node->link = start;
            start = new_node;
        }
        printf("Enter the data and to end type -1");
        scanf("%d", &num);
    }
    return start;
}
struct node *display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    printf("\n");
    printf("Displaying a linkedlist");
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->link;
    }
    printf("NULL");
    return start;
}
int main()
{
    head = create(head);
    display(head);
}
