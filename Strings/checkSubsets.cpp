/*
Given two non-empty strings write a function that determines weather the second string is subsequence of first one.


eg:- input:- s1= codingminutes
             s2= cines

      output:- Yes

*/



#include<bits/stdc++.h>
using namespace std;

//1st approach
//take two pointers for s1 ans s2 match all the char of s2 in s1
//if s1 and s2 char match move both pointer
//if not match move s1's pointer
//TC:-O(n)


bool isSubsequence(string s1,string s2)
{
    int i=s1.length()-1;
    int j=s2.length()-1;

    while(i>=0 && j>=0)
    {
       if(s2[j]==s1[i])
       {
           i--;
           j--;
       }
       else{
        i--;
       }
    }

    if(j==-1)         //if j is finished
    {
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    string str1="codingminutes";
    string str2="cines";

    if(isSubsequence(str1,str2))
    {
        cout<<"Yes"<<endl;
    }
    else{

        cout<<"No"<<endl;
    }
}
