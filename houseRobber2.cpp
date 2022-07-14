#include<bits/stdc++.h>
#define ll long long
using namespace std;

long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    vector<long long int>dp1(n,0);
    dp1[0] = valueInHouse[0];
    dp1[1] = max(valueInHouse[0],valueInHouse[1]);
    for(int i = 2;i < n-1;i++){
        dp1[i] = max(dp1[i-1],valueInHouse[i]+dp1[i-2]);
    }
    vector<long long int>dp2(n,0);
    dp2[1] = valueInHouse[1];
    for(int i = 2;i < n;i++){
        dp2[i] = max(dp2[i-1],valueInHouse[i]+dp2[i-2]);
    }
    return max(dp1[n-2],dp2[n-1]);
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll n;
    vector<int> arr(n);
    for(ll i =0;i < n;i++){
      cin >> arr[i];
    }
    cout << houseRobber(arr) << endl;
  }
  return 0;
}