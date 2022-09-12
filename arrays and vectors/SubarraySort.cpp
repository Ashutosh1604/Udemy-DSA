/*
Given an array of size at least two find the smallest subarray that needs to be sorted in place so that entire input array becomes sorted

if the input array is already sorted the function should return [-1,-1] otherwise return the start and end index of smallest subarray

    eg:- arr=[1,2,3,4,5,8,6,7,9,10,11]

         output:-[5,7]

*/


#include<bits/stdc++.h>
using namespace std;


bool outOfOrder(vector<int> arr,int i)
{
    int x=arr[i];
    if(i==0)
    {
        return x>arr[i+1];
    }
    if(i==arr.size()-1)
    {
        return x<arr[i-1];
    }
    return x>arr[i+1] || x<arr[i-1];
}


pair<int,int> subarraySort(vector<int> arr)
{

int smallest=INT_MAX;
int largest=INT_MIN;

for(int i=0;i<arr.size();i++)
{   int x=arr[i];
    if(outOfOrder(arr,i))
    {
       smallest=min(smallest,x);
       largest=max(largest,x);
    }
}

if(smallest==INT_MAX)
{
    return {-1,-1};
}

int left=0;
while(smallest>=arr[left])
{
    left++;
}
int right=arr.size()-1;

while(largest<=arr[right])
{
    right--;
}



return {left,right};
}
int main()
{
    vector<int> arr={1,2,3,4,5,8,6,7,9,10,11};

    pair<int,int> p=subarraySort(arr);

    cout<<p.first<<","<<p.second<<endl;
}
