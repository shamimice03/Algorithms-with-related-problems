#include<bits/stdc++.h>
using namespace std;
bool visited[100];
int parent[100];
vector<int>edges[100];
vector<int>path;
int level[100];

map<int,int>ss;

void make(int n){

  for(int i=0; i<=40; i++)
  {
      parent[i]=0;
      level[i]=0;
      visited[i]=0;

  }

}

void fll(int n){

  for(int i=0; i<=40; i++)
  {

      edges[i].clear();
  }

}

void BFS(int start, int l,int Case,int ini,int sala){

   queue<int>Q;

   Q.push(start);

   visited[start]=1;
   int c=0;
   level[start]=0;

   while(!Q.empty()){

      int v=Q.front();
      Q.pop();

      for(int i=0; i<edges[v].size(); i++){

           int u=edges[v][i];

           if(visited[u]!=1){
            Q.push(u);
            visited[u]=1;
            parent[u]=v;
            level[u]=level[v]+1;
            if(level[u]<=l)
                c++;
           }
          }
         }
      printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",Case,sala-c,ini,l);
    }


int main()
{
   int n,e,u,v,start,End,l,k=1,Case=1,sala;

  while(1){
   cin>>e;
  fll(100);
   if(e==0) return 0;
     k=1;
   for(int i=1; i<=e; i++){
       cin>>u>>v;

       if(ss.find(u)==ss.end()) ss[u]=k++;
       if(ss.find(v)==ss.end()) ss[v]=k++;

       edges[ss[u]].push_back(ss[v]);
       edges[ss[v]].push_back(ss[u]);
   }


 sala=k-2;
   while(1){
    make(100);
  cin>>start>>l;
  if(start==0 && l==0) break;

   BFS(ss[start],l,Case,start,sala);
   Case++;
   }
   ss.clear();

}
}

