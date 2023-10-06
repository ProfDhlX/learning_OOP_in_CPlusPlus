//odd even withou modulas operator
#include<iostream>
#include<string>ll

using namespace std;
int main(){
    int a;
    cin>>a;
    int temp = a;
    int ttemp = a/2;

   

    if(ttemp*2 == temp){
        cout<<"Number is even";
    } else{
        cout<<"Number is odd";
    }

    return 0;
    
}