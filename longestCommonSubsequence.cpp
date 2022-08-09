#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        
        if(i == text1.length() || j == text2.length()){
            return 0;
        }
        if(dp[i][j] != -1)return dp[i][j];
        if(text2[j] == text1[i]){
            return dp[i][j] = 1 + solve(text1,text2,i+1,j+1,dp);
        }
        else{
            return dp[i][j] = max(solve(text1,text2,i+1,j,dp),solve(text1,text2,i,j+1,dp));
        }
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return solve(text1,text2,0,0,dp);
    }

int main(){
  ll t;
  cin >> t;
  while(t--){
    string text1,text2;
    cin >> text1 >> text2;
    int ans = longestCommonSubsequence(text1,text2);
    cout << ans << endl;
  }
}
