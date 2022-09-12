/*
Given a ladder containing N steps you can take a jump of 1,2 or 3 at each step.
find the number of ways to climb the ladder.

eg:- N=4
   output:- 7
*/

//TC:- O(3^N)
//its pretty bad complaxity
#include<bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return 1;
    }

    return countWays(n-1)+countWays(n-2)+countWays(n-3);
}

int main()
{
    int n;
    cin>>n;
    cout<<"there are "<<countWays(n)<<" ways to climb"<<endl;
}
