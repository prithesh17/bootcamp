#include<iostream>

using namespace std;

pair<int,int> calculate(int vehicles, int wheels){
    int twoWheelers;
    int fourWheelers;
    if(vehicles ==0 || wheels == 0){
        return {0,0};
    }
    fourWheelers = (wheels - 2* vehicles)/2;
    twoWheelers = vehicles - fourWheelers;
    return {twoWheelers,fourWheelers};
}

int main(){
    int wheels, vehicles;
    cin>>vehicles;
    cin>>wheels;
    pair<int,int> result = calculate(vehicles, wheels);
    cout<<"Number of Two Wheelers : "<<result.first<<endl;
    cout<<"Number of Four Wheelers :"<<result.second<<endl;
}
