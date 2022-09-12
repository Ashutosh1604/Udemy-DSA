

/*
Given an array of size N find the min number of swaps needed to make the array as sorted


eg:- [10,11,5,4,3,2,1]
      output:-4

      algo:- 1. store the element and its index in pair vector
             2. sort it using sort function
             3. iterate sorted pair vector and check if stored index is equal to the index
             4.if equal= element was in correct position if not than swap it with the element at the index stored with it
             5. check the new value again

*/

//TC:-O(nlogn)
#include<bits/stdc++.h>
using namespace std;



int minSwaps(vector<int> arr)
{
    int n=arr.size();
    vector<pair<int,int>> v(n);

    for(int i=0;i<n;i++)
    {
        v[i]={arr[i],i};
    }

    sort(v.begin(),v.end());

    int ans=0;

    for(int i=0;i<n;i++)
    {
        if(v[i].second!=i)
        {
            ans++;
            swap(v[i],v[v[i].second]);
            i--; //to check new value
        }
    }


    return ans;
}
int main()
{
    vector<int> arr={10,11,5,4,3,2,1};
    cout<<minSwaps(arr);
}







