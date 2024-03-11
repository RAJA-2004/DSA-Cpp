
// ! time complexity = O(n)

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

// ! catch is k is to be passed by refrence

int kthSmallest(Node* root,int& k){
    if(root==NULL) return -1;
    int leftAns = kthSmallest(root->left,k);
    if(leftAns!=-1){
        return leftAns;
    }
    k--;
    if(k==0){
        return root->data;
    }
    int rightAns = kthSmallest(root->right,k);
    return rightAns;
}

void solve(Node* root,vector<int>& ans){
    if(root==NULL) return;
    solve(root->left,ans);
    cout << root->data << " ";
    ans.push_back(root->data);
    solve(root->right,ans);
}

void create(){
    Node* root = NULL;
    while(true){
        int key;
        cin >> key;
        if(key==-1) break;
        root = bst(root,key);
    }
    vector<int> ans;
    solve(root,ans);
    int element;
    cout << endl << "enter the kth element : ";
    cin >> element;
    // cout << endl << element << " element is " << ans[element+1] << endl;
    cout << endl << element << " element is " << kthSmallest(root,element) << endl;
}


int main(){
    create();
    return 0;
}