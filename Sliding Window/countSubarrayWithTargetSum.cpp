
/*
eg:- INPUT:- [1,3,2,1,4,1,3,2,1,1,2]
              k=8

    OUTPUT:-  2 5
              4 6
              5 9
*/

#include<bits/stdc++.h>
using namespace std;



int  SubarrayWithSumK(vector<int> arr,int target)
{

    int n=arr.size();
int i=0;
int j=0;

int sum=0;
int ans=0;

while(j<n )
{
    //expand to right
    sum=sum+arr[j];
    j++;


    //when sum is greater than target contract window
    while( sum>target && i<j)
    {
        sum=sum-arr[i];
        i++;
    }

    //when sum is equal to target
    if(sum==target )
    {
        ans++;

    }
}

return ans;



}
int main()
{
  vector<int> arr={10,2,-2,-20,10};
    int k=-10;
    cout<<SubarrayWithSumK(arr,k);



}
