
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

int width(Node* root){
    if(root == NULL) return 0;
    queue<pair<Node*,long long int> > q;
    q.push({root,0});
    long long int ans = 0;
    while(!q.empty()){
        long long int size = q.size();
        long long int currMin = q.front().second;
        long long int leftMost,rightMost;
        for(long long int i=0;i<size;i++){
            long long int curr = q.front().second - currMin;
            Node* temp = q.front().first;
            q.pop();
            if(i==0) leftMost = curr;
            if(i==size-1) rightMost = curr;
            if(temp->left) q.push({temp->left,2*i+1});
            if(temp->right) q.push({temp->right,2*i+2});
        }
        ans = max(ans,rightMost-leftMost+1);
    }
    return ans;
}

int main(){
    Node* root = create();
    cout << "max width is : " << width(root) << endl;
    return 0;
}