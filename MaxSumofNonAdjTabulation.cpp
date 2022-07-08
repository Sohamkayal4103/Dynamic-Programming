#include<bits/stdc++.h>
#define ll long long
using namespace std;

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    vector<int>dp(n,-1);
    dp[0] = nums[0];
    dp[1] = nums[1];
    for(int i = 1;i < n;i++){
        int take = nums[i];
        if(i > 1){
            take += dp[i-2];
        }
        int notTake = 0 + dp[i-1];
        dp[i] = max(take,notTake);
    }
    return dp[n-1];
}

//space -optimized solution

int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    
    int prev,prev2,curr;
    
    prev = nums[0];
    prev2 = 0;
    for(int i = 1;i < n;i++){
        int take = nums[i];
        if(i > 1){
            take += prev2;
        }
        int notTake = 0 + prev;
        curr = max(take,notTake);
        prev2 = prev;
        prev = curr;
    }
    return prev;
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