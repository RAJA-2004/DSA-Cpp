#include <iostream>
#include <vector>
using namespace std;
int main (){
    
    // without size
    vector<vector<int> > arr;

    // with size
    int rows = 5;
    int cols = 5;
    int values = -8;
    vector<vector<int> > arr1(rows,vector<int>(cols,values));
    cout << "vector with size constraints" << endl;
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1[i].size();j++){
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    vector<int> a{1,2,3};
    vector<int> b{4,5,6};
    vector<int> c{7,8,9};

    arr.push_back(a);
    arr.push_back(b);
    arr.push_back(c);
    cout << "vector without size constraints" << endl;
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr[i].size();j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}