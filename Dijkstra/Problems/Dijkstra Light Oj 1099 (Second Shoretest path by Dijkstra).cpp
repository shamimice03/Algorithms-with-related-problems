#include<bits/stdc++.h>
#define inf 100000000000000000
#define X first
#define Y second
#define B begin()
#define E end()
#define mp make_pair
#define pb push_back
#define ll long long
#define loop1(i,n) for(ll i=1; i<=(n); i++)
#define loop2(j,n) for(ll j=1; j<=(n); j++)
#define loop0(i,n) for(ll i=0; i<(n); i++)
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
#define pll pair<ll, ll>
#define pii pair<int, int>
using namespace std;
const int Size=123456;
map<ll, vector<ll> > edges,cost;
ll p[Size],sp[Size];

void Dijkstra(ll src, ll des){

      priority_queue<pll, vector<pll>, greater<pll> >pq;
      pq.push(pll(0,src));
      p[src]=0;

      while(! pq.empty()){

        pll temp=pq.top();
        pq.pop();
        ll dis=temp.X;
        ll u=temp.Y;

        loop0(i,edges[u].size()){

           ll v=edges[u][i];

           if(dis+cost[u][i]<p[v]){
            sp[v]=p[v];
            p[v]=cost[u][i]+dis;
            pq.push(pll(p[v],v));
           }
           else if(dis+cost[u][i]<sp[v] && dis+cost[u][i] != p[v]){
            sp[v]=cost[u][i]+dis;
            pq.push(pll(sp[v],v));
           }
        }

      }

}

int main()
{
    ll n,e,u,v,w,t;
    cin>>t;

    loop1(i,t){

    cin>>n>>e;
    cost.clear();
    edges.clear();
    loop1(i,n) p[i]=sp[i]=LLONG_MAX;
    loop1(i,e){

       cin>>u>>v>>w;

       edges[u].pb(v);
       edges[v].pb(u);

       cost[u].pb(w);
       cost[v].pb(w);

    }

    Dijkstra(1,n);

   printf("Case %lld: %lld\n",i,sp[n]);
    }

    return 0;
}


