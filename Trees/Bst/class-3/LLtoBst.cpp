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

Node* sortedLLtoBst(Node* &head,int n){
    if(head == NULL || n<=0){
        return NULL;
    }
    // creating left subtree
    Node* leftSubTree = sortedLLtoBst(head,n/2);
    Node* root = head;
    head = head->right;
    root->right = sortedLLtoBst(head,(n/2)-1);
    return root;
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
    root = sortedLLtoBst(head,7);
    lvl(root);
    return 0;
}