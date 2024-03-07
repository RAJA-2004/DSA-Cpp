
// time complexity (without map) : O(n^2)
// time complexity (with map)    : O(n)

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

Node* solve(vector<int>& postorder,int poststart,int postend,vector<int>& inorder,int instart,int inend,map<int,int>& mp){
    // base case
    if(poststart > postend || instart > inend) return NULL;

    int element = postorder[postend];
    Node* root = new Node(element);
    int pos = mp[element];
    int left = pos - instart;

    // ! right call first bcz element is found to the right in inorder array
    // ! since postorder is -> L R P -> and we are coming backwards first creating root -> right -> left
    
    root->right = solve(postorder,poststart+left,postend-1,inorder,pos+1,inend,mp);
    root->left = solve(postorder,poststart,poststart+left-1,inorder,instart,pos-1,mp);

    return root;
}

Node* b(vector<int>& postorder,vector<int>& inorder){
    int poststart = 0;
    int postend = postorder.size()-1;
    int instart = 0;
    int inend = inorder.size()-1;
    map<int,int> mp;
    for(int i=0;i<inorder.size();i++){
        mp[inorder[i]] = i;
    }

    return solve(postorder,poststart,postend,inorder,instart,inend,mp);
}

void preO(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preO(root->left);
    preO(root->right);
}

int main(){
    vector<int> inOrder{40,20,10,50,30,60};

    // root always be the last element
    vector<int> postOrder{40,20,50,60,30,10};
    Node* root = b(postOrder,inOrder);
    preO(root);
    return 0;
}