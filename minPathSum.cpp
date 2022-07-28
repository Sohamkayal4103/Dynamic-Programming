#include<bits/stdc++.h>
#define ll long long
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        for(int j = 1;j < grid[0].size();j++){
            grid[0][j] += grid[0][j-1];
        }
        for(int i = 1;i < grid.size();i++){
            grid[i][0] += grid[i-1][0];
        }
        for(int i = 1;i < n;i++){
            for(int j = 1;j < m;j++){
                grid[i][j] += min(grid[i-1][j],grid[i][j-1]);
            }
        }
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++){
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
        return grid[n-1][m-1];
    }

int main(){
  ll t;
  cin >> t;
  while(t--){
    int n,m;
    cin >> n >> m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i = 0;i < n;i++){
      for(int j = 0;j < m;j++){
        cin >> grid[i][j];
      }
    }
    int ans = minPathSum(grid);
    cout << ans << endl;
  }
}