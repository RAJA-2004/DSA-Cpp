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

void solve(Node* root,vector<string>& path,string str){
    if(root == NULL) return;
    str.append(to_string(root->data));
    if(root->left == NULL && root->right == NULL){
        path.push_back(str);
        return;
    }
    str+=" ";
    solve(root->left,path,str);
    solve(root->right,path,str);
}

vector<string> rootToLeaf(Node* root){
    vector<string> path;
    string str="";
    solve(root,path,str);
    return path;
}

int main(){
    Node* root = createTree();
    vector<string> ans = rootToLeaf(root);
    for(auto val : ans){
        cout << val << endl;
    }
    return 0;
}