#include<iostream>
#include<stdlib.h>
using namespace std;

 struct node
    {
       int data;
       struct node *link;
    };
    void Print_node(struct node *head){
        struct node *ptr=head;
        if(ptr==NULL){
            cout<<"Linkedlist is empty";

        }
        while(ptr!=NULL){
            cout<<ptr->data<<"  ";
            ptr=ptr->link;

        }
    }
    void Insert_End(struct node *head,int data){
             struct node *ptr=head;

             if(ptr==NULL){
                cout<<"linkedlist is empty";

             }
             while(ptr->link!=NULL){
                ptr=ptr->link;
             }
             struct node *temp=(struct node*)malloc(sizeof(struct node));
             temp->data=data;
             temp->link=NULL;
             ptr->link=temp;

    }

int main(){

    struct node *head=(struct node*)malloc(sizeof(struct node));
    head->data=40;
    head->link=NULL;

    struct node *current=(struct node*)malloc(sizeof(struct node));
    current->data=50;
    current->link=NULL;
    head->link=current;

    current=(struct node*)malloc(sizeof(struct node));
     current->data=50;
     current->link=NULL;
     head->link->link=current;
    
Print_node(head);
Insert_End(head,70);
Insert_End(head,56);
Insert_End(head,80);
Insert_End(head,110);
cout<<endl;
Print_node(head);
  return 0;
}