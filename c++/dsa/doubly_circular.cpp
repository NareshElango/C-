#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next,*prev;
};

node *head=nullptr;
void display(){
    cout<<"display"<<endl;
    node *temp=head;
    while(temp->next!=head){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<temp->data<<endl;
}
void create(){
    int n;
    cout<<"enter the no of nodes";
    cin>>n;
    for(int i=0;i<n;i++){
        node *newnode=new node();
        cout<<"Enter the data: ";
        cin>>newnode->data;
        newnode->next=nullptr;
        newnode->prev=nullptr;
        if(head==nullptr){
            head=newnode;
            newnode->next=head;
            newnode->prev=head;
        }
        else{
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            newnode->next=temp->next;
            newnode->prev=temp;
            temp->next=newnode;
        }
       
    }
 display();
}
void ins_beg(){
    node *temp=head;
    node *newnode=new node();
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->next=nullptr;
    newnode->prev=nullptr;
    while(temp->next!=head){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    head=newnode;
    display();
}
void ins_end(){
    node *temp=head;
    node *newnode=new node;
    node *prev=nullptr;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next=newnode;
    display();
}
void del_beg(){
    node *temp=head;
    node *temp1=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = head->next;
    head->next->prev = temp;
    delete temp1;
    head = temp->next;
    display();
}

void del_end(){
    node *temp=head;
    node *prev=nullptr;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    temp->next->prev=prev;
    prev->next=temp->next;
    delete temp;
    display();
}

void ins_part(){
    int pos;
    cout<<"enter the pos";
    cin>>pos;
    if(pos==0)
    ins_beg();
    else{
        node *temp=head;
        node *newnode=new node;
        cout<<"enter the data";
        cin>>newnode->data;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        newnode->prev=temp;
        temp->next=newnode;
        temp=newnode;

    }
    display();
}
void del_part(){
    int pos;
    cout<<"enter the pos";
    cin>>pos;
    if(pos==0)
    del_beg();
    else{
        node *temp=head;
        node *prev=nullptr;
        for(int i=1;i<=pos;i++){
            prev=temp;
            temp=temp->next;
        }
        temp->next->prev=prev;
        prev->next=temp->next;
        delete temp;
    }
    display();
}
int main(){
    create();
    ins_beg();
    ins_end();
    del_beg();
    del_end();
    ins_part();
    del_part();
}