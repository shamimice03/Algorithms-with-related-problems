#include<bits/stdc++.h>
#define   inf            100000000000000000
#define   X              first
#define   Y              second
#define   B              begin()
#define   E              end()
#define   mp             make_pair
#define   pb             push_back
#define   loop1(i,n)     for(int i=1; i<=(n); i++)
#define   loop2(j,n)     for(int j=1; j<=(n); j++)
#define   loop0(i,n)     for(int i=0; i<(n); i++)
#define   valid(nx,ny)   nx>=1 && nx<=8 && ny>=1 && ny<=8
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           1000+10
using namespace std;

bool prime[100005];
vector<int>prime_fact[100005];
vector<int>data;
int visited[100005];
int dis[100001];

void isprime(){

    memset(prime, true, sizeof(prime));

    for(int i=2; i<=SIZE; i++){
         for(int j=i*2; j<=SIZE; j+=i){
            prime[j]=false;
         }
    }

    for(int i=2; i<=SIZE; i++){
        if(prime[i]==true)
            data.pb(i);
    }

}

void fact(){

      for(int i=2; i<=SIZE; i++){
        for(int j=0; j<data.size(); j++){

            if(i%data[j]==0 and data[j]<i){
                prime_fact[i].pb(data[j]);
            }
        }
      }

}

int bfs(int s, int t){



       memset(visited,0, sizeof(visited));
       visited[s]=1;
       dis[s]=0;
       queue<int>q;
       q.push(s);

       while(!q.empty()){

          int u=q.front();
          q.pop();
          if(u==t) return dis[u];

          for(int i=0; i<prime_fact[u].size(); i++){

              int v=u+prime_fact[u][i];

              if(visited[v]==0){
                q.push(v);
                visited[v]=1;
                dis[v]=1+dis[u];
              }
          }
       }

    return -1;
}


int main()
{
     isprime();
       fact();

    int t,s,test;
      scanf("%d",&test);
    for(int i=1; i<=test; i++){

        scanf("%d %d",&s,&t);

        int q= bfs(s,t);

         printf("Case %d: %d\n",i,q);

    }
}
