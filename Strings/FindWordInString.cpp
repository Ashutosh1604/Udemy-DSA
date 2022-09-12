#include<bits/stdc++.h>
using namespace std;

int main()
{
    string paragraph="We are learning about STL strings. STL string class is quite powerfull";

    string word;
    getline(cin,word);

    vector<int> res;


    //to find the first occurance
    int index=paragraph.find(word);


    while(index!=-1){
      res.push_back(index);
      index=paragraph.find(word,index+1);
    }



   for(int i=0;i<res.size();i++)
   {
       cout<<res[i]<<" ";
   }

}
