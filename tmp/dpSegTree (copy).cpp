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
	vector<pii> tmpV(n);
	map<ll,ll> heights;
	rep(i,0,n){
		cin>>tmpV[i].first>>tmpV[i].second;
		heights[tmpV[i].second] = 1;
	}
	ll ind = 0;
	for(auto e:heights) heights[e.first] = ind++;

	sort(all(tmpV));
	reverse(all(tmpV));

	vector<vi> v;
	rep(i,0,n){
		if(i>0&&tmpV[i].first==tmpV[i-1].first)
			v[v.size()-1].push_back(tmpV[i].second);
		else
			v.push_back(vi(1,tmpV[i].second));
	}

	Tree st(n);
	rep(i,0,v.size()){
		vi newVals(v[i].size());
		rep(j,0,v[i].size()){
			newVals[j] = st.query(0,heights[v[i][j]]+1) + v[i][j];
			//cout<<v[i][j]<<" "<<heights[v[i][j]]<<": "<<newVals[j]<<endl;
		}
		rep(j,0,v[i].size())
			st.update(heights[v[i][j]],newVals[j]);
		//cout<<endl;
	}
	cout<<st.query(0,n)<<endl;
}
