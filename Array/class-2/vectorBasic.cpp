#include <iostream>
#include <vector>
using namespace std;

int main(){
    
    // vector - Dynamic ARRAY
    vector <int> vrr;
    vector <int> ans{1,2,3,4,5};

    // size
    cout << "initial size : " << vrr.size() << endl;

    // capacity - double of size
    cout << "initial capacity : " << vrr.capacity() << endl;

    // fixed size -> size = capacity
    // vector <int> arr(10); // default initialised with 0 
    vector <int> arr(10,-1); // all initialised with -1

    // insert element
    vrr.push_back(10);
    vrr.push_back(20);
    vrr.push_back(30);

    // delete element
    vrr.pop_back();

    // empty
    cout << "vector empty : " << vrr.empty() << endl;
    
    for(int i=0;i<vrr.size();i++){
        cout << vrr[i] << " ";
    }

    cout << endl;
    cout << "size : " << vrr.size() << endl;
    cout << "capacity : " << vrr.capacity() << endl;

    return 0;
}