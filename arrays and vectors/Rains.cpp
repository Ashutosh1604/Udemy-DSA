/*
Given n non-negative integers representing an elevation map where the width of each bar is 1
compute how much water it can trap after raining

eg:- height-{0,1,0,2,1,0,1,3,2,1,2,1}
     output:-6


explain:- what will be water trap between  1. (6,3):- find min of both that is 3
                                           2. (6,2,2,4):-max at left is 6 and max at right is 4 than min of both 6 and 4 is 4

approach:- * find highest bar at the left and right and find min of both subtract the current bar
           * water store by block =minimum of longest tower from left and right -  height of tower
*/

#include<bits/stdc++.h>
using namespace std;

int trappedWater(vector<int> height)
{
    int n=height.size();

    if(n<=2){
        return 0;
    }
    int left[n];
    int right[n];

    left[0]=height[0];     //store the 1st element of array as current longest from left

    for(int i=1;i<=n;i++)
    {
        left[i]=max(left[i-1],height[i]);
    }

    right[n-1]=height[n-1];      //store the 1st element of array as current longest from right

    for(int i=n-2;i>=0;i--)
    {
        right[i]=max(right[i+1],height[i]);
    }

    int ans=0;
    for(int i=0;i<n;i++)
    {
       ans=ans+  min(left[i],right[i])-height[i];
    }


    return ans;

}
int main()
{
    vector<int> height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<trappedWater(height)<<endl;

}
