/*
a memer function can be called by using its name inside another member function of the same class.
This id known as nesting of member functions
*/
#include<iostream>
using namespace std;
class sicalc{
    private:
    float p,t,r,si;
    public:
    void SI(){
        cout<<"enter principal time and rate :"<<endl;
        cin>>p;
        cout<<"enter time:"<<endl;
        cin>>t;
        cout<<"enter rate:"<<endl;
        cin>>r;
        si=(p*t*r)/100;
        cout<<"SI ="<<si<<endl;
    }
    float findtotal(){
        SI();
        return si+p;
    }
};
int main(){
    sicalc obj;
    float res=obj.findtotal();
    cout<<"TOTAL AMT: "<<res;
    return 0;
}
