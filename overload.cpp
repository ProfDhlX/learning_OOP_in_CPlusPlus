//function overload
#include<iostream>
using namespace std;
class Overloading
{
    public:
    void add(int x , int y)
    {
          cout<<"First Method called."<<endl;
          cout<<"Sum:"<<x+y<<endl;
    }

    void add(double x , double y)
    {
      cout<<"Second Method called."<<endl;
       cout<<"Sum:"<<x+y<<endl;
    }

    void add(float x , float y,float z)
    {
      cout<<"Third Method called."<<endl;
       cout<<"Sum:"<<x+y+z<<endl;

    }
};

int main()
{
    Overloading obj;
    obj.add(5,6);
    obj.add(3.5,6.523);
    obj.add(3.622f,5.325f,2.36f);
    return 0;
}