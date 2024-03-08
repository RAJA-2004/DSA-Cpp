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

// Node* search(Node* root,int key){
//     if(root == NULL) return NULL;
//     if(root->data > key){
//         return search(root->left,key);
//     }
//     else{
//         return search(root->right,key);
//     }
//     return root;
// }

// void inorder(Node* root,vector<int>& ans){
//     if(root == NULL) return;
//     inorder(root->left,ans);
//     ans.push_back(root->data);
//     inorder(root->right,ans);
// }

// int maxVal(Node* root){
//     vector<int> ans;
//     inorder(root,ans);
//     return ans[ans.size()-1];
// }

// Node* deleteNode(Node* root,int key){
//     if(root == NULL) return NULL;
//     if(root->data == key){
//         if(root->left == NULL && root->right == NULL) return NULL;
//         else if(root->left == NULL && root->right != NULL) return root->right;
//         else if(root->left != NULL && root->right == NULL) return root->left;
//         else{
//             int maxi = maxVal(root->left);
//             root->data = maxi;
//             root->left = deleteNode(root->left,maxi);
//             return root;
//         } 
//     }
//     else if(root->data > key){
//         root->left = deleteNode(root->left,key);
//     }
//     else{
//         root->right = deleteNode(root->right,key);
//     }
//     return root;
// }

void inorder(Node* root,vector<int>& ans){
    if(root == NULL) return;
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}

int maxVal(Node* root){
    vector<int> ans;
    inorder(root,ans);
    return ans[ans.size()-1];
}

Node* deleteNode(Node* root,int key){
    if(root == NULL) return NULL;
    if(root->data == key){
        if(!root->left && !root->right) return NULL;
        else if(root->left == NULL && root->right != NULL) return root->right;
        else if(root->left != NULL && root->right == NULL) return root->left;
        else{
            int maxi = maxVal(root->left);
            root->data = maxi;
            root->left = deleteNode(root->left,maxi);
        }
    }
    else if(key > root->data){
        root->right = deleteNode(root->right,key);
    }
    else{
        root->left = deleteNode(root->left,key);
    }
    return root;
}

void lvl(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        // store queue front in temp
        Node* temp = q.front();

        // pop the node
        q.pop();

        // separating the levels
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            // print data
            cout << temp->data << " ";

            // insert child
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
    int target = 95;
    root = deleteNode(root,target);
    lvl(root);
    return 0;
}