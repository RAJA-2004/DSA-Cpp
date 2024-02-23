#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(){
            this->data=0;
            this->next=NULL;
        }
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void disp(Node* &head){
    while(head){
        cout << head->data << " ";
        head=head->next;
    }
    cout << endl;
}

void s(Node* &head,int data){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}
int main(){
    Node* head = new Node(10);
    s(head,20);
    s(head,30);
    disp(head);
    return 0;
}