/*
there is a long wire at straight line which contains N bird nests at position x1,x2...xN.

There are B(B<=N) birds which become angry once put into a nest.assign them such that minimum distance
between any two birds is as large as possible. what is the largest minimum distance.

eg:- N=5 (nests)
    B=3 (Birds)
    Nests=[1,2,4,8,9]   (coordinates of nests)

    output:-3
*/

#include<bits/stdc++.h>
using namespace std;

bool canPlaceBirds(int B,int N,vector<int> nests,int sep)
{
    //put 1st bird at 1st location
    int birds=1;
    int location=nests[0];

    for(int i=1;i<=N-1;i++)
    {
        int current_location=nests[i];
        if(current_location-location >= sep)
        {
            birds++;
            location=current_location;

            if(birds==B)
            {
                return true;
            }
        }
    }
    return false;

}
int main()
{
    int B=3;
    vector<int> nests{1,2,4,8,9};

    sort(nests.begin(),nests.end());

    int N=nests.size();

    int s=0;
    int e=nests[N-1]-nests[0];
    int ans=-1;

    while(s<=e)
    {
        int mid=(s+e)/2;

        bool canPlace=canPlaceBirds(B,N,nests,mid);

        if(canPlace)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    cout<<ans;
}
