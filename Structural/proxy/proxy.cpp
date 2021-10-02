#include "proxy.hpp"

namespace ProxyDP
{
    ServiceInterface::ServiceInterface()
    {
    }
    
    ServiceInterface::~ServiceInterface()
    {
    }

    Service::Service()
    {
    }
    
    Service::~Service()
    {
    }

    std::string Service::Operation() const
    {
        return "Service Operation ";
    }

    Proxy::Proxy()
    {
    }
    
    Proxy::~Proxy()
    {
    }

    std::string Proxy::Operation() const
    {
        Service service;
        return "Proxy Operation " + service.Operation();
    }

    void Execute()
    {
       Proxy proxy;

       std::cout << proxy.Operation();
    }
}

