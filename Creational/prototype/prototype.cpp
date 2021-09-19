#include "prototype.hpp"

using namespace PrototypeDP;

Prototype::Prototype(/* args */)
{
}

Prototype::Prototype(const std::string& value)
    : value(value)
{
}

Prototype::~Prototype()
{
}

void Prototype::PrintValue()
{

    std::cout<< "Calling from "<<this->value<<"\n";
}

/*Prototype * Prototype::clone()
{
    return this;
}*/

ConcretePrototype1::ConcretePrototype1()
{
}

ConcretePrototype1::ConcretePrototype1(std::int8_t value_concrete, std::string value)
    : Prototype(value), value_concrete(value_concrete)
{
}

ConcretePrototype1::~ConcretePrototype1()
{
} 

 Prototype * ConcretePrototype1::clone() const
 {

    return new ConcretePrototype1(*this);
 }


ConcretePrototype2::ConcretePrototype2()
{
}

ConcretePrototype2::ConcretePrototype2(std::int8_t value_concrete, std::string value)
    : Prototype(value), value_concrete(value_concrete)
{
}

ConcretePrototype2::~ConcretePrototype2()
{
} 

 Prototype * ConcretePrototype2::clone() const
 {

    return new ConcretePrototype2(*this);
 }

PrototypeFactory::PrototypeFactory()
{
    prototypes_map[PrototypeType::PROTOTYPE_1] = new ConcretePrototype1 (10, "PROTOYPE_1");
    prototypes_map[PrototypeType::PROTOTYPE_2] = new ConcretePrototype2 (10, "PROTOYPE_2");
}

PrototypeFactory::~PrototypeFactory()
{
    delete prototypes_map[PrototypeType::PROTOTYPE_1];
    delete prototypes_map[PrototypeType::PROTOTYPE_2];
}


Prototype *PrototypeFactory::createPrototype(const PrototypeType type)
{
    return prototypes_map[type]->clone();
}

