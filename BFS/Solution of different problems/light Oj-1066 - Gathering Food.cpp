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
#define   valid(nx,ny)   nx>=0 && nx<col && ny>=0 && ny<col
#define   pii            pair<int, int>
#define   ll             long long
#define   MOD            1000000007
#define   SIZE           25
using namespace std;

int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
int row,col,Alpha=0,f=0;
char data[SIZE][SIZE];
bool visited[SIZE][SIZE];
char pp[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int BFS(int sx, int sy){

    queue<pii>q;
    q.push(mp(sx,sy));
    int m=0;
    int v=1;
    while(!q.empty()){

        pii top=q.front();
        q.pop();
        for(int i=0; i<4; i++){

            int nx=top.X+fx[i];
            int ny=top.Y+fy[i];

            if(valid(nx,ny) and !visited[nx][ny] and data[nx][ny]!='#'){

                q.push(mp(nx,ny));
                m++;

               if(data[nx][ny])

            }
        }
    }

}


int main(){

   int t,x,y;

   cin>>t;

   for(int i=1; i<=t; i++){

    memset(visited, 0, sizeof(visited));
    cin>>col;

      for(int j=0; j<col; j++)
      for(int p=0; p<col; p++){
        cin>>data[j][p];
       if(data[j][p]=='A'){

         visited[j][p]=true;
         x=j;
         y=p;
       }
       if(isalpha(data[j][p])) Alpha++;
      }

      printf("Case %d: ",i);
      cout<<BFS(x,y)<<endl;;
   }

}
