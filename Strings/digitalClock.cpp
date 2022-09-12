/*
sample input is a integer:- eg- 125
output is a string :-     2:05

eg2- input:- 155
      output:- 2:35


*/


#include<bits/stdc++.h>
using namespace std;

string convert_to_digital_time(int minutes){

  int hrs=minutes/60;
  int mi=minutes%60;

  string m;
  if(mi>=10)
  {
      m=to_string(mi);
  }
  else
  {
      m='0'+to_string(mi);
  }

  string t;
  t=to_string(hrs)+":"+m;

  return t;

}

int main()
{
    int minutes;
    cin>>minutes;
    cout<<convert_to_digital_time(minutes);
}


/*
#include<bits/stdc++.h>
using namespace std;
int space(string &s,int idx){
    while(idx<s.length() && s[idx]==' '){
        idx+=1;
    }
    return idx;
}
int solve(string &s,int idx)
{
    if(idx<s.length()&&s[idx]!=' ')
    {
        s[idx]=toupper(s[idx]);
        idx+=1;
    }
      while(idx<s.length()&&s[idx]!=' ')
    {
        s[idx]=tolower(s[idx]);
        idx+=1;
    }
    return idx;

 }
string normalize(const string &s) {
    string copy = s;
    int idx = 0;
    while (idx <copy.length()){
        idx=space(copy,idx);
        idx=solve(copy,idx);

    }
    return copy;
}

*/
