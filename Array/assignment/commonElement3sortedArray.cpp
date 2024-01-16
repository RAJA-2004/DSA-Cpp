#include <iostream>
#include <vector>
#include <set>
using namespace std;

// SET APPROACH

vector<int>common(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3,int n1,int n2, int n3){
    set<int> st;
    int i,j,k;
    i=j=k=0;
    vector<int> ans;
    while(i<n1 && j<n2 && k<n3){
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
            st.insert(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr3[k]){
            j++;
        }
        else{
            k++;
        }
    }
    for(auto values:st){
        ans.push_back(values);
    }
    return ans;
}

vector<int> duplicate(vector<int>& a){
    vector<int> ans;
    sort(a.begin(),a.end());
    if(!(a.empty())){
        ans.push_back(a[0]);
    }
    int i=0;
    for(int j=1;j<a.size();j++){
        if(a[j]!=a[i]){
            ans.push_back(a[j]);
            a[i+1]=a[j];
            i++;
        }
    }
    return ans;
}

vector<int>common1(vector<int>& arr1,vector<int>& arr2,vector<int>& arr3,int n1,int n2, int n3){
    // REMOVE DUPLICATES APPROACH SO THAT NO ADDITIONAL DS IS REQUIRED
    arr1 = duplicate(arr1);
    arr2 = duplicate(arr2);
    arr3 = duplicate(arr3);
    int i,j,k;
    i=j=k=0;
    vector<int> ans;
    while(i<arr1.size() && j<arr2.size() && k<arr3.size()){
        if(arr1[i]==arr2[j] && arr2[j]==arr3[k]){
            ans.push_back(arr1[i]);
            i++;
            j++;
            k++;
        }
        else if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr3[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return ans;
}
int main(){
    vector<int>arr1 {3,3,3};
    vector<int>arr2 {3,3,3};        
    vector<int>arr3 {3,3,3};

    int n1 = arr1.size();
    int n2 = arr2.size();
    int n3 = arr3.size();
    
    vector<int> res;
    vector<int> res2;
    res=common(arr1,arr2,arr3,n1,n2,n3);

    res2=common1(arr1,arr2,arr3,n1,n2,n3);
    for(auto values : res){
        cout << values << " ";
    }

    
    cout << endl;
    for(auto values : res2){
        cout << values << " ";
    }
    return 0;
}