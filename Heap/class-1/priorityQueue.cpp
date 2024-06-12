
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    
    // by default MAX-HEAP
    priority_queue<int> pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(50);

    cout << "top element : " <<  pq.top() << endl;

    pq.pop();

    cout << "top element : " <<  pq.top() << endl;

    cout << "size : " << pq.size() << endl;

    if(pq.empty()) cout << "empty" << endl;
    else cout << "not empty" << endl;
    
    return 0;
}