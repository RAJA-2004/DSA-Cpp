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
    return max(x,y)+1;
}

int diameter(Node* root){
    if(root==NULL) return 0;
    int leftDiameter = diameter(root->left);
    int rightDiameter = diameter(root->right);
    int h = height(root->left) + height(root->right);
    return max(h , max(leftDiameter,rightDiameter));
}

int main(){
    Node* root = createTree();
    cout << "diameter : " << diameter(root) << endl;
    return 0;
}