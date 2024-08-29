#include <iostream>
using namespace std;

float autofare(float distance, float minutes, float luggageWeight){
    float minDistance = 1.6;
    float basicFare = 35;
    float chargePerKm = 10;
    float chargePerMinutes = 1;
    float chargePerKg = 0.5;
   

    if(distance <= minDistance){
        return basicFare + minutes*chargePerMinutes+ luggageWeight*chargePerKg;
    }else{
        distance = distance - minDistance;
        return  basicFare + distance*chargePerKm + minutes*chargePerMinutes+ luggageWeight*chargePerKg;
    }
}

int main() {
    float a, b, c;
    cin>>a;
    cin>>b;
    cin>>c;
    float result= autofare(a,b,c);
    cout<<"The result is calculated using the below formula"<<endl;
    cout<<"Minimum Fare + (distance travelled * Charge per Kilo meter) + (Number of waiting minutes * Charge per Waiting minute)* (Weight of the Luggage * Charge Per Kilo Gram )"<<endl;
    cout<<"The Total Auto Fare is : "<<result;
    return 0;
}
