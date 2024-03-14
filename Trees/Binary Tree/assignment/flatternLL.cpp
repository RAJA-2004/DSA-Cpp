
// ! time complexity (without map) : O(n)
// ! time complexity (with map)    : O(n)

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

Node* create(){
    int data;
    cout << "enter data : ";
    cin >> data;
    if(data == -1){
        return NULL;
    }
    Node* root = new Node(data);
    root->left = create();
    root->right = create();
    return root;
}

void flattern(Node* root,Node* &prev){
    if(root == NULL) return;
    flattern(root->right,prev);
    flattern(root->left,prev);
    root->right = prev;
    root->left = NULL;
    prev = root;
}

void display(Node* root){
    while(root){
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main(){
    Node* root = create();
    Node* prev = NULL;
    flattern(root,prev);
    display(prev);
    return 0;
}