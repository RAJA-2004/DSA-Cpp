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

int height(Node* root){
    if(root==NULL) return 0;
    int x = height(root->left);
    int y = height(root->right);
    if(x==-1 || y==-1 || abs(x-y)>1) return -1;
    return max(x,y)+1;
}

int main(){
    Node* root = createTree();
    int h = height(root);
    if(h==-1) cout << "not balanced";
    else cout << "balanced";
    cout << endl;
    return 0;
}