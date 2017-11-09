#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pi;
typedef pair<pi, int> pii;
#define INF 100000000
const int Size = 1007;


vector<pi>edge[Size];
int dis[Size][105];
int cost[Size];
int capa,n,m;

int dijkstra(int st,int ed){

    priority_queue<pii, vector<pii>, greater<pii> > pq;
    memset(dis,0x7f,sizeof dis);

    dis[st][0]=0;
    pq.push(make_pair(make_pair(dis[st][0],0),st));

    while(!pq.empty()){

        pii akhon = pq.top();
        pq.pop();
        int u = akhon.second;
        int unit = akhon.first.second; //unit koto cover korbe
        int nite_parbe = akhon.first.first; // koto nile best

        if(nite_parbe>dis[u][unit]) continue;
        if(u==ed) return dis[u][unit];

        for(int i=0; i<edge[u].size(); ++i){

             int v = edge[u][i].first;
             int range = edge[u][i].second;

             if(range>capa) continue;

             if(unit >= range && dis[v][unit-range]>dis[u][unit]){
                dis[v][unit-range]=dis[u][unit];
                pq.push(make_pair(make_pair(dis[v][unit-range],unit-range),v));
             }
        }

        if(unit<capa){
            dis[u][unit+1] = dis[u][unit] + cost[u];
            pq.push(make_pair(make_pair(dis[u][unit+1],unit+1),u));
        }
    }

    return INF;

}

int main()
{
    int test;

    cin>>test;

    for(int t=1; t<=test; t++){


    cin>>n>>m;

    for(int i=0; i<=n; i++)
        edge[i].clear();

    for(int i=0; i<n; i++)
        cin>>cost[i];

    int u,v,c;
    for(int i=0; i<m; i++){

        cin>>u>>v>>c;

        edge[u].push_back(make_pair(v,c));
        edge[v].push_back(make_pair(u,c));
    }


    int q,s,tt;
    printf("Case %d:\n",t);


    cin>>q;

    for(int i=0; i<q; i++){
    cin>>capa>>s>>tt;

    int solve=dijkstra(s,tt);

    if(solve==INF) cout<<"impossible"<<endl;
    else cout<<solve<<endl;


    }
    }

}
