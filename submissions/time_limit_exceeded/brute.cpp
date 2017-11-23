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
	}
	sort(all(v));
	reverse(all(v));
	ll ans = 0;
	rep(mask,0,(1<<n)){
		bool valid = true;
		ll last = 0;
		ll sum = 0;
		rep(i,0,n){
			if((1<<i)&mask){
				if(last>v[i].second) valid = false;
				sum += v[i].second;
				last = v[i].second;
			}
		}
		if(valid){
			ans = max(sum,ans);
		}
	}
	cout<<ans<<endl;
}
