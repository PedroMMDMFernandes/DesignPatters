#include "flyweight.hpp"

namespace FlyweightDP
{
    Flyweight::Flyweight(const SharedState* sharedState)
    : sharedState(new SharedState(*sharedState))
    {
    }

    Flyweight::Flyweight(const Flyweight& flyweight)
    : sharedState(new SharedState(*flyweight.sharedState))
    {
    }

    Flyweight::~Flyweight()
    {
        delete sharedState;
    }

    void Flyweight::Operation(const UniqueState &unique_state)
    {
        std::cout << "Shared State: " << *sharedState << " Unique State: " << unique_state;
    }

    FlyweightFactory::FlyweightFactory(std::initializer_list<SharedState> SharedStateList)
    {
        std::cout<<"Constructor";
        for (const SharedState &state : SharedStateList)
        {
            flyweightsMap.insert(std::make_pair<std::string, Flyweight>(this->GetKey(state), Flyweight(&state)));
        }

        std::cout<<"End";
        
    }
    
    FlyweightFactory::~FlyweightFactory()
    {
    }

    Flyweight FlyweightFactory::GetFlyweight(const SharedState &sharedState)
    {
        std::string key = GetKey(sharedState);

        if(flyweightsMap.find(key)==flyweightsMap.end())
        {
            //Dind't found a key after reaching the maps'end

            flyweightsMap.insert(std::make_pair<std::string, Flyweight>(this->GetKey(sharedState), Flyweight(&sharedState)));

        }
        else{
            //Reuse existing object;
        }

        return flyweightsMap.at(key);
    }

    std::string FlyweightFactory::GetKey(const SharedState &sharedState)
    {
        return sharedState.brand_+"_"+sharedState.model_+"_"+sharedState.color_;
    }

    void FlyweightFactory::GetListOfFlyweights()
    {
        std::cout<<"List";
        std::unordered_map<std::string, Flyweight>::iterator it;

        for (it = flyweightsMap.begin(); it != flyweightsMap.end(); ++it)
        {
            std::cout<<it->first<<"\n";
        }
        
    }

    void Execute()
    {
        //GetList

        FlyweightFactory *flyFact = new FlyweightFactory ({{"Chevrolet", "Camaro2018", "pink"}, {"Mercedes Benz", "C300", "black"}, {"Mercedes Benz", "C500", "red"}, {"BMW", "M5", "red"}, {"BMW", "X6", "white"}});
        flyFact->GetListOfFlyweights();

        Flyweight flyweight = flyFact->GetFlyweight({"Opel","Astra","black"});

        flyweight.Operation({"Pedro Fernandes","20BB07"});
    }
}




