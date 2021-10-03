#include <iostream>

namespace ChainOfResponsabilityDP
{
    class Handler
    {
    private:
        /* data */



    public:
        Handler(/* args */);
        ~Handler();

        virtual void setNextHandler(Handler* chainOfresp) = 0;
        virtual std::string callHandle(std::string request) const = 0;

    };

    class BaseHandler: public Handler
    {
    public:
        BaseHandler();
        BaseHandler(BaseHandler &&) = default;
        BaseHandler(const BaseHandler &) = default;
        BaseHandler &operator=(BaseHandler &&) = default;
        BaseHandler &operator=(const BaseHandler &) = default;
        ~BaseHandler();

        void setNextHandler(Handler* chainOfresp) override;
        std::string callHandle(std::string request) const override;
    
    private:

    protected:
    Handler* handler;
        
    };

    class DogHandler: public BaseHandler
    {
    public:
        DogHandler();
        DogHandler(DogHandler &&) = default;
        DogHandler(const DogHandler &) = default;
        DogHandler &operator=(DogHandler &&) = default;
        DogHandler &operator=(const DogHandler &) = default;
        ~DogHandler();

        std::string callHandle(std::string request) const override;
    
    private:
        
    };

    class MonkeyHandler: public BaseHandler
    {
    public:
        MonkeyHandler();
        MonkeyHandler(MonkeyHandler &&) = default;
        MonkeyHandler(const MonkeyHandler &) = default;
        MonkeyHandler &operator=(MonkeyHandler &&) = default;
        MonkeyHandler &operator=(const MonkeyHandler &) = default;
        ~MonkeyHandler();

        std::string callHandle(std::string request) const override;
    
    private:
        
    };

    class SquirrelHandler: public BaseHandler
    {
    public:
        SquirrelHandler();
        SquirrelHandler(SquirrelHandler &&) = default;
        SquirrelHandler(const SquirrelHandler &) = default;
        SquirrelHandler &operator=(SquirrelHandler &&) = default;
        SquirrelHandler &operator=(const SquirrelHandler &) = default;
        ~SquirrelHandler();

        std::string callHandle(std::string request) const override;
    
    private:
        
    };

    void Execute(void);
    
}
