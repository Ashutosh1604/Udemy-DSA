/*
 first k smallest element
*/

#include<iostream>
using namespace std;


int Partition(int arr[],int l,int r)
{
    int pivot=arr[l];
    int i=l;
    int j=r;

    while(i<j)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }

        while(arr[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[j],arr[l]);

    return j;


}

int quickSelect(int arr[],int l,int r,int k)
{
    //we find the position of pivot

      int p=Partition(arr,l,r);

     //if pivot is at k position it is answer
        if(p==k-1){
            return arr[p];
        }
        else if(k-1<p)   //if pivot is  greater than the ans at k than sort only left part of pivot
        {

        return quickSelect(arr,l,p-1,k);
        }
        else{

        return quickSelect(arr,p+1,r,k);  //if pivot is  smaller than the ans at k than sort only right part of pivot
        }





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

    cout<<quickSelect(arr,0,n-1,k);





}
