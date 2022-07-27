#include<bits/stdc++.h>
#define int long long
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0] == 1)return 0;
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n,(vector<int>(m,1)));
        for(int i = 0;i < n;i++){
            if(obstacleGrid[i][0] == 1){
                while(i < n){
                    dp[i][0] = 0;
                    i++;
                }
            }
        }
        for(int j = 0;j < m;j++){
            if(obstacleGrid[0][j] == 1){
                while(j < m){
                    dp[0][j] = 0;
                    j++;
                }
            }
        }
        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }
                else{
                    int up = 0,left = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = left + up;
                }
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[n-1][m-1];
    }


int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>obstacleGrid(n,vector<int>(m));
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        cin >> obstacleGrid[i][j];
      }
    }
    int ans = uniquePathsWithObstacles(obstacleGrid);
    cout << ans << endl;
  }
}