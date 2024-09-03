#include<iostream>
#include<vector>

using namespace std;

string reverse(string s, int left, int right){
    if(left>=right){
        return s;
    }
    char ch = s[left];
    s[left]=s[right];
    s[right]=ch;
    return reverse(s,++left,--right);
}


int main(){
    string s;
    cin>>s;
    cout<<reverse(s,0,s.size()-1);
}