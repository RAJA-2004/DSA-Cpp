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

class NodeData{
    public:
    int minVal;
    int maxVal;
    int size;
    bool validBst;

    NodeData(int size,int max,int min,bool valid){
        this->size = size;
        minVal = min;
        maxVal = max;
        validBst = valid;
    }
};

NodeData* findLargestBst(Node* root,int& ans){
    // base case
    if(root == NULL){
        NodeData* temp = new NodeData(0,INT_MIN,INT_MAX,true);
        return temp;
    }
    NodeData* leftAns = findLargestBst(root->left,ans);
    NodeData* rightAns = findLargestBst(root->right,ans);

    NodeData* currNode = 
}

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

int main(){
    Node* root = NULL;
    root = create();
    Node* head = NULL;
    return 0;
}