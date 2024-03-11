
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

Node* bstFromInorder(vector<int>& ans,int start,int end){
    if(start > end) return NULL;
    int mid = start + (end - start)/2;
    int element = ans[mid];
    Node* root = new Node(element);
    root->left = bstFromInorder(ans,start,mid-1);
    root->right = bstFromInorder(ans,mid+1,end);
    return root;
}

void lvl(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main(){
    vector<int> inorder{7,8,9,10,11,15,20};
    Node* root = bstFromInorder(inorder,0,inorder.size()-1);
    lvl(root);
    return 0;
}