#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node *next;
};

node *head=nullptr;

void display() {
    if (head == nullptr) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    while (temp->next != head) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

void create(){
    int n;
    cout<<"enter the number of nodes";
    cin>>n;
    for(int i=0;i<n;i++){
        node *newnode=new node;
        int val;
        cout<<"Enter the value: ";
        cin>>val;
        newnode->data=val;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
            head->next=head;
        }
        else{
            node *temp=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
        }
        
    }
    display();
}

void ins_beg(){
    node *newnode=new node;
    node *temp=head;
    cout<<"enter the data";
    cin>>newnode->data;
    while(temp->next!=head){
        temp=temp->next;
    }
     temp->next=newnode;
    newnode->next=head;
    head=newnode;
    display();
}
void ins_end(){
    node *newnode=new node;
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->next=nullptr;
    node *temp=head;
    node *prev=nullptr;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->next=head;
    display();
}

void del_beg(){
    node *temp=head;
     node *temp1=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next=head->next;
    head=head->next;
    delete temp1;
    display();
}

void del_end(){
    node *temp=head;
    node *prev=nullptr;
    while(temp->next!=head){
        prev=temp;
        temp=temp->next;
    }
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
        newnode->next=nullptr;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        display();
    }
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