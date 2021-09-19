#include "singleton.hpp" 

using namespace SingletonDP;
Singleton* Singleton::instance{nullptr};

Singleton::Singleton(const std::string data)
: data{data}
{
    
}

Singleton::~Singleton()
{
}

Singleton* Singleton::getInstance(const std::string& data)
{
    if (instance == nullptr)
    {
        instance = new Singleton(data);
    }

    return instance;
}

std::string Singleton::getValue()
{
    return data;
}

