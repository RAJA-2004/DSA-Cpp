
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

int find(vector<int>& inOrder,int element){
    for(int i=0;i<inOrder.size();i++){
        if(element == inOrder[i]){
            return i;
        }
    }
    return -1;
}

// !important
// index of preOstart has to be passed by refrence 

Node* solve(vector<int>& preOrder,vector<int>& inOrder,int inOStart,int inOend,int& preOstart){
    if(inOStart > inOrder.size() || preOstart >= preOrder.size()){
        return NULL;
    }
    int element = preOrder[preOstart++];
    Node* root = new Node(element);
    int pos = find(inOrder,element);
    
    // make tree in left part
    root->left = solve(preOrder,inOrder,inOStart,pos-1,preOstart);
    // make tree in right part
    root->right = solve(preOrder,inOrder,pos+1,inOend,preOstart);
    return root;
}

void preO(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preO(root->left);
    preO(root->right);
}

int main(){
    // Node* root = createTree();
    // preOrder decides the root node
    vector<int> preOrder{5,1,3,4,2};
    // values to left of root inside inOrder will form left subtree
    vector<int> inOrder{3,1,4,5,2};

    int inOstart = 0;
    int inOend = inOrder.size()-1;
    int preOstart = 0;
    Node* root = solve(preOrder,inOrder,inOstart,inOend,preOstart);
    preO(root);
    return 0;
}