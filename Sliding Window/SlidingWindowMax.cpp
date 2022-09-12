#include<bits/stdc++.h>
using namespace std;


vector<int> maxInWindow(vector<int> a,int k)
{
    vector<int> ans;
    int n=a.size();
    int i=0;
    int j=0;
  int    maxele=INT_MIN;
    int cnt=0;

    while(j<n)
    {

       maxele=max(maxele,a[j]);
       j++;
       cnt++;

       if(cnt==k)
       {
           ans.push_back(maxele);
           maxele=INT_MIN;
           cnt=0;
           i++;
           j=i;

       }
    }

    return ans;
}
int main()
{
    vector<int> a={1, 2, 3, 1, 4, 5, 2, 3, 6};
    int k=3;

    vector<int> ans=maxInWindow(a,k);

    for(auto i: ans)
    {
        cout<<i<<" ";
    }
}



