#include <iostream>
using namespace std;

string replace(string s){
    for(int i=0;i<s.size();i++){
        if(s[i]=='a'){
            s[i]='b';
        }
        else if(s[i]=='b'){
            s[i]='a';
        }
    }
   return s;  
}

int main() {
    string s;
    cin>>s;
    s= replace(s);
    cout<<s;

    return 0;
}