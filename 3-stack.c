#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 5
int stack[MAX];
int top = -1;
int item;

void push(item)
{

    if (top == (MAX - 1))
        printf("\n Stack Overflow");
    else
    {
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top == -1)
        printf("\n Stack Underflow");
    else
    {
        item = stack[top];
        top--;
    }
}

void display()
{
    int i;
    if (top == -1)
        printf("\n Sorry Empty Stack");
    else
    {
        printf("\nThe elements of the stack are\n");
        for (i = top; i >= 0; i--)
            printf("stack[%d] = %d\n", i, stack[i]);
    }
}

void palindrome()
{
    int num, temp, digit, revnum = 0, k = 0;
    while (top != -1)
        pop();

    printf("Enter the number\n");
    scanf("%d", &num);
    temp = num;

    while (temp != 0)
    {
        digit = temp % 10;
        push(digit);
        temp = temp / 10;
    }
    while (top != -1)
    {
        pop();
        revnum = item * pow(10, k) + revnum;
        k = k + 1;
    }
    printf("The reverse of given number is %d\n", revnum);
    if (num == revnum)
        printf("The given no. is pallindrome\n");
    else
        printf("The given no. is not a pallindrome\n");
}
void main()
{
    int choice;
    while (1)
    {
        printf("\nSTACK OPERATIONS\n");
        printf("\n1.Push\n2.Pop\n3.Display\n4.Palindrome\n5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            palindrome();
            break;
        case 5:
            return;
        default:
            printf("Invalid choice\n");
        }
    }
}