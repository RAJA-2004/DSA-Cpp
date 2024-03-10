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

bool lowestCommonAncestor(Node* root, int p,int k) {
    if(root==NULL){
        return false;
    }
    if(root->data==p){
        return true;
    }
    bool leftSearch = lowestCommonAncestor(root->left,p,k);
    bool rightSearch = lowestCommonAncestor(root->right,p,k);
    if(leftSearch || rightSearch){
        k--;
    }
    if(k == 0){
        cout << root->data << " ";
        k=-1;
    }
    return leftSearch || rightSearch;
}
int main(){
    Node* root = createTree();
    int k = 1;
    int p = 4;
    bool f = lowestCommonAncestor(root,p,k);
    return 0;
}