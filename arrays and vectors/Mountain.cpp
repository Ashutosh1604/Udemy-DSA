/*
write a function that takes input an array of distinct integers and returns the length of heighest mountain.

* A mountain is defined as adjacent integers that are strictly increasing until they reach a peak at which the become strictly decreasing


At least 3 numbers are required to form a mountain.



eg:-[5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4]
output:- 9


steps:- 1. identify peaks(elements with previous and next elements lesser than that element)
        2. calculate height
*/

//TC:- O(N) as we are going backwards only on peak
#include<bits/stdc++.h>
using namespace std;


int highestMountain(vector<int> arr)
{
    int n=arr.size();
    int largest=0;

    //as 1st and last elements can not be peak
    for(int i=1;i<=n-2;i++)
    {
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
           int cnt=1;
           int j=i;
           while(j>=1 && arr[j]>arr[j-1])
           {
               j--;
               cnt++;
           }
           while(i<=n-2 && arr[i]>arr[i+1])
           {
               i++;
               cnt++;
           }
           largest=max(largest,cnt);

        }

    }
        return largest;

}


int main()
{
    vector<int> arr{5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
    cout<<highestMountain(arr);
}

