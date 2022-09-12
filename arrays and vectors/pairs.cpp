/*
Given an array containing N integers and an number S denoting target sum.

find two distinct integers that can pair up to form target sum. Let us assume there will be only one such pair.

input: array=[10,5,2,3,-6,9,11]
S=4

output: [10,-6]
*/



#include<bits/stdc++.h>
using namespace std;



//1st approach
//TC:- O(n^2)
/*
vector<int> pairSum(vector<int> arr,int S)
{
    vector<int> res;
    for(int i=0;i<arr.size();i++)
    {
        for(int j=1;i<=arr.size();j++)
        {
            if(arr[i]+arr[j]==S)
            {
                res.push_back(arr[i]);
                res.push_back(arr[j]);
                 return res;
            }
        }
    }

    return {};


}

*/







//2nd approach
//TC:- O(nlogn)

/*
vector<int> pairSum(vector<int> arr,int S)
{
    vector<int> res;
        sort(arr.begin(),arr.end());

        for(int i=0;i<arr.size();i++)
        {
            int diff=S-arr[i];
            int s=0;
         int e=arr.size()-1;

            while(s<e)
            {
                int mid=(s+e)/2;

                if(arr[mid]==diff)
                {
                   res.push_back(diff);
                   res.push_back(arr[i]);
                   return res;
                }
                else if(arr[mid]<diff)
                {
                    s=mid+1;
                }
                else{
                    e=mid-1;
                }
            }

        }

        return {};

}

*/




//3rd approach
//TC:- O(n)

vector<int> pairSum(vector<int> arr,int S)
{    unordered_set<int> s;

     vector<int> res;

     for(int i=0;i<arr.size();i++)
     {
         int diff=S-arr[i];
         if(s.find(diff)!=s.end())
         {
              res.push_back(diff);
            res.push_back(arr[i]);
            return res;

         }
         else{
            s.insert(arr[i]);
         }
     }

return {};

}

int main()
{
    vector<int> arr{10,5,2,3,-6,9,11};
    int S=4;

    vector<int> p=pairSum(arr,S);

    if(p.size()==0)
    {
        cout<<"no such pair";
    }
    else
    {
        cout<<p[0]<<","<<p[1];
    }
}

