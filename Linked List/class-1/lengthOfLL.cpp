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
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
    Node(int data,Node* ptr){
        this->data=data;
        next=ptr;
    }
};
Node* convert(vector<int>& ans){
    Node* head = new Node(ans[0]);
    Node* trav = head;
    for(int i=1;i<ans.size();i++){
        Node* temp = new Node(ans[i]);
        trav->next = temp;
        trav = trav->next;
    }
    return head;
}
int len(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        count ++;
        temp = temp->next;
    }
    return count;
}
int main(){
    vector<int> ans{1,12,3,14};
    Node* head = convert(ans);
    Node* temp = head;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    int count = len(head);
    cout << count << endl;
    return 0;
}