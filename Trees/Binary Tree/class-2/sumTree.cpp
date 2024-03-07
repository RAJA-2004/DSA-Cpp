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

int convert(Node* root){
    if(root==NULL) return 0;
    int leftSum = convert(root->left);
    int rightSum = convert(root->right);
    root->data = root->data+leftSum+rightSum;
    return root->data;
}

void preOrder(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = createTree();
    root->data = convert(root);
    preOrder(root);
    return 0;
}