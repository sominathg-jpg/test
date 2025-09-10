#include <stdio.h>
#include <stdlib.h>
// node for the graph

// suppose the three is already have exist
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// function for creating a node

struct Node *create_Node(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function for inorder traversal

void inorderTraversal(struct Node *root)
{

    if (root == NULL)
        return;

    inorderTraversal(root->left);
    printf("%d", root->data);
    inorderTraversal(root->right);
}

// pre order traveral

void preOrderTraversal(struct Node *root)
{

    if (root == NULL)
        return;

    printf("%d", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// post order travesal

void postOrderTraversal(struct Node *root)
{

    if (root == NULL)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d", root->data);
}

struct Node *Insert(struct Node *root, int ele)
{
}
int main()
{

    /*


const root = new Node(5);
root.left = new Node(3);
root.right = new Node(7);

root.left.left = new Node(2);
root.left.right = new Node(4);

root.right.left = new Node(6);
root.right.right = new Node(8);
    */

    struct Node *n1 = create_Node(5);
    n1->left = create_Node(3);
    n1->right = create_Node(7);
    n1->left->left = create_Node(2);
    n1->left->right = create_Node(4);
    n1->right->left = create_Node(6);
    n1->right->right = create_Node(8);

    printf("\n inorder travesal\n");
    inorderTraversal(n1);
    printf("\n");
    printf("pre order \n");
    preOrderTraversal(n1);
    // post order
    printf("\npost order\n");
    postOrderTraversal(n1);
    return 0;
}