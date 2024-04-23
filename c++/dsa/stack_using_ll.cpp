#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
struct node* top=nullptr;

void push(int val){
    node* newnode=new node;
    newnode->data=val;
    newnode->next = top;
    top=newnode;
    
}

void pop(){
    cout<<top->data;
    top=top->next;
}

void display(){
    cout<<"display";
    node* temp=top;
    while(temp!=nullptr){
        cout<<temp->data;
        temp=temp->next;
    }
}

int main(){
    int c,val;
    while(1){
        cout<<"push"<<endl;
        cout<<"pop"<<endl;
        cout<<"display"<<endl;
        cout<<"enter the choice";
        cin>>c;
        switch(c){
            case 1:{
                cout<<"enter the data";
                cin>>val;
                push(val);
                break;
            }
            case 2:{
                pop();
                break;
            }
            case 3:{
                display();
                break;
            }
            case 4:{
            exit(0);
            break;
            }
            default:
            {
                cout<<"enter the correct choice";
                break;
            }
            
        }
    }
    return 0;
}