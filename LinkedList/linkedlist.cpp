#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int data;
    struct node *link;
};

// in this code we have to return the head after updating becuase in the main function we have not pass th
// head by reference that's the reaon we have to d this .
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
}
// in this we have take the the head as a pass by reference nad now if we change ade in head the change will
// reflect in the main head of the main function. for that we dont need to return the head and now we have to pass the head address like (&head).
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

void Insert_End(struct node *head, int data)
{
    struct node *ptr = head;

    if (ptr == NULL)
    {
        cout << "linkedlist is empty";
    }
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
}

void Delete_end(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    while (ptr->link->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = NULL;
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

    cout << endl;
    Print_node(head);
    cout << endl;
    Delete_end(head);
    Delete_end(head);
    Delete_end(head);
    Print_node(head);

    return 0;
}