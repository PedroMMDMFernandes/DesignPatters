#include "adapter.hpp"
#include <string>


namespace AdapterDP
{

    ClientInterface::ClientInterface()
    {
    }

    ClientInterface::~ClientInterface()
    {
    }

    Adaptee::Adaptee()
    {
        
    }

    Adaptee::~Adaptee()
    {

    }

    void Adaptee::serviceMethod(int data)
    {
        std::cout<<"Number: "<<data<<std::endl;
    }

    Adapter::Adapter(Adaptee* adaptee)
    {
        this->adaptee = new Adaptee;
    }

    Adapter::~Adapter()
    {
        delete this->adaptee;
    }

    void Adapter::method(std::string data) const 
    {
        int number = std::stoi(data);
        this->adaptee->serviceMethod(number);
    }

    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        Adaptee* adaptee = new Adaptee;
        ClientInterface* clientInt = new Adapter(adaptee);

        std::cout << "Adaptee original output by providing an int" <<std::endl;

        adaptee->serviceMethod(1);

        std::cout << "Adapter output by providing a string" <<std::endl;

        clientInt->method("2"); 

        delete adaptee;
        delete clientInt;
    }
}


