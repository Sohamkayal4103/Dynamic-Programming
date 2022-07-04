#include<bits/stdc++.h>
#define ll long long
using namespace std;

int nthPoint(int n){
	vector<long long>arr(n+1);
	long long mo = 1000000007;
	arr[0] = 1;
	arr[1] = 1;
	arr[2] = 2;
	for(int i = 3;i <= n;i++){
		arr[i] = (arr[i-1]+arr[i-2])%mo;
	}
	return arr[n];
}

int main(){
  ll t;
  cin >> t;
  while(t--){
    ll n;
    cin >> n;
    cout << nthPoint(n) << endl;
  }
  return 0;
}