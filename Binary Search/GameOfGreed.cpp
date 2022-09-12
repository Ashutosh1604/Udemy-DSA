/*
Game of Greed
You are playing a game with your 'k' friends. You have an array of N coins, at each index i you have a coin of value a[i].
Your task is to divide the coins, among a group of K friends by doing consecutive segments (k-subarrays) of the array.
Each friend will get a total sum of the coins in that subarray. Since all your friends are greedy, and they will pick the largest k-1 segments and you will get the smallest segment. Find out the maximum value you can make by making an optimal partition.

Note : The coins array may or may not be sorted!

(Refer Hints at the end if needed)


Input

K = 3
coins = {1,2,3,4};
Output

3

Explanation
The ideal partition looks like this -

{1 + 2} = 3

{3} = 3

{4} = 4

You will get a maximum of 3 coins in the best case
*/

#include<bits/stdc++.h>
using namespace std;



bool divideAmongK(int arr[],int n,int k,int min_coins)
{
    int partions=0;
    int current_friend=0;

    for(int i=0;i<n;i++)
    {
    if(current_friend+arr[i]>=min_coins)
    {
        partions++;
        current_friend=0;
    }
    else
    {

        current_friend=current_friend + arr[i];
    }


    }

    return partions>=k;   //return true if partions is greater than equal to k

}
int k_partition(int arr[],int n,int k)
{
    int s=0;
    int e=0;
    for(int i=0;i<n;i++)
    {
        e=e+arr[i];
    }

   int ans;
    while(s<=e){
        int mid=(s+e)/2;

        bool isPossible=divideAmongK(arr,n,k,mid);

        if(isPossible)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

    return ans;
}
int main()
{
int a[]={1,2,3,4};
int n=4;
int k=3;

cout<<k_partition(a,n,k)<<endl;
}
