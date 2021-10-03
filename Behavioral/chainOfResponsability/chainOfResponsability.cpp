#include "chainOfResponsability.hpp"

namespace ChainOfResponsabilityDP
{
    Handler::Handler(/* args */)
    {
    }
    
    Handler::~Handler()
    {
    }

    BaseHandler::BaseHandler()
    :handler(nullptr)
    {
    }
    
    BaseHandler::~BaseHandler()
    {
    }

    void BaseHandler::setNextHandler(Handler* chainOfresp)
    {
        handler = chainOfresp;
    }

    std::string BaseHandler::callHandle(std::string request) const
    {
        //return Handler::callHandle(request);

        return handler->callHandle(request);
    }

    DogHandler::DogHandler()
    {
    }
    
    DogHandler::~DogHandler()
    {
    }

    std::string DogHandler::callHandle(std::string request) const
    {
        if("bone" == request)
        {
            return "Dog: I'll eat the " + request + "\n";
        }
        else if(handler != nullptr){
            return handler->callHandle(request);
        }
        else{
            return "Nobody Eats it \n"; 
        }        
    }

    MonkeyHandler::MonkeyHandler()
    {
    }
    
    MonkeyHandler::~MonkeyHandler()
    {
    }

    std::string MonkeyHandler::callHandle(std::string request) const
    {
        if("banana" == request)
        {
            return "Monkey: I'll eat the " + request + "\n";
        }
        else{
            return handler->callHandle(request);
        } 
    }

    SquirrelHandler::SquirrelHandler()
    {
    }
    
    SquirrelHandler::~SquirrelHandler()
    {
    }

    std::string SquirrelHandler::callHandle(std::string request) const
    {
        //return Handler::callHandle(request);

        if("nut" == request)
        {
            return "Squirrel: I'll eat the " + request + "\n";
        }
        else {
            return handler->callHandle(request);
        }        
    }

    void Execute(void)
    {
        Handler *Dog = new DogHandler;
        Handler *Monkey = new MonkeyHandler;
        Handler *Squirrel = new SquirrelHandler;

        Monkey->setNextHandler(Dog);
        Squirrel->setNextHandler(Monkey);

        std::cout<<Squirrel->callHandle("bone");
        std::cout<<Squirrel->callHandle("banana");
        std::cout<<Squirrel->callHandle("nut");
        std::cout<<Squirrel->callHandle("Water");
    }
    
}

