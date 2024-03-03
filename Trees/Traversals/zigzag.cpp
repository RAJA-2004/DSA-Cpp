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

vector<vector<int> > zigzag(Node* root){
    vector<vector<int> > ans;
    if(root == NULL) return ans;
    bool leftToRight = true;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> res(size);
        for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();

            // checking if leftToRight is true or not
            // if true insert from front else from back
            int index = leftToRight ? i : size-1-i;
            res[index] = temp->data;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        leftToRight = !leftToRight;
        ans.push_back(res);
    }
    return ans;
}


int main(){
    Node* root = createTree();
    vector<vector<int> > ans = zigzag(root);
    for(auto val : ans){
        for(auto vals : val){
            cout << vals << " ";
        }
        cout << endl;
    }
    return 0;
}