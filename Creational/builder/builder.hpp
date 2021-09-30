#include <iostream>
#include <vector>


namespace BuilderDP
{
    class Builder
    {
    public:
        Builder();
        Builder(Builder &&) = default;
        Builder(const Builder &) = default;
        Builder &operator=(Builder &&) = default;
        Builder &operator=(const Builder &) = default;
        ~Builder();

        virtual void reset() = 0;
        virtual void buildStepA() const = 0;
        virtual void buildStepB() const = 0;
        virtual void buildStepC() const = 0;
    private:
        
    };

    
    class Product1
    {
    public:
        Product1();
        Product1(Product1 &&) = default;
        Product1(const Product1 &) = default;
        Product1 &operator=(Product1 &&) = default;
        Product1 &operator=(const Product1 &) = default;
        ~Product1();

        void setParts(std::string part);
        void listParts();
    
    private:
        std::vector<std::string> product_parts;
    };

    class Product2
    {
    public:
        Product2();
        Product2(Product2 &&) = default;
        Product2(const Product2 &) = default;
        Product2 &operator=(Product2 &&) = default;
        Product2 &operator=(const Product2 &) = default;
        ~Product2();

        void listParts();
        void setParts();
    
    private:
        std::vector<std::string> product_parts;
    };
    

    
    class ConcreteBuilder1: public Builder
    {
    public:
        ConcreteBuilder1();
        ConcreteBuilder1(ConcreteBuilder1 &&) = default;
        ConcreteBuilder1(const ConcreteBuilder1 &) = default;
        ConcreteBuilder1 &operator=(ConcreteBuilder1 &&) = default;
        ConcreteBuilder1 &operator=(const ConcreteBuilder1 &) = default;
        ~ConcreteBuilder1();

        void reset() override;
        void buildStepA() const override;
        void buildStepB() const override;
        void buildStepC() const override;

        Product1* getResult();
    
    private:
        Product1* result;
    };
    

    class ConcreteBuilder2: public Builder
    {
    public:
        ConcreteBuilder2();
        ConcreteBuilder2(ConcreteBuilder2 &&) = default;
        ConcreteBuilder2(const ConcreteBuilder2 &) = default;
        ConcreteBuilder2 &operator=(ConcreteBuilder2 &&) = default;
        ConcreteBuilder2 &operator=(const ConcreteBuilder2 &) = default;
        ~ConcreteBuilder2();

        void reset() override;
        void buildStepA() const override;
        void buildStepB() const override;
        void buildStepC() const override;

        Product2* getResult();
    
    private:
       Product2* result; 
    };

    typedef enum
    {
        simple = 0,
        complex
    }BuilderType;

    class Director
    {
    public:
        Director(Builder* builder);
        Director(Director &&) = default;
        Director(const Director &) = default;
        Director &operator=(Director &&) = default;
        Director &operator=(const Director &) = default;
        ~Director();

        void changeBuilder(Builder& builder);

        void make(BuilderType type);
    
    private:
       Builder* builder;
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

        void execute();

    
    private:
        
    };
    


}

