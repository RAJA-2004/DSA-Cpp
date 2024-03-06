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

void solve(Node* root,vector<int>& ans,int level){
    if(root == NULL) return;
    if(ans.size() == level) ans.push_back(root->data);
    solve(root->left,ans,level+1);
    solve(root->right,ans,level+1);
}

vector<int> rightview(Node* root){
    vector<int> ans;
    int level = 0;
    solve(root,ans,level);
    return ans;
}

int main(){
    Node* root = createTree();
    vector<int> ans = rightview(root);
    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}