#include <iostream>
#include <singleton.hpp>
#include <prototype.hpp>
#include <factory.hpp>
#include <Builder.hpp>

using namespace std;

int main ()
{
    cout<<"Builder Pattern"<<endl;

    BuilderDP::Main BuilderDP;
    BuilderDP.execute();

    cout<<endl;

    cout<<"Singleton Pattern"<<endl;

    SingletonDP::Main singletonDP;
    singletonDP.execute(); 

    cout<<endl;

    cout<<"Prototype Pattern"<<endl;

    PrototypeDP::Main prototypeDP;
    prototypeDP.execute();

    cout<<endl;

    cout<<"Factory Pattern"<<endl;

    FactoryDP::Main factoryDP;
    factoryDP.execute();

    cout<<endl;

    std::cout<<"End";

    return 0;
}