#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 10000000
#define mp make_pair
#define pb push_back
#define loop1(i,n) for(int i=1; i<=(n); i++)
#define loop2(j,n) for(int j=1; j<=(n); j++)
#define loop0(i,n) for(int i=0; i<(n); i++)
#define valid(nx,ny) nx>=1 && nx<=8 && ny>=1 && ny<=8
using namespace std;
int dis[50][50];
int fx[]= {-2,-1, 1, 2, 2, 1,-1,-2};
int fy[]= {-1,-2,-2,-1, 1, 2, 2, 1};

int BFS(int sx, int sy, int dx, int dy){

    loop1(i,8) loop2(j,8){dis[i][j]=inf;}

    dis[sx][sy]=0;

    queue<pii>q;
    q.push(mp(sx,sy));

    while(!q.empty()){

        pii top=q.front();
        q.pop();

        loop0(i,8){
          int nx=fx[i]+top.X;
          int ny=fy[i]+top.Y;

          if(valid(nx,ny) && dis[nx][ny]==inf){
            dis[nx][ny]=dis[top.X][top.Y]+1;
            q.push(mp(nx,ny));
          }

        }
    }
   return dis[dx][dy];

}

int main()
{
    string ss,dd;

    while(cin>>ss>>dd){

     int sx=ss[0]-96;
     int sy=ss[1]-48;

     int dx=dd[0]-96;
     int dy=dd[1]-48;

    cout<<"To get from "<<ss<<" to "<<dd<<" takes "<<BFS(sx,sy,dx,dy)<<" knight moves."<<endl;

}
}


