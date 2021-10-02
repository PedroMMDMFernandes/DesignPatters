#include <iostream>

namespace ProxyDP
{
    class ServiceInterface
    {
    public:
        ServiceInterface();
        ServiceInterface(ServiceInterface &&) = default;
        ServiceInterface(const ServiceInterface &) = default;
        ServiceInterface &operator=(ServiceInterface &&) = default;
        ServiceInterface &operator=(const ServiceInterface &) = default;
        ~ServiceInterface();

        virtual std::string Operation() const = 0;
    
    private:
        
    };

    class Service: public ServiceInterface
    {
    public:
        Service();
        Service(Service &&) = default;
        Service(const Service &) = default;
        Service &operator=(Service &&) = default;
        Service &operator=(const Service &) = default;
        ~Service();

        std::string Operation() const;
    
    private:
        
    };
    
    class Proxy: public ServiceInterface
    {
    public:
        Proxy();
        Proxy(Proxy &&) = default;
        Proxy(const Proxy &) = default;
        Proxy &operator=(Proxy &&) = default;
        Proxy &operator=(const Proxy &) = default;
        ~Proxy();

        std::string Operation() const;
    
    private:
        
    };
    
    void Execute();
}


