#include <stdio.h>
#include <stdlib.h>
// creating an array
#define max 4
int c = 0;
int arr[max];
int top = -1;
void push()
{

    int val;
    if (top == max - 1)
    {
        printf("overflow ");
    }
    else
    {
        printf("Enter the value to be pushed ");
        scanf("%d", &val);
        top++;
        arr[top] = val;
    }
}
void display()
{
    printf("The array is: ");
    for (int i = 0; i <= top; i++)
    {
        printf("%d\n", arr[i]);
    }
}
void pop()
{
    printf("Deleted element:%d", arr[top]);
    top--;
}
void peek()
{
    if (top != -1)
    {
        printf("Peek %d", arr[top]);
    }
    else
    {
        printf("Empty stack");
    }
}
int main()
{
    push();
    push();
    push();
    push();
    push();
    pop();
    display();
    peek();
}