/*
find pair of numbers(one from each array) who's absolute difference is closest to zero and returns a pair
containing these two numbers with first number from array.Only one such pair exist for the test

*/

#include<bits/stdc++.h>

using namespace std;


pair<int,int> minDifference(vector<int> a,vector<int> b){
    int n1=a.size();
    int n2=b.size();

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());


    int minD=INT_MAX;

    int i=0;
    int j=0;

    int f;
    int s;
    while(i<n1 && j<n2)
    {
        if(abs(a[i]-b[j])<minD)
        {
            minD=abs(a[i]-b[j]);
            f=a[i];
            s=b[j];

        }
        if(a[i]>b[j])
        {
            j++;
        }
        else
        {
            i++;
        }
    }

    return {f,s};
}

int main()
{
    vector<int> a={23,5,10,17,30};
    vector<int> b={26,134,135,14,19};

     pair<int,int> p=minDifference(a,b);
     cout<<p.first<<","<<p.second<<endl;
}









