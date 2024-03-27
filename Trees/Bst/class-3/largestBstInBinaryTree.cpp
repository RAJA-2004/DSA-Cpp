#include <bits/stdc++.h>
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
    NodeData(int size, int max, int min, bool valid){
        this->size = size;
        minVal = min;
        maxVal = max;
        validBst = valid;
    }
};

NodeData* findLargestBst(Node* root, int& ans){
    // base case
    if(root == NULL){
        NodeData* temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }
    NodeData* leftAns = findLargestBst(root->left, ans);
    NodeData* rightAns = findLargestBst(root->right, ans);

    NodeData* currNode = new NodeData(0, 0, 0, false); // Allocate memory for currNode

    // Check if leftAns and rightAns are not NULL before accessing their members
    if (leftAns != NULL && rightAns != NULL) {
        // left side + right side + node itself
        currNode->size = leftAns->size + rightAns->size + 1;
        currNode->maxVal = max(root->data, rightAns->maxVal);
        currNode->minVal = min(root->data, leftAns->minVal);

        if (leftAns->validBst && rightAns->validBst && (root->data < rightAns->minVal && root->data > leftAns->maxVal)){
            currNode->validBst = true;
        }
        else{
            currNode->validBst = false;
        }
        if (currNode->validBst){
            ans = max(ans, currNode->size);
        }
    }
    return currNode;
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
    int ans = 0;
    NodeData* temp = findLargestBst(root, ans);
    cout << ans << endl;
    return 0;
}
