#include <iostream>
#include <singleton.hpp>
#include <prototype.hpp>
#include <factory.hpp>
#include <builder.hpp>
#include <abstractFactory.hpp>
#include <adapter.hpp>
#include <bridge.hpp>
#include <composite.hpp>

using namespace std;

int main ()
{
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

    cout<<"Builder Pattern"<<endl;

    BuilderDP::Main BuilderDP;
    BuilderDP.execute();

    
    cout<<"Abstract Factory Pattern"<<endl;
    AbstractFactoryDP::Main abstractFactory;
    abstractFactory.execute();

    cout<<endl;

    cout<<"Adapter Pattern"<<endl;
    AdapterDP::Main adapter;
    adapter.execute();

    cout<<endl;

    cout<<"Bridge Pattern"<<endl;
    BridgeDP::Main bridge;
    bridge.execute();

    cout<<endl;

    cout<<"Composite Pattern"<<endl;
    CompositeDP::Main composite;
    composite.execute();

    cout<<endl;

    std::cout<<"End";

    return 0;
}