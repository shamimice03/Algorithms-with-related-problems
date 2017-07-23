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
#define   valid(nx,ny)   nx>=0 && nx<row && ny>=0 && ny<col
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           40
using namespace std;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col;
int h1,h2;
int n1,n2,n3,n4,n5,n6;
char data[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dis[SIZE][SIZE];

int BFS(int sx,int sy){

    memset(visited, false, sizeof(visited));
    memset(dis, false, sizeof(dis));

    queue<pii>q;
    q.push(mp(sx,sy));
    visited[sx][sy]=true;

    while(!q.empty()){

        pii top=q.front();
        q.pop();
        for(int i=0; i<4; i++){

            int nx=top.X+fx[i];
            int ny=top.Y+fy[i];

            if(valid(nx,ny) && visited[nx][ny]==false && data[nx][ny]!='#' && data[nx][ny] != 'm' ){
                visited[nx][ny]=true;
                q.push(mp(nx,ny));
                dis[nx][ny]=1+dis[top.X][top.Y];

                if(data[nx][ny]=='h') return dis[h1][h2];
            }
        }
    }




}


int main(){

   int t;

   cin>>t;

   for(int i=1; i<=t; i++){
    cin>>row>>col;

      for(int j=0; j<row; j++)
      for(int p=0; p<col; p++){
        cin>>data[j][p];
        //dis[j][p]=0;
       if(data[j][p]=='a'){
         n1 = j;
         n2 = p;
       }

       else if(data[j][p]=='b'){
         n3 =j;
         n4 =p;
       }

       else if(data[j][p]=='c'){
         n5 =j;
         n6 =p;
       }
       else if(data[j][p]=='h'){
         h1=j;
         h2=p;
       }

      }
      int a=0,b=0,c=0,mm=0,mp=0;
       BFS(h1,h2);
       a=dis[n1][n2];
       b=dis[n3][n4];
       c=dis[n5][n6];

       mp=max(a,max(b,c));

      printf("Case %d: %d\n",i,mp);
   }

}


