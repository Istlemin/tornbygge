#include<bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i<int(b);++i)
#define all(v) v.begin(),v.end()

typedef long long ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;

int main(int argc, char** argv) {
	cin.sync_with_stdio(false);
	srand(time(NULL));

	stringstream ss;
	rep(i,1,argc) ss<<argv[i]<<" ";
	string str;
	ll n; 
	bool iWidth; //If W_i should equal (n-i)
	ll type;
	ss>>n>>iWidth>>type;

	ll maxHW = 2*n;
	vi w(n);
	rep(i,0,n){
		if(rand()%5==1&&i!=0)
			w[i] = w[rand()%i];
		else
			w[i] = rand()%maxHW;
	}
	sort(all(w));
	reverse(all(w));

	vector<pii> blocks(n);
	if(type==1){ //Uniformly random
		rep(i,0,n){
			if(iWidth)
				blocks[i].first = (n-i);
			else
				blocks[i].first = w[i];
			
			if(rand()%8==1&&i!=0)
				blocks[i].second = blocks[rand()%i].second;
			else
				blocks[i].second = rand()%maxHW;
		}
	}
	if(!iWidth)
		random_shuffle(all(blocks));
	cout<<n<<endl;
	rep(i,0,n)
		cout<<blocks[i].first<<" "<<blocks[i].second<<endl;
	return 0;
}
