#include<bits/stdc++.h>
#define inf 100000000000000000000000
#define pii pair<int, int>
using namespace std;
const int Size=123456;
map<int, vector<int> >edges,mm;
map<int,int>check;
long long cost[Size],sc[Size];
int parent[Size];


void Dijkstra(int str, int des){

  priority_queue< pii, vector<pii>, greater<pii> > pq;
  pq.push(make_pair(0,str));
  cost[str]=0;

   while(!pq.empty()){
       int u=pq.top().second;
       int dis=pq.top().first;
       pq.pop();

       for(int i=0; i<edges[u].size(); i++){
          int v=edges[u][i];
          if(dis+mm[u][i]<cost[v]){
              sc[v]=cost[v];
              cost[v]=dis+mm[u][i];
              pq.push(make_pair(cost[v],v));
          }
           else if(dis+mm[u][i]<sc[v] && dis+mm[u][i] != cost[v]){
              sc[v]=dis+mm[u][i];
              parent[v]=u;
              pq.push(make_pair(sc[v],v));
          }
       }
   }

}


int main()
{
    int n,e,u,v,w,s,d,t,p=0;

   cin>>n>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v>>w;
        edges[u].push_back(v);
        edges[v].push_back(u);

        if(check.find(u)==check.end()) check[u]=1;
        if(check.find(v)==check.end()) check[v]=1;

        mm[u].push_back(w);
        mm[v].push_back(w);

    }

 for(int i=0; i<=n; i++){cost[i]=sc[i]=LLONG_MAX; parent[i]=-1;}
    cin>>s>>d;
    Dijkstra(s,d);

    cout<<sc[d]<<endl;

    return 0;
}

