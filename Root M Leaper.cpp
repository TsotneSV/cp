#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define deb(x) cout<<(x)<<"\n"
#define fast_cin() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const int INF=1e9,MOD=1e9+7;

bool check(int x,int n){
	if(x>0 && x<=n) return 1;
	return 0;
}

struct pCost{
	int f1;
	int s2;
	int cost;
};

int tt=1,n,m;
void solve(){
	cin>>n>>m; int reach[n+1][n+1]; memset(reach,-1,sizeof(reach));
	pCost p; p.f1=p.s2=1; p.cost=0;
	queue<pCost> q; q.push(p);
	while(!q.empty()){
		pCost top = q.front(); q.pop();
		int ff = top.f1,ss=top.s2,c=top.cost;
		if(reach[ff][ss]==-1) reach[ff][ss]=c;
		else reach[ff][ss]=min(reach[ff][ss],c);
		for(int i=0;i<=n;i++){
			int y = sqrt(m-i*i);
			if(y*y!=m-i*i) continue;
			if(check(ff+i,n)){
				if(check(ss+y,n)){
					pCost pp; pp.f1=ff+i; pp.s2=ss+y; pp.cost=c+1;
					q.push(pp);
				}
				if(check(ss-y,n)){
					pCost pp; pp.f1=ff+i; pp.s2=ss-y; pp.cost=c+1;
					q.push(pp);
				}
			}
			if(check(ff-i,n)){
				if(check(ss+y,n)){
					pCost pp; pp.f1=ff-i; pp.s2=ss+y; pp.cost=c+1;
					q.push(pp);
				}
				if(check(ss-y,n)){
					pCost pp; pp.f1=ff-i; pp.s2=ss-y; pp.cost=c+1;
					q.push(pp);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) cout<<reach[i][j]<<" ";
		cout<<"\n";
	}
}

main(){
    fast_cin();
    //cin>>tt;
    while(tt--){
        solve();
    }
}
