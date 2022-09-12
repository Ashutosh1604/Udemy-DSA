
/*
TC:- O(nlogn)

SC:- O(n)
*/

#include<iostream>
using namespace std;


void Merge(int arr[],int l,int mid,int r)
{
    int i=l;
    int j=mid+1;
    int k=l;

    int arr2[r+1];


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


}

void mergeSort(int arr[],int l,int r)
{
    if(l>=r)
    {
        return;
    }
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);

        Merge(arr,l,mid,r);



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


    mergeSort(arr,0,n-1);

       for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }



}
