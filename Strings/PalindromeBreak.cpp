/*
Given a palindromic string of lowercase English letters palindrome, replace exactly one character with any lowercase English letter so that the resulting string is not a palindrome and that it is the lexicographically smallest one possible.

Return the resulting string. If there is no way to replace a character to make it not a palindrome, return an empty string.

Example-1

Input: palindrome = "abccba"
Output: "aaccba"
Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".

Of all the ways, "aaccba" is the lexicographically smallest.

Example-2

Input: palindrome = "a"
Output: ""
Explanation: There is no way to replace a single character to make "a" not a palindrome, so return an empty string.

Example-3

Input: palindrome = "aa"
Output: "ab"
Example-4

Input: palindrome = "aba"
Output: "abb"

*/

/*logic:- 1.traverse from left to right
          2. the 1st character different from 'a' change that to 'a'
          3. if there are only 'a' than chance the last character to 'b'
          4. aacaa:- if we try to change c it will remain a palindrome so change the last character to 'b'
*/

#include<bits/stdc++.h>
using namespace std;

string breakString(string s)
{
    int n=s.length();
    if(n==1){
        return "";
    }

    for(int i=0;i<n;i++)
    {
           int j=n-1-i;
           if(i==j)
           {
            break;
           }
        if(s[i]!='a')
        {
            s[i]='a';
            return s;
        }
    }

    s[n-1]='b';
    return s;

}
int main()
{

string s="abccba";
cout<<breakString(s);
}











