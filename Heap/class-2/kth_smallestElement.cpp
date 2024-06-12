#include <bits/stdc++.h>
using namespace std;



int main(){
	int n,target;
	cin >> n >> target;
	vector<int> ans(n);
	for(int i=0;i<n;i++){
		cin >> ans[i];
	}
	
	// <!-- MAX HEAP -->
	
	priority_queue<int> pq;
	
	for(int i=0;i<n;i++){
		pq.push(ans[i]);
		if(pq.size()>target){
			pq.pop();
		}
	}

	cout << pq.top() << endl;

	
	return 0;
}