/*
given a sorted array of strings that is having lots of empty string write a method to find location of given string.

eg:- ["ai","","","bat","","","car","cat","","","dog","e"]

    bat
    output:- 4
*/


//we will modify binary search
//find mid if it is empty string update mid to the nearest non empty string by traversing linearly in both directions
//now reduce the search place
#include<bits/stdc++.h>
using namespace std;

int sparseSearch(string arr[],int n,string key)
{
    int s=0;
    int e=n-1;

    while(s<=e)
    {
        int mid=(s+e)/2;


        if(arr[mid]=="")       //if mid is empty string update mid to closest non empty string
        {
            int l=mid-1;
            int r=mid+1;

        while(1)
        {
            if(l<s && r>e)
            {
                return -1;
            }
            else if(r<=e && arr[r]!="")
            {
                mid=r;
                break;
            }
            else if(l>=s && arr[l]!="")
            {
                mid=l;
                break;
            }
            l--;
            r++;

        }

        }
        if(arr[mid]==key)        //if found return inndex
        {
            return mid;
        }
        else if(arr[mid]>key)        //if mid is greater update e
        {
            e=mid-1;
        }
        else{                         //if mid is small update s
            s=mid+1;
        }
    }

}
int main()
{
    string arr[]={"ai","","","bat","","","car","cat","","","dog","e"};
    int n=12;

    cout<<sparseSearch(arr,n,"dog")<<endl;

    return 0;
}
