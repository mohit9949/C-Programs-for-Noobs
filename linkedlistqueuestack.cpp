#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *next;
};
void insertfirstNode(struct Node *head,int data){
    head->data=data;
    head->next=NULL;
}

void push(struct Node **head,int data){
    Node *temp=new Node;
    temp->data=data;
    temp->next=NULL;
    Node *cur=*head;
    while(cur){
        if(cur->next==NULL){
            cur->next=temp;
            return;
        }
        cur=cur->next;
    }
}
static void pop(struct Node **head){
    Node *cur=*head;
    Node *fast=cur->next;
    Node *slow=cur;
    while(fast->next!=NULL){
        slow=fast;
        fast=fast->next;
    }
    slow->next=NULL;
    delete fast;
}
int top(struct Node *head){
    return head->data;
}
void Enqueue(struct Node **head,int data){
    Node *temp=new Node;
    temp->data=data;
    temp->next=*head;
    *head=temp;
}
static void Dequeue(struct Node **head){
    Node *cur=*head;
    Node *fast=cur->next;
    Node *slow=cur;
    while(fast->next!=NULL){
        slow=fast;
        fast=fast->next;
    }
    slow->next=NULL;
    delete fast;
}

int Front(struct Node *head){
    Node *cur=head;
    while (cur){
       cur=cur->next;
    }
    return cur->data;
}
void middleElement(struct Node *head){
    Node *mid=head;
    Node *cur=head;
    int count=0;
    if(head!=NULL){
        while(cur!=NULL && cur->next!=NULL){
            cur=cur->next->next;
            mid=mid->next;
        }
        cout<<mid->data<<endl;
    }
}
void display(struct Node *head){
    Node *cur=head;
    while(cur){
        cout<<cur->data<<"->";
        cur=cur->next;
    }
    cout<<endl;
}
static void reverse(struct Node **head){
    Node *prev=NULL;
    Node *cur=*head;
    Node *next;
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    *head=prev;
}
static void removeElement(struct Node **head,int data){
    Node *cur=*head;
    Node *temp=*head;
    while(cur->data!=data && cur->next!=NULL){
        //cout<<cur->data<<"->"<<data<<endl;
        temp=cur;
        cur=cur->next;
    }
    if(cur->data==data){
        if(cur==*head){
            //cur=head;
            Node *temp=cur;
            cur=cur->next;
            *head=cur;
            delete temp;
        }
        else{
        temp->next=cur->next;
        cur->next=NULL;
        delete cur;
            
        }
    }
    else{
       cout<<"There is no such data:"<<data<<" in the linked list. :("<<endl;
    }
}

int main() {
	// your code goes here
	struct Node *head=new Node;
	insertfirstNode(head,1);
	push(&head,2);
	push(&head,3);
	push(&head,4);
	push(&head,5);
	push(&head,6);
	push(&head,7);
	push(&head,8);
	push(&head,9);
	push(&head,10);
	display(head);
    //Enqueue(head,0);
	//display(head);
    pop(&head);
	display(head);
	//Dequeue(&head);
	//display(head);
	//middleElement(head);
	//removeElement(&head,5);
	//display(head);
	//reverse(&head);
	//display(head);
	return 0;
}