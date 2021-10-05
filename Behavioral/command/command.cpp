#include "command.hpp"

namespace CommandDP
{
    Command::Command()
    {
    }
    
    Command::~Command()
    {
    }

    Invoker::Invoker(Command& command)
    {
        this->command = &command;
    }
    
    Invoker::~Invoker()
    {
 
    }

    void Invoker::SetCommand(Command& command)
    {
        this->command = &command;
    }
    
    std::string Invoker::ExecuteCommand()
    {
        return "Invoker Command Execution: " + command->Execute();
    }

    Receiver::Receiver()
    {
    }
    
    Receiver::~Receiver()
    {
    }

    std::string Receiver::Operation(const std::string data)
    {
        return "Receiver: "+ data;
    }

    Command1::Command1(Receiver& receiver, const std::string data)
    : receiver(&receiver), data(data)
    {
    }
    
    Command1::~Command1()
    {
        
    }

    std::string Command1::Execute() const
    {
        return "Command1: " + receiver->Operation(data);
    }
    
    Command2::Command2(Receiver& receiver, const std::string data)
    : receiver(&receiver), data(data)
    {
    }
    
    Command2::~Command2()
    {
    }

    std::string Command2::Execute() const
    {
        return "Command2: " + receiver->Operation(data);
    }

    void Execute()
    {
        Receiver receiver;
        Command1 command1(receiver, "Command1");
        Command2 command2(receiver, "Command2");
        Invoker invoker1(command1);
        Invoker invoker2(command2);
        std::cout<<"Request1 "<<invoker1.ExecuteCommand()<<"\n";
        std::cout<<"Request2 "<<invoker2.ExecuteCommand()<<"\n";
    }
}