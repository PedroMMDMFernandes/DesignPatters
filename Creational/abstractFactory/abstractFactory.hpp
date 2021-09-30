#include <iostream>

namespace AbstractFactoryDP
{

    class AbstractProductA
    {
    public:
        AbstractProductA();
        AbstractProductA(AbstractProductA &&) = default;
        AbstractProductA(const AbstractProductA &) = default;
        AbstractProductA &operator=(AbstractProductA &&) = default;
        AbstractProductA &operator=(const AbstractProductA &) = default;
        virtual ~AbstractProductA();
        virtual std::string doSomeA() const = 0;
    
    private:
        
    };
    
    class AbstractProductB
    {
    public:
        AbstractProductB();
        AbstractProductB(AbstractProductB &&) = default;
        AbstractProductB(const AbstractProductB &) = default;
        AbstractProductB &operator=(AbstractProductB &&) = default;
        AbstractProductB &operator=(const AbstractProductB &) = default;
        virtual ~AbstractProductB();

        virtual std::string doSomeB(const AbstractProductA &collaborator) const = 0;
    
    private:
        
    };
    
    class AbstractFactory
    {
        public:
            AbstractFactory();
            AbstractFactory(AbstractFactory &&) = default;
            AbstractFactory(const AbstractFactory &) = default;
            AbstractFactory &operator=(AbstractFactory &&) = default;
            AbstractFactory &operator=(const AbstractFactory &) = default;
            ~AbstractFactory();

            virtual AbstractProductA* createProductA(void) = 0;
            virtual AbstractProductB* createProductB(void) = 0;
        
        private:
        
    };

    class ConcreteProductA1: public AbstractProductA
    {
    public:
        ConcreteProductA1();
        ConcreteProductA1(ConcreteProductA1 &&) = default;
        ConcreteProductA1(const ConcreteProductA1 &) = default;
        ConcreteProductA1 &operator=(ConcreteProductA1 &&) = default;
        ConcreteProductA1 &operator=(const ConcreteProductA1 &) = default;
        ~ConcreteProductA1();

        std::string doSomeA() const override;
    
    private:
        
    };

    class ConcreteProductA2: public AbstractProductA
    {
    public:
        ConcreteProductA2();
        ConcreteProductA2(ConcreteProductA2 &&) = default;
        ConcreteProductA2(const ConcreteProductA2 &) = default;
        ConcreteProductA2 &operator=(ConcreteProductA2 &&) = default;
        ConcreteProductA2 &operator=(const ConcreteProductA2 &) = default;
        ~ConcreteProductA2();
    
        std::string doSomeA() const override;
    private:
        
    };
    


    class ConcreteProductB1: public AbstractProductB
    {
    public:
        ConcreteProductB1();
        ConcreteProductB1(ConcreteProductB1 &&) = default;
        ConcreteProductB1(const ConcreteProductB1 &) = default;
        ConcreteProductB1 &operator=(ConcreteProductB1 &&) = default;
        ConcreteProductB1 &operator=(const ConcreteProductB1 &) = default;
        ~ConcreteProductB1();

        std::string doSomeB(const AbstractProductA &collaborator) const override;
    private:
        
    };
    
    class ConcreteProductB2: public AbstractProductB
    {
    public:
        ConcreteProductB2();
        ConcreteProductB2(ConcreteProductB2 &&) = default;
        ConcreteProductB2(const ConcreteProductB2 &) = default;
        ConcreteProductB2 &operator=(ConcreteProductB2 &&) = default;
        ConcreteProductB2 &operator=(const ConcreteProductB2 &) = default;
        ~ConcreteProductB2();
    
        std::string doSomeB(const AbstractProductA &collaborator) const override;
    private:
        
    };
    
    class ConcreteFactory1: public AbstractFactory
    {
    public:
        ConcreteFactory1();
        ConcreteFactory1(ConcreteFactory1 &&) = default;
        ConcreteFactory1(const ConcreteFactory1 &) = default;
        ConcreteFactory1 &operator=(ConcreteFactory1 &&) = default;
        ConcreteFactory1 &operator=(const ConcreteFactory1 &) = default;
        ~ConcreteFactory1();

        AbstractProductA* createProductA(void) override;
        AbstractProductB* createProductB(void) override;

    private:
        
    };

    class ConcreteFactory2 : public AbstractFactory
    {
    public:
        ConcreteFactory2();
        ConcreteFactory2(ConcreteFactory2 &&) = default;
        ConcreteFactory2(const ConcreteFactory2 &) = default;
        ConcreteFactory2 &operator=(ConcreteFactory2 &&) = default;
        ConcreteFactory2 &operator=(const ConcreteFactory2 &) = default;
        ~ConcreteFactory2();

        AbstractProductA* createProductA(void) override;
        AbstractProductB* createProductB(void) override;

    
    private:
        
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
