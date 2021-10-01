
#include <iostream>

namespace FacadeDP
{
    class Subsystem1
    {
    public:
        Subsystem1();
        Subsystem1(Subsystem1 &&) = default;
        Subsystem1(const Subsystem1 &) = default;
        Subsystem1 &operator=(Subsystem1 &&) = default;
        Subsystem1 &operator=(const Subsystem1 &) = default;
        ~Subsystem1();

        std::string CallOperation() const;
    
    private:
        
    };
    


    class Subsystem2
    {
    public:
        Subsystem2();
        Subsystem2(Subsystem2 &&) = default;
        Subsystem2(const Subsystem2 &) = default;
        Subsystem2 &operator=(Subsystem2 &&) = default;
        Subsystem2 &operator=(const Subsystem2 &) = default;
        ~Subsystem2();

        std::string CallOperation() const;
    
    private:
        
    };
    
    class Facade
    {
    public:
        Facade(Subsystem1* subsystem1 = nullptr, Subsystem2* subsystem2 = nullptr);
        Facade(Facade &&) = default;
        Facade(const Facade &) = default;
        Facade &operator=(Facade &&) = default;
        Facade &operator=(const Facade &) = default;
        ~Facade();

        std::string CallSubsystemOperation() const;
    
    private:
        Subsystem1* subsystem1;
        Subsystem2* subsystem2;
    };
    
    void Execute();

}
