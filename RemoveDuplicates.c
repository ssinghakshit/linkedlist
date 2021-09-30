
#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

void push(struct Node **head_ref, int new_data)
{
    struct Node *new_node =
        (struct Node *)malloc(sizeof(struct Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void removeDuplicates(struct Node *start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;
        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
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
    struct Node *start = NULL;
    while (1)
    {
        printf("1. Create linked list\n");
        printf("2. Display\n");
        printf("3. Remove duplicate\n");
        printf("4. Exit\n");

        printf("Select option: ");
        int menuSelection;
        scanf("%d", &menuSelection);
        switch (menuSelection)
        {
        case 1:
        {
            //system("CLS");
            int i, data, n;
            printf("how many node you want to create : ");
            scanf("%d", &n);
            printf("enter node data : ");
            for (i = 1; i <= n; i++)
            {
                scanf("%d", &data);
                push(&start, data);
            }
            printf("Linked list created\n");
            break;
        }
        case 2:
        {
            //system("CLS");
            printList(start);
            break;
        }
        case 3:
        {
            //system("CLS");
            removeDuplicates(start);
            break;
        }
        case 4:
        {
            //system("CLS");
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
