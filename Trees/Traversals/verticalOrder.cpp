#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <map>
using namespace std;

// time complexity : O(n)
// space complexity : O(n)
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
    // multiset bcz we can have duplicate values as well
    map<int,map<int,multiset<int>>> nodes;
    
    queue<pair<Node*,pair<int,int>>> todo;
    // push root
    todo.push({root,{0,0}});

    // level order steps
    while(!todo.empty()){
        auto p = todo.front();
        todo.pop();

        Node* temp = p.first;
        int vertical_order = p.second.first;
        int lvl = p.second.second;

        nodes[vertical_order][lvl].insert(temp->data);

        if(temp->left){
            int vertical = vertical_order-1;
            int level = lvl+1;
            todo.push({temp->left,{vertical,level}});
        }

        if(temp->right){
            int vertical = vertical_order+1;
            int level = lvl+1;
            todo.push({temp->right,{vertical,level}});
        }
    }

    vector<vector<int>> ans;
    for(auto p : nodes){
        vector<int> col;
        // p.second -> map<int,multiset<int>>
        for(auto q : p.second){
            // insets all the data of the multiset into the vector
            // to the end from starting of the multiset till end
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