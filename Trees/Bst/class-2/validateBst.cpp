
// ! time complexity : O(n)

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

Node* create(){
    int key;
    cin >> key;
    if(key==-1) return NULL;
    Node* root = new Node(key);
    root->left=create();
    root->right=create();
    return root;
}

void solve(Node* root,vector<int>& ans){
    if(root==NULL) return;
    solve(root->left,ans);
    ans.push_back(root->data);
    solve(root->right,ans);
}

bool s(Node* root,long long int lb,long long int up){
    if(root == NULL) return true;
    if(root->data > lb && root->data < up){
        bool left = s(root->left,lb,root->data);
        bool right = s(root->right,root->data,up);
        return (left && right);
    }
    else{
        return false;
    }
}

bool validateBst(Node* root){
    // vector<int> ans;
    // solve(root,ans);
    // for(int i=1;i<ans.size();i++){
    //     if(ans[i-1]>ans[i]) return false;
    // }
    // return true;

    // constraints 10^-31 < x < 10^32;
    // 10^-32 = -4294967296
    // 10^32 = 4294967296

    long long int lowerBound = -4294967296;
    long long int upperBound = 4294967296;
    bool ans = s(root,lowerBound,upperBound);
    return ans;
} 

int main(){
    Node* root = create();
    cout << validateBst(root) << endl;
    return 0;
}