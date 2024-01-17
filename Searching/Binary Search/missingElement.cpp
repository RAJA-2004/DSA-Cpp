#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> arr{1,2,3,5,6,7,8};
    int x = -1;
    for(int i=0;i<arr.size();i++){
        if(!(binary_search(arr.begin(),arr.end(),i+1))){
            x = i+1;
        }
    }
    cout << x << endl;
    return 0;
}