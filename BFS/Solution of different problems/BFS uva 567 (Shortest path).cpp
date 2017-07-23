#include<bits/stdc++.h>
using namespace std;
bool visited[100];
int parent[100];

vector<int>edges[100];
vector<int>path;
void fll(int n){
  for(int i=0; i<=40; i++) edges[i].clear();
}

void make( int n)
{
    for(int i=0; i<=40; i++)
    {
        parent[i]=0;
        visited[i]=0;
        path.clear();
    }
}

int BFS(int s,int des){

  queue<int>Q;

  Q.push(s);

  visited[s]=1;

  while(!Q.empty()){

    int u=Q.front();
    Q.pop();

    for(int i=0; i<edges[u].size(); i++){

        if(visited[edges[u][i]]!=1){

            int v=edges[u][i];
            visited[v]=1;
            parent[v]=u;
            Q.push(v);
        }

        if(visited[des]==1) break;
    }
  }

  path.push_back(des);
  int b=des;
  while(b!=s){
    b=parent[b];
    path.push_back(b);
  }
     int k=path.size();
      return k-1;
}

int main()
{
    int n,e,u,v,start,End,let=1;

      while(scanf("%d",&e)!= EOF){
        fll(40);


        for(int i=1; i<=e; i++){
            cin>>v;
            edges[1].push_back(v);
            edges[v].push_back(1);
        }

        for(int j=2; j<=19; j++){
        cin>>e;

        for(int i=1; i<=e; i++){
            cin>>v;
            edges[j].push_back(v);
            edges[v].push_back(j);
        }

        }
    printf("Test Set #%d\n",let);
     int qu,ans=0;
     cin>>qu;
    for(int j=1; j<=qu; j++){

    cin>>start>>End;

    ans=BFS(start,End);

   printf("%2d to %2d: %d\n",start,End,ans);
    make(100);

    }
    cout<<endl;
    let++;
      }
    return 0;
}

