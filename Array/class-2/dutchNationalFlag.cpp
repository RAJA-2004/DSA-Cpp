#include <iostream>
#include <vector>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    vector<int>ans;
    for(int i=0;i<9;i++){
        int a;
        cin >> a;
        ans.push_back(a);
    }

    // TWO pointer approach
    int start = 0;
    int end = ans.size()-1;
    int i=0;
    while(start<end){
        if(ans[i]==0){
            swap(ans[start],ans[i]);
            i++;
            start++;
        }
        else{
            swap(ans[end],ans[i]);
            end--;
        }
    }
    for(auto values:ans){
        cout << values << " ";
    }
    cout << endl;
    return 0;
}