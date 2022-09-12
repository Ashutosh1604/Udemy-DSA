#include<bits/stdc++.h>
using namespace std;

//str is the input the string
string compressString(string &str){
    //complete the function to return output string
    string ans="";
    int cnt=0;

   for(int i=0;i<str.size();i++)
   {
       cnt++;

       if(i==str.size()-1 || str[i]!=str[i+1])
       {
           ans=ans+str[i]+to_string(cnt);
           cnt=0;
       }

   }


   return ans;




}

int main()
{
    string str="bbbaaaadexxxxxx";

    string ans=compressString(str);

    cout<<ans;
}
