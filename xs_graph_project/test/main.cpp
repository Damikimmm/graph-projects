#include<bits/stdc++.h>
using namespace std;
#define repi(i, a, b) for (int i = (a), i##len = (b); i <= i##len; ++i)
#define peri(i, a, b) for (int i = (a), i##len = (b); i >= i##len; --i)
#define ll long long
#define pii pair<int, int>
 ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
 ll lcm(ll a,ll b){
    return a/(gcd(a,b))*b;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int _;cin>>_;
    while(_--){
        int N,M,Q;cin>>N>>M>>Q;
        vector<ll> lcmm(N+1,1);  //习惯上加一位
        for(int i=0;i<M;i++){
            int x,y; ll g;
            cin>>x>>y>>g;
            lcmm[x]=lcm(lcmm[x],g);
            lcmm[y]=lcm(lcmm[y],g);
        }
        for (int i = 0; i < Q; i++)
        {
            int x,y;cin>>x>>y;
            cout<<gcd(lcmm[x],lcmm[y])<<endl;
        }
    }
	return 0;
}