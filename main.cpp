#include <iostream>
#include <singleton.hpp>
#include <prototype.hpp>
#include <factory.hpp>
#include <builder.hpp>
#include <abstractFactory.hpp>
#include <adapter.hpp>
#include <bridge.hpp>
#include <composite.hpp>
#include <decorator.hpp>
#include <facade.hpp>
#include <flyweight.hpp>
#include <proxy.hpp>


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

    cout<<"Decorator Pattern"<<endl;
    DecoratorDP::executeStatic();

    cout<<endl;

    cout<<"Facade Pattern"<<endl;
    FacadeDP::Execute();

    cout<<endl;

    cout<<"Flyweight Pattern\n";
    FlyweightDP::Execute();

    cout<<endl;
    cout<<endl;

    cout<<"Proxy Pattern\n";
    ProxyDP::Execute();

    cout<<endl;

    std::cout<<"End";

    return 0;
}