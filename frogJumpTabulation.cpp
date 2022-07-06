#include<bits/stdc++.h>
#define ll long long
using namespace std;

int frogJump(int n, vector<int> &heights)
{
    vector<int>dp(n+1,0);
    dp[0] = 0;
    for(int i = 1;i < n;i++){
        int ls = dp[i-1]+abs(heights[i]-heights[i-1]);
        int rs = INT_MAX;
        if(i > 1){
            rs = dp[i-2]+abs(heights[i]-heights[i-2]);
        }
        dp[i] = min(ls,rs);
    }
    return dp[n-1];
}

//frogJump space optimized
int frogJumpSpaceOptimized(int n, vector<int> &heights)
{
    
    int prev,prev2,curr;
    prev = 0;
    prev2 = INT_MAX;
    for(int i = 1;i < n;i++){
        int ls = prev+abs(heights[i]-heights[i-1]);
        int rs = INT_MAX;
        if(i > 1){
            rs = prev2+abs(heights[i]-heights[i-2]);
        }
        curr = min(ls,rs);
        prev2 = prev;
        prev = curr;
    }
    return curr;
}

int main() {
  ll t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    vector<int>heights(n);
    for(ll i =0;i < n;i++){
      cin >> heights[i];
    }
    cout << frogJump(n,heights) << endl;
  }
  return 0;
}