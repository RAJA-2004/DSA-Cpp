#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left = NULL;
        right = NULL;
    }
};

Node* bst(Node* root,int key){
    if(root == NULL){
        Node* temp = new Node(key);
        return root;
    }
    if(key > root->data){
        root->right = bst(root->right,key);
    }
    else{
        root->left = bst(root->left,key);
    }
    return root;
}


void convertBstToSortedLL(Node* root,Node* &head){
    if(root == NULL) return;

    // ! right will act as next pointer
    // ! left will act as prev pointer 

    // right subtree converted into a DLL
    convertBstToSortedLL(root->right,head);
    // connected next pointer to head
    root->right = head;
    // connexted prev pointer to head
    if(head != NULL){
        head->left = root;
    }

    // update head
    head = root;

    // left subtree converted into a DLL
    convertBstToSortedLL(root->left,head);
}

void display(Node* &head){
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp=temp->right;
    }
    cout << endl;
}

void lvl(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
}

Node* create(){
    int data;
    cout << "enter data : ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = create();
    root->right = create();
    return root;
}

int main(){
    Node* root = NULL;
    root = create();
    Node* head = NULL;
    convertBstToSortedLL(root,head);
    display(head);
    return 0;
}