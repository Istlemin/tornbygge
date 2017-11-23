#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()
#define sz(v) v.size()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vi lis(vi S) {
	vi prev(sz(S));
	typedef pair<ll, int> p;
	vector<p> res;
	rep(i,0,sz(S)) { 
		p el { S[i], i };
		auto it = lower_bound(all(res), p { S[i]+1, 0 }); 
		if (it == res.end()) res.push_back(el), it = --res.end();
		*it = el;
		prev[i] = it==res.begin() ?0:(it-1)->second; 
	}
	int L = sz(res), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

int main() {
	cin.sync_with_stdio(false);
	ll n; cin>>n;
	vector<pii> v(n);
	rep(i,0,n){
		cin>>v[i].first>>v[i].second;
	}
	sort(all(v));
	vi heights(n);
	rep(i,0,n) heights[i] = v[i].second;
	vi tower = lis(heights);
	ll ans = 0;
	rep(i,0,tower.size()){
		ans += heights[tower[i]];
	}
	cout<<ans<<endl;
}