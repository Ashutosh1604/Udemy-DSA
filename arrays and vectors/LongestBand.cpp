/*
array=[1,9,3,0,18,5,2,4,10,7,12,6]

output: 8
explaination: largest subset containing consicutive numbers is {0,1,2,3,4,5,6,7}

*/

//1st approach:- sort the array
//TC:-O(nlogn)



//2nd approach
//O(N)
#include<bits/stdc++.h>
using namespace std;


int LongestChain(vector<int> arr)
{
    int maxl=0;

    unordered_set<int> s;

    for(int i=0;i<arr.size();i++)
    {
        s.insert(arr[i]);
    }

    for(int i=0;i<arr.size();i++)
    {
        if(s.find(arr[i]-1)==s.end())   //if there is no element less than the current element
        {
            int currM=1;
            int ele=arr[i];
            while(s.find(ele+1)!=s.end())
            {
                currM++;
                ele++;
            }
               maxl=max(maxl,currM);
        }
    }

    return maxl;
}
int main()
{
    vector<int> arr={1,9,3,0,18,5,2,4,10,7,12,6};

    cout<<LongestChain(arr);
}

