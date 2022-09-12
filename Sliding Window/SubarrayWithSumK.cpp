/*
eg:- INPUT:- [1,3,2,1,4,1,3,2,1,1,2]
              k=8

    OUTPUT:-  2 5
              4 6
              5 9
*/

#include<bits/stdc++.h>
using namespace std;

//brute force
//O(n^2)
/*
vector<vector<int>>  SubarrayWithSumK(vector<int> arr,int target)
{
    vector<vector<int>> ans;
    int n=arr.size();

for(int i=0;i<n;i++)
{
    int sum=0;
    for(int j=i;j<n;j++)
{


           sum=sum+arr[j];
           if(sum==target)
           {
          ans.push_back({i,j});
           }



    }

}

return ans;
}
*/

//sliding window approach:- put pointer i,j at the starting element find current sum and expand j till sum is smaller than k
//as it become greater than k start contracting window by increasing i and as it become smaller again increase j
//O(n)


vector<vector<int>>  SubarrayWithSumK(vector<int> arr,int target)
{
     vector<vector<int>> res;
    int n=arr.size();
int i=0;
int j=0;

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
    if(sum==target)
    {
        res.push_back({i,j-1});
    }
}

return res;



}
int main()
{
  vector<int> arr={1,3,2,1,4,1,3,2,1,1,2};
    int k=8;

    vector<vector<int>> res=SubarrayWithSumK(arr,k);


    for(auto i:res){
        for(auto j:i)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }


}
