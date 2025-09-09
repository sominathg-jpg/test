#include <stdio.h>
// pointers

int f = 0, t = -1;

int queue[10];

void printQueue()
{

    if (f > t)
    {

        printf("Queue is empty\n");
    }
    else
    {

        for (int i = f; i <= t; i++)
        {
            printf("%d\t", queue[i]);
        }
    }
}
void enqueue(int ele)
{

    if (t == (sizeof(queue) / sizeof(queue[0])))
    {

        printf("queue is overflow\n");
    }
    else
    {
        queue[t + 1] = ele;
        t++;
        printf("element Enqueued...\n");
    }
}

void dequeue()
{

    if (f > t)
    {
        printf("queue is already empty\n");
    }
    else
    {
        f++;
        printf("Element is dequeued\n");
    }
}

int get_peek()
{

    return queue[t];
}

int main()
{

    // user driver

    do
    {

        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Peek\n");
        printf("4. Print Queue\n");
        int choice, ele;

        printf("Enter choice=\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter element for push:\n");
            scanf("%d", &ele);
            enqueue(ele);
            printQueue();
            break;

        case 2:
            dequeue();
            printQueue();
            break;
        case 3:
            ele = get_peek();
            printf("%d is a peek element of the queueu\n", ele);

            break;

        case 4:
            printQueue();
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (1);

    return 0;
}
