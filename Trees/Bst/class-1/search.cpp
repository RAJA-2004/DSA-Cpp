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

void search(Node* root,int target){
    if(root == NULL){
        cout << "not found" << endl;
        return;
    }
    if(root->data == target){
        cout << "found" << endl;
    }
    else if(root->data < target){
        search(root->right,target);
    }
    else{
        search(root->left,target);
    }
}

int main(){
    Node* root = NULL;
    vector<int> arr{100,90,80,95,200,150,250};
    for(int i=0;i<arr.size();i++){
        root = bst(root,arr[i]);
    }
    int target = 300;
    search(root,target);
    return 0;
}