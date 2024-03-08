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

Node* lowestCommonAncestor(Node* root,Node* p,Node* q){
        if(root == NULL) return NULL;
        int curr = root->data;
        if(curr < p->data && curr < q->data){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(curr > p->data && curr > q->data){
            return lowestCommonAncestor(root->left,p,q);
        }
        return root;
}

int main(){
    Node* root = NULL;
    vector<int> arr{100,90,80,95,200,150,250};
    for(int i=0;i<arr.size();i++){
        root = bst(root,arr[i]);
    }
    Node* p = new Node(80);
    Node* q = new Node(95);

    Node* ans = lowestCommonAncestor(root,p,q);
    cout << "lowest common ancestor : " << ans->data << endl;

    return 0;
}