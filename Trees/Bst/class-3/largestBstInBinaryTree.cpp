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
    return 0;
}