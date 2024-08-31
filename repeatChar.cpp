#include<iostream>
#include<map>

using namespace std;

char intToChar(int num) {
    return static_cast<char>(num + '0');
}

string repeatChar(string s){

    map<char,int> map;
    for(int i=0;i<s.size();i++){
        map[s[i]]++;
    }
    string ans;
    for (auto x : map){
        int i=0;
        ans+=x.first;
        char p = x.second + '0';
        ans+=p;
    }
    return ans;
}


int main(){
    string s;
    cin>>s;
    s=repeatChar(s);
    cout<<s;
}
