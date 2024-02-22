#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        next=NULL;
    }
    node(int data,node* next1){
        this->data=data;
        next=next1;
    }
};

int main(){
    vector<int> ans{2,3,4,5};
    node* x = new node(ans[0]);
    node* y = new node(ans[1],x->next);
    cout << x->data << endl;
    cout << y->next << endl;
    return 0;
}