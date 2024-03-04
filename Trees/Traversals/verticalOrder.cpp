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

vector<vector<int> > vertical(Node* root){
    map<int,map<int,multiset<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> todo;
    // push root
    todo.push({root,{0,0}});
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();
        Node* temp = p.first;
        int x = p.second.first;
        int y = p.second.second;
        nodes[x][y].insert(temp->data);

        if(temp->left){
            int vertical = x-1;
            int level = y+1;
            todo.push({temp->left,{vertical,level}});
        }

        if(temp->right){
            int vertical = x+1;
            int level = y+1;
            todo.push({temp->right,{vertical,level}});
        }
    }

    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        for(auto q : p.second){
            col.insert(col.end(),q.second.begin(),q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int main(){
    Node* root = createTree();
    vector<vector<int> > ans = vertical(root);
    for(auto vals : ans){
        for(auto val : vals){
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}

    //                     10(0,0)
    //                   /         \ 
    //           20(-1,1)           50(1,1) 
    //           /      \           /      \ 
    //    30(-2,2)      40(0,2) 60(0,2)    70(2,2)

    // 30 20 10 40 60 50 70