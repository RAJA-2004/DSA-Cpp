#include <bits/stdc++.h>
using namespace std;

class job{
	
	public:
		int id;
		int profit;
		int dead;	
		void getId(){
			cin >> id;
		}
		void getProfit(){
			cin >> profit;
		}
		void getDead(){
			cin >> dead;
		}
		void display(){
	        cout << "id : " << id << endl << "profit : " << profit << " deadline : " << dead << endl;
	    }
};

bool static comp(job val1,job val2){
	return val1.profit > val2.profit;
}

vector<int> solve(job arr[],int n){
	sort(arr,arr+n,comp);
	int maxDeadLine = -1;
	for(int i=0;i<n;i++){
		maxDeadLine = max(maxDeadLine,arr[i].dead);
	}
	int count = 0;
	int maxProfit = 0;
	vector<int> ans(maxDeadLine+1,-1);
	for(int i=0;i<n;i++){
		for(int j=arr[i].dead;j>0;j--){
			if(ans[j]==-1){
				ans[j] = arr[i].id;
				count++;
				maxProfit+=arr[i].profit;
				break;
			}
		}
	}
	vector<int> res(2);
	res[0]=count;
	res[1]=maxProfit;
	return res;
}

int main(){
	int n;
	cin >> n;
	job j1[n];
	for(int i=0;i<n;i++){
		j1[i].getId();
		j1[i].getDead();
		j1[i].getProfit();
	}
	vector<int> ans = solve(j1,n);
	for(auto val : ans){
		cout << val << " ";
	}
	// for(int i=0;i<n;i++){
	// 	j1[i].display();
	// }

	return 0;
}