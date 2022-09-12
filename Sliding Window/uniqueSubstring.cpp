//Given a string write a function to find the largest substring with unique characters(no duplicates)
//eg1:-prateekbhaiya       sol:- ekbhaiy
//eg2:- aabcb              sol:-abc



//if current char is part of the window start new window form index+1 element was there (use array or map)
//if current char is not part of window expand window


#include<bits/stdc++.h>
using namespace std;

string unique_substr(string str)
{
    unordered_map<char,int> mp;
    int i=0;
    int j=0;

    int window_len=0;
    int max_window_len=0;
    int start_window=-1;

    while(j<str.size())
    {
        char ch =str[j];
        //if it is in hashmap and its idx >= start of window (it as occured and is inside window)
        if(mp. find(ch)!=mp.end() && mp[ch]>=i)
        {
            i=mp[ch]+1;
            window_len=j-i;

        }

        //update last occurance
        mp[ch]=j;
        window_len++;
        j++;

        //update max window_len at every step
        if(window_len>max_window_len)
        {
            max_window_len=window_len;
            start_window=i;
        }

    }


    return str.substr(start_window,max_window_len);
}
int main()
{
string input;
cin>>input;

cout<<unique_substr(input);


}
