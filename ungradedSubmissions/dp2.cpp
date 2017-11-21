#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vector<vi> mem;
vector<pii> v;
vi newHeights;
ll n;

ll getBest(ll last, ll index){
	if(index==n) return 0;
	if(mem[last][index] != -1)
		return mem[last][index];
	ll ans = getBest(last,index+1);
	if(newHeights[index]>=last)
		ans = max(ans,getBest(newHeights[index],index+1)+v[index].second);
	return mem[last][index] = ans;
}

int main() {
	cin.sync_with_stdio(false);
	cin>>n;
	v.resize(n);
	set<ll> heights;
	rep(i,0,n){
		cin>>v[i].first>>v[i].second;
		v[i].first *= -1;
		heights.insert(v[i].second);
	}

	vi allHeights;
	for(auto e:heights) allHeights.push_back(e);

	sort(all(v));
	rep(i,0,n)
		newHeights.push_back(lower_bound(all(allHeights), v[i].second) - allHeights.begin());
	
	mem.assign(n,vi(n,-1));

	cout<<getBest(0,0)<<endl;
}
