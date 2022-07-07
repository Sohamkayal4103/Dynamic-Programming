#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(int ind,vector<int> &nums,vector<int> &dp){
    if(dp[ind] != -1) return dp[ind];
    if(ind == 0)
        return nums[0];
    if(ind < -1)
        return 0;
    int pick,notPick;
    pick = nums[ind] + solve(ind-2,nums,dp);
    notPick = 0 + solve(ind-1,nums,dp);
    dp[ind] = max(pick,notPick);
    return dp[ind];
}

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n,-1);
    return solve(n-1,nums,dp);
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int>nums(n);
    for(int  i= 0;i < n;i++){
      cin >> nums[i];
    }
    cout << maximumNonAdjacentSum(nums) << endl;
  }
}