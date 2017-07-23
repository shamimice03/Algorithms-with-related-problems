#include<bits/stdc++.h>
using namespace std;
bool visited[100];
vector<int>edges[100];

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty()){
      int u=Q.front();
        cout<<u<<endl;
        Q.pop();
        for(int i=0; i<edges[u].size(); i++){

             if(visited[edges[u][i]]!=1){

                int v=edges[u][i];
                Q.push(v);
                visited[v]=1;
            }
        }
    }
}

int main()
{

    int n,e,v,u,start;

    cin>>e;

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    cin>>start;

    BFS(start);

}
