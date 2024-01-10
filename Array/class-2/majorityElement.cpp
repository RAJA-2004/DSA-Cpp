#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> arr{1,2,1,1,2,3,4,2,1,2,3,2,4,2};
    sort(arr.begin(),arr.end());
    int max=0;
    int num=0;
    for(int i=0;i<arr.size();i++){
        int count = 1; 
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]==arr[j]){
                count++;
                arr[j]=INT_MIN;
            }
        }
        if(count>max){
            max=count;
            num=arr[i];
        }
    }
    cout << "majority element is : " << num << " with count : " << max << endl;
    return 0;
}
