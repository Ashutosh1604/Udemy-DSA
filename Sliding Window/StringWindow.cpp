/*
Given two string one big and one small string, find the smallest window in the big string that contains all characters of the small string.

-window can have additional characters than required
-if small string has duplicates,then those duplicates must be present with same or higher count in window



eg1:- s1=hello_world
      s2=lol
       output= llo

eg2:- s1=fizzbuzz
      s2=fuzz
      output= fizzbu
*/


#include<bits/stdc++.h>
using namespace std;

//store s2 frequency pattern in map
//store window pattern in another map
//match if s2 pattern is present in window pattern
//remove unnecessary elements
string stringWindow(string s,string p)
{
    //array as freq map
    int FP[256]={0};   //freq of p
    int FS[256]={0};   //freq of s

    for(int i=0;i<p.length();i++)
    {
        FP[p[i]]++;

    }

 //sliding window algo

    int cnt=0;   //how many p characters have matched
    int start=0;  //left contraction
    int start_idx=-1;  //start idx for best window
    int min_so_far=INT_MAX;
    int window_size;


    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
 //expand the window by including current character
     FS[ch]++;

     //count how many characters have been matched till now (string and pattern)
     if(FP[ch]!=0 && FS[ch]<=FP[ch])   //if char is present in p and its freq in window is smaller or equal to pattern
     {
         cnt++;
     }

     //contraction
     //if all characters of pattern are found in the current window then you can start contracting
     if(cnt==p.length())
     {
         //start contracting from left to remove unwanted character(not present in pattern or freq is heigher than required)
         while(FP[s[start]]==0 || FS[s[start]] > FP[s[start]])
         {
             FS[s[start]]--;
             start++;

         }

         //note window size
         window_size=i-start+1;
         if(window_size<min_so_far)
         {
             min_so_far=window_size;
             start_idx=start;
         }
     }

    }

    if(start_idx==-1){
        return "NO Window Found";

    }
    return s.substr(start_idx,min_so_far);
}

int main()
{
    string s,p;
    cin>>s>>p;

    cout<<stringWindow(s,p)<<endl;
}


