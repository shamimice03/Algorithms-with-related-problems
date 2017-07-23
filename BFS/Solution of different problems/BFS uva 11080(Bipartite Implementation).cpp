#include<bits/stdc++.h>
using namespace std;
#define MAXX 10000

int parent[MAXX];
bool visited[20000];
vector<int>edges[20000];
set<int>kopa;
set<int>total;
int color[20000],c2=0,c3=0,c=0;


void makeset(int p){
 parent[p]=p;
}

void kaka(){
   for(int i=0; i<=10000; i++){
      edges[i].clear();
      visited[i]=0;
      color[i]=0;

   }
}

int BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    c=0;
    visited[s]=1;
    color[s]=2;
    c2++;
    while(!Q.empty()){
      int u=Q.front();
        Q.pop();
        for(int i=0; i<edges[u].size(); i++){

             if(visited[edges[u][i]]!=1){

                int v=edges[u][i];
                Q.push(v);
                visited[v]=1;

                if(color[u]==2){color[v]=3; c3++;}
                else {color[v]=2; c2++;}

            }
            else{
                int v=edges[u][i];
                if(color[u]==color[v]){cout<<"-1"<<endl; kaka(); c2=0,c3=0,c=1;return 0;}
            }

        }
    }
   int f =0;
   f= min(c2,c3);
     c2=0,c3=0;
    int color[20000]={0};
   return f;

}


int finding(int represent){

   if(parent[represent]==represent)
    return represent;
   else
    return parent[represent]=finding(parent[represent]);
}

void Union(int a,int b){

 int u=finding(a);
 int v=finding(b);
  if(u!=v) parent[u]=v;
  //else cout<<u<<endl;

}

void Check(int a){ int v=finding(a); kopa.insert(v); }

int main()
{

    int a,b,s,e,n,u,v,ans=0,test,t=0;
    cin>>test;

    while(test--){
    vector<int>oh;
    cin>>n>>e;
  for(int i=0; i<=n; i++) makeset(i);

  for(int i=1; i<=e; i++){
    cin>>u>>v;
    edges[u].push_back(v);
    edges[v].push_back(u);
    oh.push_back(u);
    oh.push_back(v);
    total.insert(v);
    total.insert(u);
    Union(u,v);
  }

  for(int i=0; i<oh.size(); i++)
        Check(oh[i]);

        oh.clear();

  set<int>:: iterator it;
  for(it=kopa.begin(); it!=kopa.end(); it++){
    int l=*it;
    ans+=BFS(l);
    if(c==1) break;

  }


  kopa.clear();

  if(e>0 && ans >0 && c==0)
   cout<<ans+(n-total.size())<<endl;
  else if(e==0) cout<<n<<endl;

  ans=0;

   kaka();
   total.clear();
    }

  return 0;
}
