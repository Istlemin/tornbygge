#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main() {
	cin.sync_with_stdio(false);
	ll n; cin>>n;
	vector<pii> v(n);
	rep(i,0,n){
		cin>>v[i].first>>v[i].second;
		v[i].first *= -1;
	}
	sort(all(v));
	vi dp(n); //dp[i] = best solution that ends in i
	ll ans = 0;
	rep(i,0,n){
		rep(j,0,i){
			if(v[j].second<=v[i].second)
				dp[i] = max(dp[j],dp[i]);
		}
		dp[i] += v[i].second;
		ans = max(dp[i],ans);
	}
	cout<<ans<<endl;
}
