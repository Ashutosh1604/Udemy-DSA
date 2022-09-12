/* Given an integer N and an integer P you need to find the square root of number N upto P places.
Do it without using library function

eg:- N=10 , P=3
output:- 3.162

*/


//apply binary search from start to N for integer part in logN
//total TC:- O(logN + 9P)

#include<bits/stdc++.h>
using namespace std;


float square_root(int N,int p)
{
    int s=0;
    int e=N;

    float ans=0;

    //binary search for integer part
    while(s<=e)
    {
        int mid=(s+e)/2;

        if(mid*mid==N)
        {
            return mid;
        }
        else if(mid*mid<N)
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }

  //liner search for floating part
  float inc=0.1;

   for(int place=1;place<=p;place++)            //for p places
   {
     while(ans*ans <= N)
     {
         ans=ans+inc;         //till its square is smaller or equal keep increasing the number
     }

     //take one step back
     ans=ans-inc;

     inc=inc/10.0;
   }

   return ans;
}
int main()
{

    int n,p;
    cin>>n>>p;

    cout<<square_root(n,p)<<endl;

}

