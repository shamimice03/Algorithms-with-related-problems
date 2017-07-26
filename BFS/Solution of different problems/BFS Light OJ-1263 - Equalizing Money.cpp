#include<bits/stdc++.h>
using namespace std;
bool visited[1005];
vector<int>edges[1005];
int cost[1005],cc=0,vis=0;
 int check=0;
void Clear(){

    for(int i=0; i<=1005; i++){
        edges[i].clear();
        cost[i]=0;
    }

        cc=0;
        vis=0;
}

void BFS(int s)
{
    queue<int>Q;
    Q.push(s);
    visited[s]=1;
    while(!Q.empty()){
      int u=Q.front();
//        cout<<u<<endl;
        cc+=cost[u];
        vis++;
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

    ios_base::sync_with_stdio(false);
    int test;
    cin>>test;

    for(int t=1; t<=test; t++){


    Clear();
    int n,e,v,u,start;

    cin>>n>>e;

    for(int i=1; i<=n; i++){
       cin>>cost[i];
    }

    for(int i=1; i<=e; i++)
    {
        cin>>u>>v;

        edges[u].push_back(v);
        edges[v].push_back(u);
    }

   vector<int>total;
   memset(visited,0,sizeof(visited));



   cout<<"Case "<<t<<": ";
   for(int i=1; i<=n; i++){

        if(visited[i]==0){
            BFS(i);
       //cout<<cc<<" "<<vis<<endl;
        if(cc%vis==0 and cc>=vis){ total.push_back(cc/vis);}
        else if(cc==0) total.push_back(cc);
        else if(vis==1) total.push_back(cc);
        else{
        check=1;
        cc=0;
        vis=0;
        cout<<"No"<<endl; break;
        }

         cc=0;
         vis=0;
        }

   }
    if(check==0){
    int p=total.size();
    sort(total.begin(),total.end());

    vector<int>::iterator it;

    it=unique(total.begin(),total.end());

    total.resize(distance(total.begin(),it));

     if(total.size()>1) cout<<"No"<<endl;
    else if(total.size()==1) cout<<"Yes"<<endl;

    }

    total.clear();
    check=0;
    }

    return 0;

}


