#include <iostream>

namespace AdapterDP
{
    class ClientInterface
    {
    public:
        ClientInterface();
        ClientInterface(ClientInterface &&) = default;
        ClientInterface(const ClientInterface &) = default;
        ClientInterface &operator=(ClientInterface &&) = default;
        ClientInterface &operator=(const ClientInterface &) = default;
        ~ClientInterface();

        virtual void method(std::string data) const = 0;
    
    private:
        
    };

    class Adaptee
    {
    public:
        Adaptee();
        Adaptee(Adaptee &&) = default;
        Adaptee(const Adaptee &) = default;
        Adaptee &operator=(Adaptee &&) = default;
        Adaptee &operator=(const Adaptee &) = default;
        ~Adaptee();

        void serviceMethod(int data);
    
    private:
        
    };
       
    class Adapter: public ClientInterface
    {
    public:
        Adapter(Adaptee* adaptee);
        Adapter(Adapter &&) = default;
        Adapter(const Adapter &) = default;
        Adapter &operator=(Adapter &&) = default;
        Adapter &operator=(const Adapter &) = default;
        ~Adapter();

        void method(std::string data) const override;
    
    private:
        Adaptee* adaptee;
    };

    class Main
    {
    public:
        Main();
        Main(Main &&) = default;
        Main(const Main &) = default;
        Main &operator=(Main &&) = default;
        Main &operator=(const Main &) = default;
        ~Main();

        void execute(void);
    
    private:
        
    };
}



