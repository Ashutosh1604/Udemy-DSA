/*
count frequency of k in a sorted array
*/


#include<bits/stdc++.h>
using namespace std;

/*
using binary search
TC:-log(n)
*/


#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr,int n,int x){

    int s = 0;
    int e = n - 1;

    int ans =  -1;
    while( s <= e){

            int mid=(s+e)/2;

        if(arr[mid] == x){
            ans = mid;
            e = mid - 1;
        }
        else if(arr[mid] < x){
            s = mid + 1;
        }
        else if(arr[mid] > x ){
           e  = mid - 1;
        }

    }
    return ans;
}


int upperBound(vector<int> arr,int n,int x){

    int s = 0;
    int e = n - 1;

    int ans =  -1;
    while( s <= e){
            int mid= (s+e)/2;
        if(arr[mid] == x){
            ans = mid;
            s = mid + 1;
        }

        else if(arr[mid] < x){
            s = mid + 1;
        }
        else if(arr[mid] > x ){
            e = mid - 1;
        }

    }
    return ans;
}







//{ Driver Code Starts.

int main()
{

vector<int> arr={0,1,1,2,3,3,3,3,3,4,5,5,5,10};
int n=arr.size();


cout<< upperBound(arr,n,3)-lowerBound(arr,n,3)+1<<endl;
}





// } Driver Code Ends











