/*
element in output array is equal to the product of every other number in input array accept the current number
solve without using division



*/


#include<bits/stdc++.h>
using namespace std;

//1st approach
//TC:-O(N)
//SC:-O(N)
/*
vector<int> productArray(vector<int> arr){

    int n = arr.size();
      if(n==1)
      {
          return {0};
      }
    vector<int> output(n,1);
      int left[n];
      int right[n];

      left[0]=arr[0];
      for(int i=1;i<=n;i++)
      {
          left[i]=left[i-1]*arr[i];
      }

      right[n-1]=arr[n-1];

      for(int i=n-2;i>=0;i--)
      {
          right[i]=right[i+1]*arr[i];
      }


      for(int i=0;i<n;i++)
      {
          if(i==0)
          {
              output[i]=right[i+1];
          }
          else if(i==n-1)
          {
              output[i]=left[i-1];
          }
          else{
            output[i]=right[i+1]*left[i-1];
          }
      }


      return output;
    }

    */


    //2nd approach
    //TC:-O(N)
    //SC:-O(1)
    vector<int> productArray(vector<int> arr){

    int n = arr.size();
    vector<int> output(n,1);
      if(n==1)
      {
          return {0};
      }
      int product=1;

      for(int i=0;i<n;i++)
      {
          product=product*arr[i];
          output[i]=product;
      }
      product=1;
      for(int i=n-1;i>0;i--)
      {
          output[i]=output[i-1]*product;
          product=product*arr[i];
      }

      output[0]=product;

      return output;
    }

int main()
{
    vector<int> arr={1,2,3,4,5};

    vector<int> op=productArray(arr);

    for(auto it:op)
    {
        cout<<it<<" ";
    }
}





