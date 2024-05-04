#include <bits/stdc++.h>
using namespace std;

void t(vector<int>& ans,vector<int>& arr,int i, int &count){
	if(i>=ans.size()){
		count++;
		return;
	}
	arr.push_back(ans[i]);
	t(ans,arr,i+1,count);
	
	arr.pop_back();
	t(ans,arr,i+1,count);
}

int s(vector<int>& ans){
	vector<int> arr;
	int count = 0;
	t(ans,arr,0,count);
	return count;
}

int main(){
	int n;
	cin >> n;
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		cin >> ans[i];
	}
	cout << s(ans) << endl;
	return 0;
}