#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){

    // ! min heap using priority queue

    // priority_queue< data_type, container, comparator >
    priority_queue<int, vector<int>, greater<int> > pq;

    // insertion
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(40);

    cout << "size : " << pq.size() << endl;
    cout << "top element : " << pq.top() << endl;

    pq.pop();

    cout << "size : " << pq.size() << endl;
    cout << "top element : " << pq.top() << endl;
    return 0;
}