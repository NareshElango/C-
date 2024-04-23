#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node *next;
};

node *head=nullptr;

void display(){
    cout<<"display the nodes "<<endl;
    node *temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void create(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        node *newnode=new node;
        cout<<"enter the data";
        cin>>newnode->data;
        newnode->next=nullptr;
        if(head==nullptr){
            head=newnode;
        }
        else{
            node *temp=head;
            while(temp->next!=nullptr) temp=temp->next;

            temp->next=newnode;
        }
    }
    display();
}

void ins_beg(){
    node *newnode=new node;
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->next=head;
    head=newnode;
    display();
}

void ins_end(){
    node *newnode=new node;
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->next=nullptr;
    if(head==nullptr){
        head=newnode;
        }
        else {
            node* temp=head;
            while(temp->next != nullptr)
                temp=temp->next;
                temp->next = newnode;
        }

    display();
}

void ins_part(){
    node *newnode=new node;
    int pos;
    cout<<"enter the pos";
    cin>>pos;
    node *prev=nullptr;
    if(pos==0)
    ins_beg();
    else{
        cout<<"enter the data";
        cin>>newnode->data;
        newnode->next=nullptr;
        node *temp=head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    display();
}

void del_beg() {
    if (head == nullptr)
        return;
    else {
        node* temp = head;
        head = head->next;
        delete temp;
        display();
    }
}

void del_end(){
    node *temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=nullptr;
    display();
}

void del_part(){
    int pos;
    cout<<"enter the pos";
    cin>>pos;
    node *temp=head;
    node *last=nullptr;
    if(pos==0)
    del_beg();
    for(int i=1;i<=pos;i++){
        last=temp;
        temp=temp->next;
    }
    last->next=temp->next;
    delete temp;
    display();

}
int main(){
    create();
    ins_beg();
    ins_end();
    ins_part();
    del_beg();
    del_end();
    del_part();
}