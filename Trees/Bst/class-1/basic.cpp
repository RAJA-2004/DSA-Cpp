#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <set>
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

// ! inorder of BST is always SORTED

Node* bst(Node* root,int key){
    if(root == NULL){
        root = new Node(key);
        return root;
    }
    if(root->data > key){
        root->left = bst(root->left,key);
    }
    else{ 
        root->right = bst(root->right,key);
    }
    return root;
}

void pre(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            cout << temp->data << " ";
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}


int main(){
    Node* root = NULL;
    vector<int> arr{100,90,80,95,200,150,250};
    for(int i=0;i<arr.size();i++){
        root = bst(root,arr[i]);
    }
    pre(root);
    return 0;
}