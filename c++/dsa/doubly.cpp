#include<iostream>
using namespace std;


struct node{
    int data;
    node* prev;
    node* next;
};

struct node* head=NULL;



void display(){
    cout<<"display"<<endl;
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void create(){
    cout<<"enter the number of nodes";
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        node* newnode=new node;
         node* temp=head;
        cout<<"enter the data";
        cin>>newnode->data;
        newnode->next=NULL;
        newnode->prev=NULL;
        
        if(head==NULL){
            head=temp=newnode;
        }
        else{
            node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->prev=temp;
            //temp=newnode;
        }
    }
    display();
}

void ins_beg(){
    cout<<"ins_beg"<<endl;
    node* newnode=new node;
    cout<<"enter the data";
    cin>>newnode->data;
    newnode->prev=NULL;
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    
    display();
}

void ins_end(){
    cout<<"ins_end"<<endl;
     node* temp=head;
    node* newnode=new node;
    cout<<"enter tha data";
    cin>>newnode->data;
    newnode->next=NULL;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    temp=newnode;
    
    display();
}

void del_beg(){
    cout<<"del_beg"<<endl;
     node* temp=head;
     head=head->next;
     delete temp;
     
     display();
}

void del_end(){
    cout<<"del_end"<<endl;
     node* temp=head;
     node* prev=new node;
     while(temp->next!=NULL){
         prev=temp;
         temp=temp->next;
     }
     
     prev->next=NULL;
     delete temp;
     
     display();
     
}

void ins_part(){
    cout<<"ins_part"<<endl;
    node* newnode=new node;
    int pos;
    cout<<"enter the position";
    cin>>pos;
    if(pos==0){
        ins_beg();
        
    }
    else{
        cout<<"enter the data";
        cin>>newnode->data;
         node* temp=head;
        for(int i=1;i<pos;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
    }
    
    display();
}

void del_part(){
    cout<<"del_part"<<endl;
    cout<<"enter the postion"<<endl;
    int pos;
    cin>>pos;
    if(pos==0){
        del_beg();
    }
    else{
         node* temp=head;
         node* prev=new node;
         for(int i=1;i<pos+1;i++){
             prev=temp;
             temp=temp->next;
         }
         prev->next=temp->next;
         temp->next->prev=prev;
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
    return 0;
}