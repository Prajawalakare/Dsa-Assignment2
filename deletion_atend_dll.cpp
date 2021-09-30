#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node *prev;
    int data;
    Node *next;
    Node(int data){
        this->data=data;
        prev=NULL;
        next=NULL;
    }
};
void traverForward(Node*node){
    while(node!=NULL){
        cout<<node->data<< " ";
        node=node->next;
    }
    cout<<"\n";
}
void traverBackward(Node *node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->prev;
    }
    cout<<"\n";
}

void deleteAtEnd(Node *&head)
{
    if(head==NULL)
    {
        cout<<"list is empty";
        return;
    }
    else if(head->next==NULL)
    {
        Node *temp=head;
        head=NULL;
        free(temp);
        return;
    }
    else if(head->next->next==NULL)
    {
        Node *temp=head->next;
        head->next=NULL;
        free(temp);
        return;
    }
    Node* tem=head;
    while(tem->next->next!=NULL)
    {
        tem=tem->next;
    }

    Node *temp = tem->next;
    tem->next = NULL;
    free(temp);     
}

int main(){
    Node *head=new Node(10);
    Node *a=new Node(20);
    Node *b=new Node(30);
    Node *c=new Node(40);
    Node *d=new Node(50);
    

    head->next=a;
    a->prev=head;

    a->next=b;
    b->prev=a;

    b->next=c;
    c->prev=b;

    c->next=d;
    d->prev=c;

    cout<<"Before Insertion : ";
    traverForward(head);
    
    deleteAtEnd(head);
    
    cout<<"After Insertion : ";
    traverForward(head);
}