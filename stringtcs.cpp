#include<iostream>

using namespace std;

int strFunction(string s){
    int starCount=0;
    int hashCount=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='*') starCount++;
        else if(s[i]=='#') hashCount++;
    }
     return starCount - hashCount;
}


int main(){
    string s;
    cin>>s;
    cout<<strFunction(s);
}