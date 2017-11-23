#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

struct Tree {
	typedef ll T;
	const T LOW = -1234567890;
	T f(T a, T b) { return max(a, b); }

	int n;
	vi s;
	Tree() {}
	Tree(int m, T def=0) { init(m, def); }
	void init(int m, T def) {
		n = 1; while (n < m) n *= 2;
		s.assign(n + m, def);
		s.resize(2 * n, LOW);
		for (int i = n; i --> 1; )
			s[i] = f(s[i * 2], s[i*2 + 1]);
	}
	void update(int pos, T val) {
		pos += n;
		s[pos] = val;
		for (pos /= 2; pos >= 1; pos /= 2)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int l, int r) { return que(1, l, r, 0, n); }
	T que(int pos, int l, int r, int lo, int hi) {
		if (r <= lo || hi <= l) return LOW;
		if (l <= lo && hi <= r) return s[pos];
		int m = (lo + hi) / 2;
		return f(que(2 * pos, l, r, lo, m),
				que(2 * pos + 1, l, r, m, hi));
	} 
};

int main() { 
	cin.sync_with_stdio(false);
	ll n; cin>>n;
	map<ll,ll> heights;
	vector<pii> v(n);
	rep(i,0,n){
		cin>>v[i].first>>v[i].second;
		heights[v[i].second] = 1;
	}
	ll ind = 0;
	for(auto e:heights) heights[e.first] = ind++;

	sort(all(v));
	reverse(all(v));

	Tree st(n);
	rep(i,0,v.size())
		st.update(heights[v[i].second],st.query(0,heights[v[i].second]+1) + v[i].second);
	cout<<st.query(0,n)<<endl;
}
