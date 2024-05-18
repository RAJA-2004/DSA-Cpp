#include <bits/stdc++.h>
using namespace std;

// <!-- time complexity  : O(m*n) -->
// <!-- space complexity : O(n) -->

void dfs(int sr, int sc,int initalColor, int newColor,vector<vector<int>>& image,vector<vector<int>>& ans,int d1[],int d2[]){
	ans[sr][sc] = newColor;
	int n = image.size();
	int m = image[0].size();
	for(int i=0;i<4;i++){
		int nrow = sr + d1[i];
		int ncol = sc + d2[i];
		if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol]==initalColor && ans[nrow][ncol]!=newColor){
			dfs(nrow,ncol,initalColor,newColor,image,ans,d1,d2);
		}
	}
}

vector<vector<int>> floodfill(vector<vector<int>>& image, int sr, int sc, int newColor){
	vector<vector<int>> ans = image;
	int initalColor = image[sr][sc];
	int d1[] = {0,-1,0,+1};
	int d2[] = {-1,0,+1,0};
	dfs(sr,sc,initalColor,newColor,image,ans,d1,d2);
	return ans;
}

int main(){
	int n;
	cin >> n;
	vector<vector<int>> isConnected(n,vector<int>(n,0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin >> isConnected[i][j];
		}
	}
	int sr,sc,newColor;
	cin >> sr >> sc >> newColor;
	vector<vector<int>> ans = floodfill(isConnected,sr,sc,newColor);
	for(auto it : ans){
		for(auto its : it){
			cout << its << " ";
		}
		cout << endl;
	}
	return 0;
}