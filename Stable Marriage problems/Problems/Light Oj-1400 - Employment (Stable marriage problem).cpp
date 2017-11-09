#include<bits/stdc++.h>
using namespace std;

#define p 101
int prefer[2*p][p];
int N;


bool wPrefersM1OverM(int w, int m, int m1)
{

    for (int i = 1; i <= N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void stableMarriage()
{

    int wPartner[N+1];

    bool mFree[N+1];

    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    while (freeCount > 0)
    {
        int m;
        for (m = 1; m <= N; m++)
            if (mFree[m] == false)
                break;
        for (int i = 1; i <= N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];


            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else
            {

                int m1 = wPartner[w-N];

                if (wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            }
        }
    }

 for (int i = 1; i <= N; i++)
       printf(" (%d %d)",wPartner[i],N+i);



}


int main()
{

    int test,a;

    cin>>test;

    for(int t=1; t<=test; t++){

    cin>>N;

    memset(prefer,0,sizeof(prefer));

    for(int i=1; i<=N*2; i++){
        for(int j=1; j<=N; j++){
           cin>>a;
           prefer[i][j] = a;
        }
    }

    printf("Case %d:",t);
    stableMarriage();
     cout<<endl;
    }

    return 0;
}

