#include "builder.hpp"

namespace BuilderDP
{
    Builder::Builder()
    {
    }
    
    Builder::~Builder()
    {
    }

    Product1::Product1()
    {
    }
    
    Product1::~Product1()
    {
    }

    
    void Product1::setParts(std::string part)
    {
        bool isContained = false;
        for (size_t i = 0; i < product_parts.size(); i++)
        {
            if(product_parts[i] == part)
            {
                isContained = true;
            }
        }

        if(!isContained)
        {
            product_parts.push_back(part);
        }    
    }

    void Product1::listParts()
    {
        std::cout<<"Produt1 parts: ";
        for (size_t i = 0; i <  product_parts.size(); i++)
        {
            /* code */
            std::cout << product_parts[i] << " ";
        }

        std::cout << std::endl;
    }

    Product2::Product2()
    {
    }
    
    Product2::~Product2()
    {
        
    }

    ConcreteBuilder1::ConcreteBuilder1()
    {
    }
    
    ConcreteBuilder1::~ConcreteBuilder1()
    {
        delete result;
    }

    void ConcreteBuilder1::reset() 
    {
        result = new Product1();
    }
    
    void ConcreteBuilder1::buildStepA() const
    {
        result->setParts("StepA");
    }

    void ConcreteBuilder1::buildStepB() const
    {
        result->setParts("StepB");
    }

    void ConcreteBuilder1::buildStepC() const
    {
        result->setParts("StepC");
    }

    Product1* ConcreteBuilder1::getResult()
    {
        return result;
    }

    ConcreteBuilder2::ConcreteBuilder2()
    {
    }
    
    ConcreteBuilder2::~ConcreteBuilder2()
    {
        delete result;
    }

    void ConcreteBuilder2::reset()
    {
        result = new Product2();
    }
    
    void ConcreteBuilder2::buildStepA() const
    {

    }

    void ConcreteBuilder2::buildStepB() const
    {

    }

    void ConcreteBuilder2::buildStepC() const
    {

    }

    Product2* ConcreteBuilder2::getResult()
    {
       return result; 
    }

    Director::Director(Builder* builder)
    {
        this->builder = builder;
    }
    
    Director::~Director()
    {
        delete builder;
    }

    
    void Director::changeBuilder(Builder& builder)
    {
        this->builder = &builder;
    }

    void Director::make(BuilderType type)
    {
        builder->reset();

        if(simple == type)
        {
            builder->buildStepA();
        }else{
            builder->buildStepA();
            builder->buildStepB();
            builder->buildStepC();
        }
    }

    Main::Main()
    {
    }
    
    Main::~Main()
    {
    }

    void Main::execute()
    {
        ConcreteBuilder1* builder1 = new ConcreteBuilder1();
        Director dir(builder1);

        std::cout<<"simple";
        dir.make(BuilderType::simple);

        Product1* product1 = builder1->getResult();

        product1->listParts();

        delete product1;

        std::cout<<"complex";
        dir.make(BuilderType::complex);

        product1 = builder1->getResult();
        product1->listParts();

        delete product1;
    }

}
