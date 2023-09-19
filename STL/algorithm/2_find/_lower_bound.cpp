#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
  ll n;
  cin>>n;
  vector<ll>a(n);
  vector<ll>b(n);
  vector<ll>c(n);
  for(ll i=0;i<n;i++){
    cin>>a[i];
  }
  for(ll i=0;i<n;i++){
    cin>>b[i];
  }
  for(ll i=0;i<n;i++){
    cin>>c[i];
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  sort(c.begin(),c.end());
  ll sum = 0;
  for(ll i=0;i<n;i++){
    ll j=lower_bound(a.begin(),a.end(),b[i])-a.begin()-1;
    ll k=upper_bound(c.begin(),c.end(),b[i])-c.begin();
    sum+=(long long)(j+1)*(n-k);
  }
  cout<<sum;
  return 0;
}