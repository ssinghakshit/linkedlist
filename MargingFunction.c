#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void MoveNode(struct Node **head, struct Node **nextRef);

struct Node *SortedMerge(struct Node *a, struct Node *b)
{
    struct Node node;

    struct Node *tail = &node;

    node.next = NULL;
    while (1)
    {
        if (a == NULL)
        {
            tail->next = b;
            break;
        }
        else if (b == NULL)
        {
            tail->next = a;
            break;
        }
        if (a->data <= b->data)
            MoveNode(&(tail->next), &a);
        else
            MoveNode(&(tail->next), &b);

        tail = tail->next;
    }
    return (node.next);
}

void MoveNode(struct Node **node, struct Node **source)
{
    struct Node *newNode = *source;

    *source = newNode->next;

    newNode->next = *node;

    *node = newNode;
}

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void menu()
{
    struct Node *res = NULL;
    struct Node *a = NULL;
    struct Node *b = NULL;
    while (1)
    {
        printf("1. Create linked list A\n");
        printf("2. Create linked list B\n");
        printf("3. Display the linked list A\n");
        printf("4. Display the linked list B\n");
        printf("5. Display the linked list after marge\n");
        printf("5. Exit\n");

        printf("Select option: ");
        int menuSelection;
        scanf("%d", &menuSelection);
        switch (menuSelection)
        {
        case 1:
        {
            //system("CLS");
            int i, n, data;
            printf("how many node you want to create : ");
            scanf("%d", &n);
            printf("enter node data : ");
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &data);
                push(&a, data);
            }
            printf("Linked list created\n");
            break;
        }
        case 2:
        {
            //system("CLS");
            int i, n, data;
            printf("how many node you want to create : ");
            scanf("%d", &n);
            printf("enter node data : ");
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &data);
                push(&b, data);
            }
            printf("Linked list created\n");
            break;
        }
        case 3:
        {
            //system("CLS");
            printList(a);
            break;
        }
        case 4:
        {
            //system("CLS");
            printList(b);
            break;
        }
        case 5:
        {
            //system("CLS");
            res = SortedMerge(a, b);
            printList(res);
            break;
        }
        case 6:
        {
            return;
        }
        default:
        {
            //system("CLS");
            printf("Wrong selection...\n\n");
        }
        }
    }
}

int main()
{
    menu();

    return 0;
}