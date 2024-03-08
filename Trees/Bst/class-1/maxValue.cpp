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

void inorder(Node* root,vector<int>& ans){
    if(root == NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int main(){
    Node* root = NULL;
    vector<int> arr{100,90,80,95,200,150,250};
    for(int i=0;i<arr.size();i++){
        root = bst(root,arr[i]);
    }
    vector<int> ans;
    inorder(root,ans);
    cout << "min val : " << ans[ans.size()-1] << endl;
    return 0;
}