/*
n strings are given we have to concatenate them together int some order such that the resulting string would be lexicographically smallest.
Given the list of strings output the lexicographically smallest concatenation.

eg:- a  , ab , aba

output:-aabaab  ("a" +"aba"+"ab")
*/


#include<bits/stdc++.h>
using namespace std;



bool compare(string x,string y)
{
    return x+y < y+x;
}


int main()
{

    string arr[]={"a","ab","aba"};
    int n=3;


    sort(arr,arr+n,compare);

    for(auto i: arr)
    {
        cout<<i;
    }
}
