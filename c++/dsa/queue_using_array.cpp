#include<iostream>
using namespace std;

int arr[100],n=100,front=-1,rear=-1;

void insert(){
    
    int val;
    cout<<"enter the val";
    cin>>val;
    if(rear==n-1){
        cout<<"full";
    }
    else{
        if(front==-1){
            front=0;
        }
                    rear++;
            arr[rear]=val;
    }
}

void del(){
    cout<<"delete"<<endl;
    if(front==-1){
        cout<<"empty";
    }
    else if(front==rear){
        front=rear=-1;
    }
    else{
        cout<<arr[front];
        front++;
    }
}

void peek(){
    cout<<arr[front];
}

void display(){
    for(int i=front;i<=rear;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int c;
    while(1){
        cout<<"insert"<<" "<<"delete"<<" "<<"peek"<<" "<<"display";
        cout<<"\n enter the choice";
        cin>>c;
        switch(c){
            case 1:{
                insert();
                break;
            }
            case 2:{
                del();
                break;
            }
            case 3:{
                peek();
                break;
            }
            case 4:{
                display();
                break;
            }
            case 5:{
                exit(0);
                break;
            }
            default:{
                cout<<"enter the correct choice";
                break;
            }
        }
    }
    return 0;
}