/*
You are given a sentence with words separated by spaces.

Your task is to:

Write a function that returns a copy of this sentence where all the words:

start with a capital letter

the rest of the letters are lower case

Note:

Your function should not modify the sentence given as argument.

Sample Input

This is SO MUCH FUN!
Sample Output

This Is So Much Fun!
*/

#include<bits/stdc++.h>
using namespace std;


string stringNorm(string s)
{
    int n=s.size();
    int idx=0;

    while(idx<n)
    {
    if(idx<n && s[idx]==' ')
    {
        idx++;
    }

    if(idx<n && s[idx]!=' ')
    {
        s[idx]=toupper(s[idx]);
        idx++;
    }

    while(idx<n && s[idx]!=' ')
    {
        s[idx]=tolower(s[idx]);
        idx++;
    }

    }

    return s;
}
int main()
{

    string s="This is SO MUCH FUN!";

    cout<<stringNorm(s);
}
