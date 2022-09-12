/*
Given two non-empty arrays, find the pair of numbers (one from each array)whose absolute difference is minimum.
print the any one pair the smallest difference.

eg:- a1=[-1,5,10,20,3]
    a2=[26,134,135,15,17]

    output:- [20,17]
*/


//sort a2 and traverse a1 and find which number is closest to that element in a2(using lowerbound) ans find difference
//TC:-O(MlogM + NlogM)
#include<bits/stdc++.h>
using namespace std;

void min_pair(vector<int> a1,vector<int> a2)
{

//sort a2
sort(a2.begin(),a2.end());
int p1,p2;
int diff=INT_MAX;

//iterate over 1st array and look for closest element in the second array
for(int i=0;i<a1.size();i++)
{
    int lb=lower_bound(a2.begin(),a2.end(),a1[i])-a2.begin();

    //left
    if(lb>=1 && a1[i]-a2[lb-1]<diff)
    {
        diff=a1[i]-a2[lb-1];
        p2=a1[i];
        p1=a2[lb-1];
    }

      //right
    if(lb!=a2.size() && a2[lb]-a1[i]<diff)
    {

        diff=a2[lb]-a1[i];
        p1=a1[i];
        p2=a2[lb];
    }
}

cout<<"min pair "<<p1<<" and "<<p2;

}

int main()
{
    vector<int> a1={-1,5,10,20,3};
    vector<int> a2={26,134,135,15,17};

    min_pair(a1,a2);


}
