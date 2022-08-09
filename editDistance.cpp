#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(s1[i] == s2[j])
            return dp[i][j] = solve(i-1,j-1,s1,s2,dp);
        else{
            return dp[i][j] = 1 + min(solve(i-1,j-1,s1,s2,dp),min(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp)));
        }
    }
    
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(n-1,m-1,word1,word2,dp);
    }

int main(){
  ll t;
  cin >> t;
  while(t--){
    string word1,word2;
    cin >> word1 >> word2;
    int ans = minDistance(word1,word2);
    cout << ans << endl;
  }
}