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

bool identical(Node* p,Node* q){
    if(p==NULL && q==NULL) return true;
    if(p==NULL || q==NULL) return false;
    return (p->data==q->data) && identical(p->left,q->right) && identical(p->right,q->left);
}

int main(){
    Node* p = createTree();
    Node* q = createTree();
    if(identical(p,q)) cout << "mirror" << endl;
    else cout << "not mirror" << endl;
    return 0;
}