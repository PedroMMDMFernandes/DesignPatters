#include <iostream>
#include "Creational/singleton/singleton.hpp"
#include "Creational/prototype/prototype.hpp"

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