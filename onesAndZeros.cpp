#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(vector<pair<int,int>>&arr,int i,int m,int n,vector<vector<vector<int>>>&dp){
        if(i == arr.size()){
            return 0;
        }
        if(dp[m][n][i] != -1) return dp[m][n][i];
        int ct0 = arr[i].first;
        int ct1 = arr[i].second;
        // cout << ct0 << " " << ct1 << endl;
        if(m - ct0 >= 0 && n - ct1 >= 0){
            return dp[m][n][i] = max(1+solve(arr,i+1,m-ct0,n-ct1,dp),solve(arr,i+1,m,n,dp));
        }
        return dp[m][n][i] = solve(arr,i+1,m,n,dp);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>arr;
        for(int i = 0;i < strs.size();i++){
            int ct0=0,ct1=0;
            for(int j = 0;j < strs[i].size();j++){
                if(strs[i][j] == '1'){
                    ct1++;
                }
                else{
                    ct0++;
                }
            }
            arr.push_back(make_pair(ct0,ct1));
            
        }
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(arr.size(),-1)));
        return solve(arr,0,m,n,dp);
    }

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll n1;
    cin >> n1;
    vector<string>strs(n1);
    for(ll i = 0;i < n1;i++){
      cin >> strs[i];
    }
    int m,n;
    cin >> m >> n;
    int ans = findMaxForm(strs,m,n);
    cout << ans << endl;
  }
}