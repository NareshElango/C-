#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    node *right,*left;
};

node *create(int val){
    node *newnode=new node;
    newnode->data=val;
    newnode->right=nullptr;
    newnode->left=nullptr;
    return newnode;
}

node *insert(node *root,int val){
    if(root==nullptr)
    return create(val);

    if(val<root->data){
        root->left=insert(root->left,val);
    }
    else{
        root->right=insert(root->right,val);
    }
    return root;
}

void inorderTraversal(node* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}
node* findMin(node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

node* deleteNode(node* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            node* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    int n;
    cout<<"enter the n";
    cin>>n;
    node *root=nullptr;
    for(int i=0;i<n;i++){
        int v;
        cin>>v;
        root = insert(root,v);
    }

    cout<<"inorder traversal"<<endl;
    inorderTraversal(root);
    int key;
    cout<<"enter the key";
    cin>>key;
    deleteNode(root,key);
    cout<<"inorder traversal"<<endl;
    inorderTraversal(root);
}