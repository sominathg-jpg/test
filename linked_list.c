#include <stdio.h>
// lib for dynamic allocation
#include <stdlib.h>

// node for the list
struct Node
{
    int data;
    struct Node *next;
};

//// diplay the list

void diplayList(struct Node *head)
{

    if (head == NULL)
    {
        printf("List is an underflow condition!\n");
    }
    else
    {
        printf("\n-----------------List----------------------\n");
        while (head != NULL)
        {

            printf("%d->", head->data);
            head = head->next;
        }
        printf("\n--------------------  -------------------\n");
    }
}

// function for creating node
struct Node *create_node(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
// fuction for inserting node at beginning

struct Node *insertAtStart(struct Node *head, int data)
{

    // checking a list is not present

    if (head == NULL)
    {
        struct Node *newnode = create_node(data);
        head = newnode;
        printf("list is created....\n");
    }
    else
    {
        struct Node *newnode = create_node(data);
        newnode->next = head;
        head = newnode;
        printf("Node insted at the Start..\n");
    }

    return head;
}

// insert the node at the last

struct Node *insertAtEnd(struct Node *head, int data)
{

    while (head != NULL)
    {

        if (head->next->next == NULL)
        {
            struct Node *newnode = create_node(data);
            head->next->next = newnode;
            printf("node inserted at end..\n");
            break;
        }

        head = head->next;
    }

    return head;
}

// delte node from the given position

struct Node *delete_node_from_list(struct Node *head, int position)
{

    // if position is staringing positon

    if (position == 0)
    {
        head = head->next;
        printf("node deleted...\n");
        return head;
    }
    else
    {
        /// if position if another expect 0 th position
        int count = 0;
        while (head != NULL)
        {
            if (count + 1 == position)
            {
                head->next = head->next->next;
                printf("node deleted...\n");
                break;
            }
        }
        return head;
    }

    return head;
}

// function to make a reverce a list
void rev_list(struct Node *head)
{

    ///
    if (head == NULL)
        return;

    struct Node *temp, *newlisthead = NULL;

    while (head != NULL)
    {

        if (newlisthead == NULL)
        {
            newlisthead = head;
            newlisthead->next = NULL;
        }
        else
        {

            temp = head;
            head = head->next;
            temp->next = newlisthead;
            newlisthead = temp;
        }
        head = head->next;
    }
}

int main()
{

    struct Node *head = NULL;

    // user driven loop

    do
    {

        printf("1.Insert Node at the start\n");
        printf("2.Insert Node at the End\n");
        printf("3.delete Node \n");
        printf("4.diplay list\n");

        printf("Enter Choice:\n");
        int choice;
        scanf("%d", &choice);

        int ele;
        switch (choice)
        {
        case 1:
            printf("\nEnter Data for node :");
            scanf("%d", &ele);
            head = insertAtStart(head, ele);
            diplayList(head);
            break;
        case 2:
            printf("Enter Data for node :\n");
            scanf("%d", &ele);
            head = insertAtEnd(head, ele);
            diplayList(head);
            break;
        case 3:
            printf("Enter Position for delete :\n");
            scanf("%d", &ele);
            head = delete_node_from_list(head, ele);
            diplayList(head);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }

    } while (11);

    return 0;
}