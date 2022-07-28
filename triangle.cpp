#include<bits/stdc++.h>
#define ll long long
using namespace std; 

int minimumTotal(vector<vector<int>>& triangle) {
        for(int i = 1;i < triangle.size();i++){
            for(int j = 0;j < triangle[i].size();j++){
                int up = INT_MAX;
                int tup = INT_MAX;
                if(i-1 >= 0 && j < triangle[i].size()-1){
                    up = triangle[i-1][j];
                }
                if(i-1 >= 0 && j-1 >= 0){
                    tup = triangle[i-1][j-1];
                }
                triangle[i][j] += min(up,tup);
            }
        }
        int n = triangle.size();
        int m = triangle[n-1].size();
        int ans = INT_MAX;
        for(int i = 0;i < triangle[n-1].size();i++){
            if(triangle[n-1][i] < ans){
                ans = triangle[n-1][i];
            }
        }
        return ans;
    }


int main(){
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<vector<int>>triangle;
    for(int i = 0;i < n;i++){
      vector<int>v1;
      for(int j = 0;j <= i;j++){
        int x;
        cin >> x;
        v1.push_back(x);
      }
      triangle.push_back(v1);
    }
    int ans = minimumTotal(triangle);
    cout << ans << endl;
  }
}