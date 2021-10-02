#include <iostream>
#include <unordered_map>

namespace FlyweightDP
{

    struct SharedState
    {
        std::string brand_;
        std::string model_;
        std::string color_;

        SharedState(const std::string &brand, const std::string &model, const std::string &color)
            : brand_(brand), model_(model), color_(color)
        {
        }

        friend std::ostream &operator<<(std::ostream &os, const SharedState &ss)
        {
            return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
        }
    };

    struct UniqueState
    {
        std::string owner_;
        std::string plates_;

        UniqueState(const std::string &owner, const std::string &plates)
            : owner_(owner), plates_(plates)
        {
        }

        friend std::ostream &operator<<(std::ostream &os, const UniqueState &us)
        {
            return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
        }
    };

    class Flyweight
    {
    public:
        Flyweight(const SharedState* sharedState);
        Flyweight(const Flyweight& flyweight);
        ~Flyweight();

        void Operation(const UniqueState &unique_state);
    
    private:
        SharedState* sharedState;
    };

    class FlyweightFactory
    {
    public:
        FlyweightFactory(std::initializer_list<SharedState> SharedStateList);
        FlyweightFactory(FlyweightFactory &&) = default;
        FlyweightFactory(const FlyweightFactory &) = default;
        FlyweightFactory &operator=(FlyweightFactory &&) = default;
        FlyweightFactory &operator=(const FlyweightFactory &) = default;
        ~FlyweightFactory();

        Flyweight GetFlyweight(const SharedState &sharedState);

        void GetListOfFlyweights();
    
    private:
        std::unordered_map<std::string, Flyweight> flyweightsMap;

        std::string GetKey(const SharedState &sharedState);


    };
    
    void Execute();
}


