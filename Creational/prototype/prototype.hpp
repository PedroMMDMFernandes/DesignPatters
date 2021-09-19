
#include <iostream>
#include <unordered_map>

namespace PrototypeDP
{
    enum PrototypeType
    {
        PROTOTYPE_1 = 0,
        PROTOTYPE_2
    };

    class Prototype
    {
    private:
        /* data */
        std::string value;
    public:
        Prototype(/* args */);
        Prototype(const std::string& value);
        ~Prototype();
        virtual Prototype *clone() const = 0;
        virtual void PrintValue();
    };

    class ConcretePrototype1: public Prototype
    {
    public:
        ConcretePrototype1();
        ConcretePrototype1(std::int8_t value_concrete, std::string value);
        ~ConcretePrototype1();

        Prototype * clone () const override;
    
    private:
        std::int8_t value_concrete;
    };

    class ConcretePrototype2: public Prototype
    {
    public:
        ConcretePrototype2();
        ConcretePrototype2(std::int8_t value_concrete, std::string value);
        ~ConcretePrototype2();

        Prototype * clone () const override;
    
    private:
        std::int8_t value_concrete;
    };

    class PrototypeFactory
    {
        std::unordered_map<PrototypeType, Prototype*, std::hash<int>> prototypes_map;
    public:
        PrototypeFactory();
        ~PrototypeFactory();
           
        Prototype *createPrototype(const PrototypeType type);
        
    };   

    class Main
    {
    public:
        Main() {};
        ~Main(){};

        void execute()
        {
            PrototypeFactory* protoFact = new PrototypeFactory();

            Prototype * conProt1 =  protoFact->createPrototype(PROTOTYPE_1);

            conProt1->PrintValue();

            Prototype * conProt2 =  protoFact->createPrototype(PROTOTYPE_2);

            conProt2->PrintValue();

            delete protoFact;
        }
    
    private:
        
    };
}
