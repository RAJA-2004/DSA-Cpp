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

vector<int> topview(Node* root){
    vector<int> ans;
    queue<pair<Node*,int>> q;
    // map bcz to get sorted lines
    map<int,int> mp;
    q.push({root,0});
    while(!q.empty()){
        auto p = q.front();
        q.pop();

        Node* temp = p.first;
        int line = p.second;
        if(mp.find(line)==mp.end()) mp[line]=temp->data;

        if(temp->left){
            int new_line = line - 1;
            q.push({temp->left,new_line});
        }

        if(temp->right){
            int new_line = line + 1;
            q.push({temp->right,new_line});
        }
    }

    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

int main(){
    Node* root = createTree();
    vector<int> ans = topview(root);
    for(auto val : ans){
        cout << val << " ";
    }
    return 0;
}