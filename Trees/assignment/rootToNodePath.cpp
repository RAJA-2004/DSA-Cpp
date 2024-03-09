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

bool solve(Node* root,vector<int>& path,int key){
    if(root == NULL) return false;
    path.push_back(root->data);
    if(root->data == key) return true;
    if(solve(root->left,path,key) || solve(root->right,path,key)){
        return true;
    }
    path.pop_back();
    return false;
}

vector<int> rootToNode(Node* root,int key){
    vector<int> path;
    if(root == NULL) return path;
    solve(root,path,key);
    return path;
}

int main(){
    Node* root = createTree();
    int key = 7;
    vector<int> ans = rootToNode(root,key);
    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}