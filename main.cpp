#include <iostream>
#include <singleton.hpp>
#include <prototype.hpp>

using namespace std;

int main ()
{
    cout<<"Hello World"<<endl;


    SingletonDP::Main singletonDP;
    singletonDP.execute(); 

    PrototypeDP::Main prototypeDP;
    prototypeDP.execute();
    
    return 0;
}