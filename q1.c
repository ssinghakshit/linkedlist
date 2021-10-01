#include <stdio.h>
#include <stdlib.h>

//hello noobs
struct node
{
    int data_20051716;
    struct node *next_20051716;
};
void insert(struct node **h_20051716, int d_20051716, int pos_20051716)
{
    struct node *cur_20051716, *ptr_20051716;
    cur_20051716 = malloc(sizeof(struct node));
    cur_20051716->next_20051716 = NULL;
    cur_20051716->data_20051716 = d_20051716;
    if (*h_20051716 == NULL)
    {
        *h_20051716 = cur_20051716;
    }
    else if (pos_20051716 == 0)
    {
        cur_20051716->next_20051716 = *h_20051716;
        *h_20051716 = cur_20051716;
    }
    else
    {
        ptr_20051716 = *h_20051716;
        int i_20051716 = 0;
        while (ptr_20051716->next_20051716 != NULL && i_20051716 < pos_20051716 - 1)
        {
            i_20051716++;
            ptr_20051716 = ptr_20051716->next_20051716;
        }
        cur_20051716->next_20051716 = ptr_20051716->next_20051716;
        ptr_20051716->next_20051716 = cur_20051716;
    }
}
void deletedup(struct node **h_20051716)
{
    struct node *ptr1_20051716, *ptr2_20051716, *prev_20051716, *dup_20051716;
    ptr1_20051716 = prev_20051716 = dup_20051716 = *h_20051716;
    while (ptr1_20051716 != NULL && ptr1_20051716->next_20051716 != NULL)
    {
        prev_20051716 = ptr1_20051716;
        ptr2_20051716 = ptr1_20051716->next_20051716;
        while (ptr2_20051716 != NULL)
        {
            dup_20051716 = ptr2_20051716->next_20051716;
            if (ptr1_20051716->data_20051716 == ptr2_20051716->data_20051716)
            {
                prev_20051716->next_20051716 = ptr2_20051716->next_20051716;
                free(ptr2_20051716);
            }
            else
            {
                prev_20051716 = ptr2_20051716;
            }
            ptr2_20051716 = dup_20051716;
        }
        ptr1_20051716 = ptr1_20051716->next_20051716;
    }
}
void display(struct node *h_20051716)
{
    for (; h_20051716 != NULL; h_20051716 = h_20051716->next_20051716)
    {
        printf("%d-", h_20051716->data_20051716);
    }
    printf("\n");
}
int main()
{
    struct node *head_20051716 = NULL;
    int n_20051716 = 7;
    for (int i_20051716 = 0; i_20051716 < n_20051716; i_20051716++)
    {
        insert(&head_20051716, rand() % 5, i_20051716);
    }
    printf("List elements: ");
    display(head_20051716);
    deletedup(&head_20051716);
    printf("List elements after removing duplicates: ");
    display(head_20051716);
}
