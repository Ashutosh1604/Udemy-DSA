
/*
*Given an array that was sorted now rotated
*each element of array is unique
*find target element in O(log n)
*return index of target element
*return -1 if not found

*/

/*
approach:- *find the mid if mid is greater than starting element the first half will be the uniform half
           *else if mid is smaller than last element the second half will be the uniform half
        *now find element in that uniform half

         TC:-O(logn)
*/

#include<bits/stdc++.h>
using namespace std;


int searchingInRotated(int arr[],int n,int k)
{
    int l=0;
    int r=n-1;

    while(l<=r)
    {
        int mid=(l+r)/2;

        if(arr[mid]==k)
        {
            return mid;
        }


        if(arr[l]<=arr[mid])
        {
            if(k<=arr[mid] && k>=arr[l])
            {
                r=mid-1;
            }
            else
            {

                l=mid+1;
            }
        }
        else
        {
            if(k>=arr[mid] && k<=arr[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
    }
    return -1;
}
int main()
{
   int n;
   cin>>n;
   int arr[n];

   for(int i=0;i<n;i++)
   {
       cin>>arr[i];
   }

   int k;
   cin>>k;

   cout<<searchingInRotated(arr,n,k);
}
