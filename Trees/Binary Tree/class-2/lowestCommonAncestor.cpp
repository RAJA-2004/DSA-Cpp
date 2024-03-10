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

Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
    if(root==NULL) return NULL;
    if(root->data==p->data) return p;
    if(root->data==q->data) return q;
    Node* leftSearch = lowestCommonAncestor(root->left,p,q);
    Node* rightSearch = lowestCommonAncestor(root->right,p,q);

    if(leftSearch==NULL && rightSearch==NULL) return NULL;
    else if(leftSearch==NULL && rightSearch!=NULL) return rightSearch;
    else if(leftSearch!=NULL && rightSearch==NULL) return leftSearch;
    else return root;
}
int main(){
    Node* root = createTree();
    Node* p = new Node(5);
    Node* q = new Node(1);
    root = lowestCommonAncestor(root,p,q);
    cout << "lowest Common Ancestor : " << root->data << endl;
    return 0;
}