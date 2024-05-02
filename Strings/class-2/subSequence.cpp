#include <bits/stdc++.h>
using namespace std;

void display(string t){
	for(auto val : t){
		cout << val << " ";
	}
	cout << endl;
}

void solve(string s,string t,int i){
	if(i>=s.size()){
		display(t);
		return;
	}
	solve(s,t,i+1);
	t.push_back(s[i]);
	solve(s,t,i+1);
	t.pop_back();
}

int main(){
	string s;
	cin >> s;
	string t;
	solve(s,t,0);
	return 0;
}