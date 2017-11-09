#include<bits/stdc++.h>
using namespace std;

// Number of Men or Women
#define p 101
int prefer[2*p][p];
int N;

// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int w, int m, int m1)
{
    // Check if w prefers m over her current engagment m1
    for (int i = 1; i <= N; i++)
    {
        // If m1 comes before m in lisr of w, then w prefers her
        // cirrent engagement, don't do anything
        if (prefer[w][i] == m1)
            return true;

        // If m cmes before m1 in w's list, then free her current
        // engagement and engage her with m
        if (prefer[w][i] == m)
           return false;
    }
}

// Prints stable matching for N boys and N girls. Boys are numbered as 0 to
// N-1. Girls are numbereed as N to 2N-1.
void stableMarriage()
{
    // Stores partner of women. This is our output array that
    // stores paing information.  The value of wPartner[i]
    // indicates the partner assigned to woman N+i.  Note that
    // the woman numbers between N and 2*N-1. The value -1
    // indicates that (N+i)'th woman is free
    int wPartner[N+1];

    // An array to store availability of men.  If mFree[i] is
    // false, then man 'i' is free, otherwise engaged.
    bool mFree[N+1];

    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    // While there are free men
    while (freeCount > 0)
    {
        // Pick the first free man (we could pick any)
        int m;
        for (m = 1; m <= N; m++)
            if (mFree[m] == false)
                break;

        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for (int i = 1; i <= N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];

            // The woman of preference is free, w and m become
            // partners (Note that the partnership maybe changed
            // later). So we can say they are engaged not married
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }

            else  // If w is not free
            {
                // Find current engagement of w
                int m1 = wPartner[w-N];

                // If w prefers m over her current engagement m1,
                // then break the engagement between w and m1 and
                // engage m with w.
                if (wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } // End of Else
        } // End of the for loop that goes to all women in m's list
    } // End of main while loop

   vector< pair<int,int> >pa;
    for(int i=1; i<=N; i++)
    {
        pa.push_back({wPartner[i],N+i});
    }

    sort(pa.begin(),pa.end());




   for (int i = 0; i < N; i++)
       printf(" (%d %d)",pa[i].first,pa[i].second);


}

// Driver program to test above functions
int main()
{

    int test,a;

    cin>>test;

    for(int t=1; t<=test; t++){

    cin>>N;

    memset(prefer,0,sizeof(prefer));

    for(int i=1; i<=N; i++){
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
