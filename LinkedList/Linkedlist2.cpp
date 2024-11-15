#include <iostream>
#include <stdlib.h>

using namespace std;

struct node
{
    int data;
    struct node *link;
};

struct node *Insert_Start(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (head == NULL)
    {
        cout << "linkedlist is empty";
    }
    temp->link = head;
    head = temp;
    return head;
};
void Insert_beg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (head == NULL)
    {
        cout << "linkedlist is empty";
    }
    temp->link = *head;
    *head = temp;
}

void Print_node(struct node *head)
{
    struct node *ptr = head;
    if (ptr == NULL)
    {
        cout << "Linkedlist is empty";
    }
    while (ptr != NULL)
    {
        cout << ptr->data << "  ";
        ptr = ptr->link;
    }
}
void Delete_at_particular(struct node *head, int pos)
{
    if (head == NULL)
    {
        cout << "linkedlist is mepty";
    }
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *ptr2 = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    while (pos != 1)
    {
        pos--;
        ptr2 = ptr;
        ptr = ptr->link;
    }

    ptr2->link = ptr->link;
    free(ptr);
    ptr = NULL;
}
void Insert_At_particular(struct node *head, int data, int pos)
{
    if (head == NULL)
    {
        cout << "linked list is empty";
    };

    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;

    // for (int i = 2; i < pos; i++)
    // {
    //     ptr = ptr->link;
    // }
    // or
    pos--;
    while (pos != 1)
    {
        ptr = ptr->link;
        pos--;
    }

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = ptr->link;
    ptr->link = temp;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 40;
    head->link = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 50;
    current->link = NULL;
    head->link = current;

    current = (struct node *)malloc(sizeof(struct node));
    current->data = 89;
    current->link = NULL;
    head->link->link = current;

    Print_node(head);

    head = Insert_Start(head, 11);
    Insert_beg(&head, 22);
    Insert_At_particular(head, 5, 4);
    Delete_at_particular(head, 4);
    Delete_at_particular(head, 2);

    cout << endl;
    Print_node(head);

    return 0;
}