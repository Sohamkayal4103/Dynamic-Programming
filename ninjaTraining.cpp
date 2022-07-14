#include<bits/stdc++.h>
#define ll long long
using namespace std;

int f(int i,int last,vector<vector<int>> &points,vector<vector<int>> &dp){
    if(dp[i][last] != -1) return dp[i][last];
    if(i == 0){
        int maxi = 0;
        for(int j = 0;j < 3;j++){
            if(j != last){
                maxi = max(points[i][j],maxi);
            }
        }
        dp[i][last] = maxi; 
        return maxi;
    }
    int maxi = 0;
    for(int j = 0;j < 3;j++){
        if(j != last){
            int point = points[i][j] + f(i-1,j,points,dp);
            maxi = max(point,maxi);
        }
    }
    dp[i][last] = maxi;
    return maxi;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n,vector<int>(4,-1));
    int pointsMax = f(n-1,3,points,dp);
    return pointsMax;
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<vector<int>>arr(n,vector<int>(3));
        for(ll i =0;i < n;i++){
            for(ll j = 0;j < 3;j++){
                cin >> arr[i][j];
            }
        }
        int ans = ninjaTraining(n,arr);
        cout << ans << endl;
    }
}