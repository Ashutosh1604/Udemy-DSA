/*Given an array containing N integers and an number S denoting target sum


Find all distinct integers that can add up to form target sum the nu. in each
triplet should be ordered in ascending order and triplets should be ordered too.

return empty array if no such triplets exist

eg:- arr=[1,2,3,4,5,6,7,8,9,15]
   target=18
   output:- [[1,2,15],
            [3,7,8],
            [4,6,8],
            [5,6,7]]

*/

#include<bits/stdc++.h>
using namespace std;

//1st approach
//TC:- O(n^3)
//using triple loop

//2nd approach
//TC:-O(n^2)  SC:-O(n^2)
//find difference of sum and 1st element in the loop and find the pair sum in the rest part
/*

  vector<vector<int>> triplets(vector<int> arr,int S)
  {
        vector<vector<int>> ans;
        int n=arr.size();

        for(int i=0;i<n;i++)
        {
            int diff=S-arr[i];
            unordered_set<int> s;

            for(int j=i+1;j<=n;j++)
            {
                int d=diff-arr[j];
                if(s.find(d)!=s.end())
                {
                      ans.push_back({arr[i],d,arr[j]});

                }
                else
                {
                    s.insert(arr[j]);
                }
            }
        }

        return ans;

  }
*/


//3rd approach
//TC:-O(nlogn)


vector<vector<int>>triplets(vector<int> arr,int S)
{
    vector<vector<int>> res;
    sort(arr.begin(),arr.end());

    for(int i=0;i<arr.size();i++)
    {
        int s=i+1;
        int e=arr.size()-1;
        while(s<e)
        {
            if(arr[i]+arr[s]+arr[e]==S)
            {
                res.push_back({arr[i],arr[s],arr[e]});
                s++;
                e--;


            }
            else if(arr[i]+arr[s]+arr[e]>S)
            {
                e--;
            }
            else{
                s++;
            }
        }
    }

    return res;
}
int main()
{
    vector<int> arr{1,2,3,4,5,6,7,8,9,15};
    int S=18;

    vector<vector<int>> res=triplets(arr,S);

    for(auto i:res){
        for(auto j:i)
        {
            cout<<j<<",";
        }
        cout<<endl;
    }



}


