#include<bits/stdc++.h>
#define ll long long
using namespace std;

int kfrogJump(int n, int k, vector<int>heights){
  vector<int>dp(n);
  dp[0] = 0;
  for(int i = 1;i < n;i++){
    int minEnergy = INT_MAX;
    for(int j = 1;j <=k;j++){
      if(i-j >= 0){
        int jump = dp[i-j] + abs(heights[i]-heights[i-j]);
        minEnergy = min(jump,minEnergy);
      }
    }
    dp[i] = minEnergy;
  }
  return dp[n-1];
}


int main(){
  ll n,k;
  cin >> n >> k;
  vector<int>heights(n);
  for(int i = 0;i < n;i++){
    cin >> heights[i];
  }
  cout << kfrogJump(n,k,heights) << endl;  
}