#include <stdio.h>

// this is a pointer to point to the top peek of the stack
int Top = -1;

// this is 10 capacity of stack
int a[10];

// fuction for printing stack
void printStack()
{

    // checking undeflow conditiob
    if (Top == -1)
    {
        printf("there is no stack\n");
    }
    else
    {

        // loop for printing a stack
        printf("\n--------------------------------------\n");
        for (int i = Top; i >= 0; i--)
        {
            printf("%d\n", a[i]);
        }
        printf("\n--------------------------------------\n");
    }
}

// function for pushing a element in the stack
void push(int ele)
{

    // checking the stack in over flow or what
    if ((sizeof(a) / sizeof(a[0])) - 1 == Top)
    {
        printf("stack is over flow\n");
    }
    else
    {
        // logic for pushing element into stack

        a[Top + 1] = ele;
        Top++;
        printf("element pushed...\n");
    }
}

// function for pop the element from the stack
void pop()
{
    // checking the stack is undeflow or what

    if (Top == -1)
    {
        printf("stack is already in the underflow condition\n");
    }
    else
    {
        // poping the element from the stack
        Top--;
        printf("Element is popped...\n");
        printStack();
    }
}

// function for getting a peek elw

int getPeek()
{

    if (Top == -1)
    {
        printf("stack is underflow\n");
        return -1;
    }
    else
    {

        return a[Top];
    }
}

int main()
{

    // user driver
    do
    {

        printf("1.push\n");
        printf("2.pop\n");
        printf("3.peek\n");
        printf("4.display\n");

        int choice, ele;
        printf("Enter choice=\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element for the push:\n");
            scanf("%d", &ele);
            push(ele);
            printStack();
            break;

        case 2:
            pop();
            break;
        case 3:
            ele = getPeek();
            printf("%d is a peek element of the stack\n", ele);
            break;
        case 4:
            printStack();
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (1);
}