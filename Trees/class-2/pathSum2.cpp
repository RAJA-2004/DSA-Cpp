#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
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

void solve(Node* root, int targetSum,vector<vector<int>>& ans,vector<int> path,int currSum){
    // base case
    if(root == NULL) return;
    // leaf node -> check sum and store
    if(root->left == NULL && root->right == NULL){
        // add leaf node also
        currSum += root->data;
        path.push_back(root->data);
        if(currSum == targetSum){
            ans.push_back(path);
        }
        return;
    }
    currSum += root->data;
    path.push_back(root->data);
    solve(root->left,targetSum,ans,path,currSum);
    solve(root->right,targetSum,ans,path,currSum);
}

vector<vector<int>> pathSum(Node* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> path;
    int currSum = 0;
    solve(root,targetSum,ans,path,currSum);
    return ans;
}

int main(){
    Node* root = createTree();
    int targetSum = 22;
    vector<vector<int> > ans = pathSum(root,targetSum);
    for(auto val : ans){
        for(auto vals : val){
            cout << vals << " ";
        }
        cout << endl;
    }
    return 0;
}