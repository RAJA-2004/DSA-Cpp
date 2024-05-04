#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& ans){
	int n = ans.size();
	int prev1 = ans[0];
	int prev2 = 0;
	for(int i=1;i<n;i++){
		int include = ans[i];
		if(i>1) include += prev2;
		int exclude = prev1;
		int curr = max(include,exclude);
		prev2 = prev1;
		prev1 = curr;
	}
	return prev1;
}

int house(vector<int>& ans){
	int n = ans.size();
	vector<int> i1;
	vector<int> i2;
	if(n==1) return ans[0];
	for(int i=0;i<n;i++){
		if(i!=0) i1.push_back(ans[i]);
		if(i!=n-1) i2.push_back(ans[i]);
	}
	return max(solve(i1),solve(i2));
}

int main(){
	int n;
	cin >> n;
	vector<int> ans;
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		ans.push_back(a);
	}
	cout << house(ans) << endl;
	return 0;
}