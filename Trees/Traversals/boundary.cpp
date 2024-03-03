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

Node* createTree(){
    int data;
    cout << "enter data : ";
    cin >> data;
    if(data==-1) return NULL;
    Node* root = new Node(data);

    cout << "enter data to left of : " << data << endl;
    root->left = createTree();

    cout << "enter data to right of : " << data << endl;
    root->right = createTree();
    return root;
}

bool isLeaf(Node* root){
    if(root->right == NULL && root->left == NULL) return true;
    else return false;
}

void addLeft(Node* root,vector<int>& ans){
    Node* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) ans.push_back(curr->data);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRight(Node* root,vector<int>& ans){
    vector<int> temp;
    Node* curr = root->right;
    while(curr){
        if(!isLeaf(curr)) temp.push_back(curr->data);
        if(curr->right) curr = curr->right;
        else curr = curr->left;
    }
    for(int i=temp.size()-1;i>=0;i--){
        ans.push_back(temp[i]);
    }
}

void addLeaf(Node* root,vector<int>& ans){
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) addLeaf(root->left,ans);
    if(root->right) addLeaf(root->right,ans);
}

vector<int> boundary(Node* root){
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeft(root,ans);
    addLeaf(root,ans);
    addRight(root,ans);
    return ans;
}


int main(){
    Node* root = createTree();
    vector<int> ans = boundary(root);
    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}