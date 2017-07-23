#include<bits/stdc++.h>
using namespace std;
bool visited[2000];
vector<int>edges[2000];
int color[2000];

void khela(int p){
    for(int i=0; i<=200; i++){
        edges[i].clear();
        visited[i]=0;
        color[i]=0;
    }
  }

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    color[s]=2;
    while(!Q.empty()){
      int u=Q.front();
        //cout<<u<<endl;
        Q.pop();
        for(int i=0; i<edges[u].size(); i++){

             if(visited[edges[u][i]]!=1){

                int v=edges[u][i];
                Q.push(v);
                visited[v]=1;
                if(color[u]==2)
                   color[v]=3;
                else color[v]=2;

            }
            else{
                int v=edges[u][i];
                if(color[u]==color[v]){cout<<"NOT BICOLORABLE."<<endl; return;}
            }

        }
    }
    cout<<"BICOLORABLE."<<endl;
}

int main()
{

    int n,e,v,u,start;

    while(1){
    khela(100);
    cin>>n;
    if(n==0) break;
    cin>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }


    BFS(v);

    }

}


