#include <bits/stdc++.h>
using namespace std;

// powers of p
int p = 31;
const int N = 1e5 + 7, m = 1e9 + 7;
vector<long long> powers(N);

int main(){
	
	string s = "rajadigvijaysingh";
	string t = "ja";
	
	int S = s.size();
	int T = t.size();	
	
	int count = 0;
	
	powers[0] = 1;
	
	for(int i=1;i<N;i++){
		powers[i] = (powers[i-1]*p) % m;
	}
	
	vector<long long> h(T+1,0);
	
	for(int i=0;i<T;i++){
		h[i+1] = (h[i] + (t[i] - 'a' + 1) * powers[i]) % m;
	}
	
	long long h_s = 0; 
	
	for(int i=0;i<S;i++){
		h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % m;
	}
	
	for(int i=0; (i + S - 1) < T;i++){
		long long ch = (h[i+S] - h[i] + m) % m;

		if(ch == (h_s * powers[i]) % m){
			count++;
		}
	}
	cout << count << endl;
	return 0;
}