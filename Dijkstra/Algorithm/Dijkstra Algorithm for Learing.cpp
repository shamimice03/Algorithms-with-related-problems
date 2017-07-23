#include<bits/stdc++.h>
#define inf 100000000000000000
#define pii pair<int, int>
using namespace std;
const int Size=123456;
map<int, vector<int> >edges,mm;

long long cost[Size];
int parent[Size];

int Dijkstra(int str, int des){

  for(int i=1; i<=Size; i++){
      parent[i]=-1;
      cost[i]=inf;
  }

  priority_queue< pii, vector<pii>, greater<pii> > pq; /// Vector<pii> , greater<pii> its for enqueue ... decreasing to increasing///
  pq.push(make_pair(0,str));
  cost[str]=0;

   while(!pq.empty()){
       int u=pq.top().second;
       if(u==des) break;
       pq.pop();
       for(int i=0; i<edges[u].size(); i++){
          int v=edges[u][i];
          if(cost[u]+mm[u][i]<cost[v]){
              cost[v]=cost[u]+mm[u][i];
              parent[v]=u;
              pq.push(make_pair(cost[v],v));
          }
       }
   }
   int y=des;
   if(parent[des]==-1){cout<<"No path"<<endl; return -1;}
   else{
   vector<int>vec;
   vec.push_back(des);

   while(str!=des){
       des=parent[des];
       vec.push_back(des);
   }

   reverse(vec.begin(),vec.end());
   cout<<"Shortest path direction : ";
   for(int i=0; i<vec.size(); i++) cout<<vec[i]<<" ";
}
  cout<<endl;
  return cost[y];
}

int main()
{
    int n,e,u,v,w,s,d;

    cin>>n>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v>>w;
        edges[u].push_back(v);
        edges[v].push_back(u);

        mm[u].push_back(w);
        mm[v].push_back(w);

    }

    cin>>s>>d;
    int cost=0;
    cost=Dijkstra(s,d);

    if(cost!=-1) cout<<"Cost : "<<cost<<endl;

    return 0;
}
