/*
                                                ==>>array of object

 in c++ , we can create an array of object just like we create an array of any other data types
 STEPS TO CREATE ARRAY OF OBJECTS
 1) DEFINE a class for the objects that we want to create an array of
 2) Declare an array of that class type
 3) Initialize and work with the individual objects within the array
*/

//EXAMPLE PROGRAM 
#include<iostream>
using namespace std;
class A{
   private:
   int a ,b;
   public:
   void getdata(int x,int y){
    a=x;
    b=y;
   }
   void display(){
    cout<<"a="<<a<<endl;
    cout<<"b="<<b<<endl;
   }
};
int main(){
    A obj[5];
    int i;
    for(i=0;i<5;i++){
        int a,b;
        cout<<"enter a: ";
        cin>>a;
        cout<<"enter b: ";
        cin>>b;
        obj[i].getdata(a,b);
        obj[i].display();
    }
    return 0;
}
