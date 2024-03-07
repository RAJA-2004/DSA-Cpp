
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

// int find(vector<int>& inOrder,int element){
//     for(int i=0;i<inOrder.size();i++){
//         if(element == inOrder[i]){
//             return i;
//         }
//     }
//     return -1;
// }

// !important
// index of preOstart has to be passed by refrence 

Node* solve(vector<int>& preOrder,vector<int>& inOrder,int inOstart,int inOend,int preOstart,int preOend,unordered_map<int,int>& mp){
    // base case
    if(preOstart > preOend || inOstart > inOend) return NULL;

    int element = preOrder[preOstart];
    Node* root = new Node(element);
    int pos = mp[root->data];
    int numsLeft = pos - inOstart;

    root->left = solve(preOrder,inOrder,inOstart,pos-1,preOstart+1,preOend+numsLeft,mp);
    root->right = solve(preOrder,inOrder,pos+1,inOend,preOstart+numsLeft+1,preOend,mp);
    return root;
}

Node* b(vector<int>& preOrder,vector<int>& inOrder){
    int preOstart = 0;
    int preOend = preOrder.size()-1;
    int inOstart = 0;
    int inOend = inOrder.size()-1;
    unordered_map<int,int> mp;
    for(int i=0;i<preOrder.size();i++){
        mp[preOrder[i]] = i;
    }
    return solve(preOrder,inOrder,inOstart,inOend,preOstart,preOend,mp);
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
    vector<int> preOrder{3,9,20,15,7};
    // values to left of root inside inOrder will form left subtree
    vector<int> inOrder{9,3,15,20,7};

    Node* root = b(preOrder,inOrder);
    preO(root);
    return 0;
}