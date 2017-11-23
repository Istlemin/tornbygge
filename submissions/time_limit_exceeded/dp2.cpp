#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

vector<vi> mem;
vector<pii> v;
map<ll,ll> heights;
ll n;

ll getBest(ll last, ll index){
	if(index==n) return 0;
	if(mem[last][index] != -1)
		return mem[last][index];
	ll ans = getBest(last,index+1);
	if(heights[v[index].second]>=last)
		ans = max(ans,getBest(heights[v[index].second],index+1)+v[index].second);
	return mem[last][index] = ans;
}

int main() {
	cin.sync_with_stdio(false);
	cin>>n;
	v.resize(n);
	rep(i,0,n){
		cin>>v[i].first>>v[i].second;
		heights[v[i].second] = 1;
	}
	ll ind = 0;
	for(auto e:heights) heights[e.first] = ind++;
	sort(all(v));
	reverse(all(v));

	mem.assign(n,vi(n,-1));

	cout<<getBest(0,0)<<endl;
}
