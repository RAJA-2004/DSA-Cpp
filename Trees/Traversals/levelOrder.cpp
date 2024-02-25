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

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        // store queue front in temp
        Node* temp = q.front();

        // pop the node
        q.pop();

        // separating the levels
        if(temp == NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }else{
            // print data
            cout << temp->data << " ";

            // insert child
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void lvlOrder(Node* root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

int main(){
    Node* root = createTree();
    lvlOrder(root);
    cout << endl;
    levelOrderTraversal(root);
    return 0;
}