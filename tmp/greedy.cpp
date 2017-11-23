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
		cin>>v[i].second>>v[i].first;
	}
	sort(all(v));
	reverse(all(v));
	ll sum = 0;
	ll last = -1e18;
	ll lastW = 1e18;
	rep(i,0,n){
		if(last<=v[i].second&&lastW>v[i].first){
			last = v[i].second;
			lastW = v[i].first;
			sum += v[i].first;
		}
	}
	cout<<sum<<endl;
}
