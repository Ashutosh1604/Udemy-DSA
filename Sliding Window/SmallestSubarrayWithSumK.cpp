#include<bits/stdc++.h>
using namespace std;


void  SubarrayWithSumK(vector<int> arr,int target)
{

    int minsub=INT_MAX;    //min size subarray
    int n=arr.size();
int i=0; //pointers
int j=0;

int min_i=INT_MAX;      //index for smallest lenghth subarray
int min_j=INT_MAX;
int sum=0;

while(j<n)
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

    if(sum==target && j-i < minsub)
    {
         minsub=j-i;
         min_i=i;
         min_j=j-1;
    }

}

cout<<min_i<<" "<<min_j<<endl;



}
int main()
{
  vector<int> arr={1,3,2,1,4,1,3,2,1,1,2};
    int k=8;

    SubarrayWithSumK(arr,k);


    }







