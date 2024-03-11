
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

pair<int,int> twosum(vector<int>& ans,int target){
    pair<int,int> res;
    int i = 0;
    int j = ans.size()-1;
    while(i<j){
        if((ans[i]+ans[j])==target){
            res.first = ans[i];
            res.second = ans[j];
            break;
        }
        else if(target > (ans[i]+ans[j])){
            i++;
        }
        else{
            j--;
        }
    }
    return res;
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
    int target;
    cout << endl << "enter target : ";
    cin >> target;
    pair<int,int> res = twosum(ans,target);
    cout << res.first << " " << res.second << endl;
}


int main(){
    create();
    return 0;
}