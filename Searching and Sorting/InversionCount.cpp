/*
Given an array containing integers you need to count the total number of inversions.

inversion:- two elements a[i] and a[j] form an inversion if a[i] > a[j] and i<j

eg:-0,5,2,3,1
 output:- 5

*/














//1.  bruteforce
//TC:-O(n^2)
/*


#include<bits/stdc++.h>
using namespace std;

int inversions(vector<int> arr)
{
    int n=arr.size();
    int ans=0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<=n-1;j++)
        {
            if(arr[i]>arr[j])
            {
                ans++;
            }
        }
    }


    return ans;
}



int main(){
vector<int> arr={0,5,2,3,1};

cout<<inversions(arr);

}
*/














//2.  using merge sort
/*divide:-0,5,2,3,1
c1:- 0,5,2,
c2:- 3,1
total inversions:- c1 +c2 +cross inversion

while applying merge sort in the merge process whenever something come from right everything on the right of the pointer of the left gets added to  the
    count of inversion

    drawback:- it will modify the array if we don't want that we can create a copy of that array

    TC:- nlogn
    SC:- O(n)
*/


#include<bits/stdc++.h>
using namespace std;


int Merge(int arr[],int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=l;

    int arr2[r+1];

    int cnt=0;

    while(i<=mid && j<=r)
    {
        if(arr[i]<=arr[j])
        {
          arr2[k]=arr[i];
          i++;
        }
        else
        {
            arr2[k]=arr[j];
            j++;

            cnt=cnt + (mid-i+1); //whenever something come from right everything on the right of the pointer of the left gets added to  the count of inversion

        }
        k++;
    }

    while(i<=mid)
    {
        arr2[k]=arr[i];
        i++;
        k++;
    }

     while(j<=r)
    {
        arr2[k]=arr[j];
        j++;
        k++;
    }


    for(int k=l;k<=r;k++)
    {
        arr[k]=arr2[k];
    }


    return cnt;

}

int InversionCnt(int arr[],int l,int r)
{
    if(l>=r)
    {
        return 0;
    }
        int mid=(l+r)/2;
       int c1= InversionCnt(arr,l,mid);
       int c2= InversionCnt(arr,mid+1,r);


       int ci= Merge(arr,l,mid,r);

        return c1 + c2 + ci;

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


    cout<<InversionCnt(arr,0,n-1);




}


