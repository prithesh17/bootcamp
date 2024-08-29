#include<iostream>

using namespace std;

void printPyramid(int n){
    for(int i = 1 ; i<=n;i++){
        for(int j = 1; j<=n-i;j++){
            cout<<" ";
        }
        for(int k=i;k<i+i;k++){
            cout<<k%10;
        }
        for(int l = i+i-2;l>=i;l--){
            cout<<l%10;
        }
        cout<<endl;
    }
}


int main(){
    int n;
    cin>>n;
    printPyramid(n);
    return 0;
}