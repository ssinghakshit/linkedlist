#include <stdio.h>
#include <stdlib.h>
//hello bot
struct node
{
    int data;
    struct node *link;
} * start, *end;

void create(int data)
{
    struct node *temp, *q;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (start == NULL)
    {
        end = start = temp;
    }
    else
    {
        end->link = temp;
        end = temp;
    }
}
void display()
{
    struct node *temp;
    temp = start;
    if (temp == NULL)
    {
        printf("node is empty : ");
    }
    else
    {
        while (temp->link != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d ", temp->data);
    }
    printf("\n\n");
    return;
}

void insert(int add)
{
    struct node *temp, *q, *temp2;
    int data, i;
    temp2 = start;
    temp = (struct node *)malloc(sizeof(struct node));
    printf(" enter your data : ");
    scanf("%d", &data);
    temp->data = data;
    if (add == 1)
    {
        temp->link = start;
        start = temp;
    }
    else if (add != 1)
    {
        for (i = 1; i <= add - 1; i++)
        {
            q = temp2;
            temp2 = temp2->link;
        }
        if (temp2->link != NULL)
        {
            q->link = temp;
            temp->link = temp2;
        }
        else
        {
            temp->link = NULL;
            temp2->link = temp;
        }
    }
}

void menu()
{
    printf("1. Create linked list\n");
    printf("2. Insert at the beginning\n");
    printf("3. Insert at the end\n");
    printf("4. Insert at specific location\n");
    printf("5. Display the linked list\n");
    printf("6. Exit\n");

    printf("Select option: ");
    int menuSelection;
    scanf("%d", &menuSelection);
    switch (menuSelection)
    {
    case 1:
    {
        system("CLS");
        start = end = NULL;
        int i, data, n;
        printf("how many node you want to create : ");
        scanf("%d", &n);
        printf("enter node data : ");
        for (i = 1; i <= n; i++)
        {
            scanf("%d", &data);
            create(data);
        }
        printf("Linked list created\n");
        break;
    }
    case 2:
    {
        system("CLS");
        insert(1);
        printf("Node added at the beginning\n");
        break;
    }
    case 3:
    {
        system("CLS");
        struct node *new;
        int data;
        printf(" enter your data : ");
        scanf("%d", &data);
        new = (struct node *)malloc(sizeof(struct node));
        new->data = data;
        end->link = new;
        new->link = NULL;
        break;
    }
    case 4:
    {
        system("CLS");
        int add;
        printf("In which position you want to add another node : ");
        scanf("%d", &add);
        insert(add);
        printf("Node added in position %d\n", add);
        break;
    }
    case 5:
    {
        system("CLS");
        printf("displaying all nodes : ");
        display();
        break;
    }
    case 6:
    {
        system("CLS");
        return;
    }
    default:
    {
        system("CLS");
        printf("Wrong selection...\n\n");
    }
    }
    menu();
}

int main()
{
    system("CLS");
    menu();
    return 0;
}
