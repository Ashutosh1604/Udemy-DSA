/*
for multiple of 3 store "Fizz" instead of number
for multiple of 5 store "Buzz" instead of number
for multiple of both 3 and 5 store "FizzBuzz"
*/

#include<bits/stdc++.h>
using namespace std;


vector<string> fizzBuzz(int n)
{
   vector<string> res;
for(int i=1;i<=n;i++)
{
    if(i%15==0)
    {
        res.push_back("FizzBuzz");
    }
    else if(i%3==0)
    {
        res.push_back("Fizz");
    }
    else if(i%5==0)
    {
        res.push_back("Buzz");
    }
    else{
        res.push_back(to_string(i));
    }
}

return res;
}
int main()
{
vector<string> op=fizzBuzz(20);

 for(string x: op)
 {
     cout<<x<<" , ";
 }

}
