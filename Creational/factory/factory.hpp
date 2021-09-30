
namespace FactoryDP {

    class Product
    {
    public:
        Product();
        Product(Product &&) = default;
        Product(const Product &) = default;
        Product &operator=(Product &&) = default;
        Product &operator=(const Product &) = default;

        ~Product();

        virtual void doStuff();
    
    };

    class ConcreteProductA : public Product
    {
    public:
        ConcreteProductA();
        ConcreteProductA(ConcreteProductA &&) = default;
        ConcreteProductA(const ConcreteProductA &) = default;
        ConcreteProductA &operator=(ConcreteProductA &&) = default;
        ConcreteProductA &operator=(const ConcreteProductA &) = default;
        ~ConcreteProductA();

        void doStuff() override;

    private:
        
    };

    class ConcreteProductB : public Product
    {
    public:
        ConcreteProductB();
        ConcreteProductB(ConcreteProductB &&) = default;
        ConcreteProductB(const ConcreteProductB &) = default;
        ConcreteProductB &operator=(ConcreteProductB &&) = default;
        ConcreteProductB &operator=(const ConcreteProductB &) = default;
        ~ConcreteProductB();

        void doStuff() override;

    private:
        
    };


    class Creator
    {
    public:
        Creator();
        Creator(Creator &&) = default;
        Creator(const Creator &) = default;
        Creator &operator=(Creator &&) = default;
        Creator &operator=(const Creator &) = default;
        ~Creator();

        void someOperation();

        virtual Product* createProduct() const = 0;
    
    private:
        
    };

    class ConcreteCreatorA : public Creator
    {
    public:
        ConcreteCreatorA();
        ConcreteCreatorA(ConcreteCreatorA &&) = default;
        ConcreteCreatorA(const ConcreteCreatorA &) = default;
        ConcreteCreatorA &operator=(ConcreteCreatorA &&) = default;
        ConcreteCreatorA &operator=(const ConcreteCreatorA &) = default;
        ~ConcreteCreatorA();
        Product* createProduct() const override;
    
    private:
        
    };

    class ConcreteCreatorB : public Creator
    {
    public:
        ConcreteCreatorB();
        ConcreteCreatorB(ConcreteCreatorB &&) = default;
        ConcreteCreatorB(const ConcreteCreatorB &) = default;
        ConcreteCreatorB &operator=(ConcreteCreatorB &&) = default;
        ConcreteCreatorB &operator=(const ConcreteCreatorB &) = default;
        ~ConcreteCreatorB();
        Product* createProduct() const override;
    
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

        void execute();
    
    private:
        
    };
}




