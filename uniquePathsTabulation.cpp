#include<bits/stdc++.h>
#define ll long long
using namespace std;

int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,1));
        for(int i = 1;i < m;i++){
            for(int j = 1;j < n;j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
        
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    int m,n;
    cin >> m >> n;
    int ans = uniquePaths(m,n);
    cout << ans << endl;
  }
  return 0;
}