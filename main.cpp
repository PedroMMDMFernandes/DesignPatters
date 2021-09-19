#include <iostream>
#include "Creational/singleton/singleton.hpp"

using namespace std;

int main ()
{
    cout<<"Hello World"<<endl;


    SingletonDP::Main singletonDP;
    singletonDP.execute(); 

    return 0;
}