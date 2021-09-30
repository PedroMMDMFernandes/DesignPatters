#include <iostream>
#include <singleton.hpp>
#include <prototype.hpp>
#include <factory.hpp>

using namespace std;

int main ()
{
    cout<<"Hello World"<<endl;


    SingletonDP::Main singletonDP;
    singletonDP.execute(); 

    PrototypeDP::Main prototypeDP;
    prototypeDP.execute();

    FactoryDP::Main factoryDP;
    factoryDP.execute();

    
    return 0;
}