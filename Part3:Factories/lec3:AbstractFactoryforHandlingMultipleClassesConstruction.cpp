//We are having various classes derived from an abstract base class for which we need to construct the factory classes. We follow the similar hierarchy in factory classes too with one abstract factory class and then we use an interface to call different factories based on the user input. This is called Abstract Factory Pattern
#include<iostream>
#include<memory> //To use smart pointers
#include<map>
using namespace std;


//Normal Classes
class HotDrink{
public:
    HotDrink(){}
    virtual void preapre(int volume) = 0; //purely virtual function
};

class Coffee: public HotDrink{
public:
    void preapre(int volume) override{
        cout<<"making coffeee with volume: "<<volume<<endl;
    }
};

class Tea : public HotDrink{
    public:
    void preapre(int volume) override{
        cout<<"making tea with volume: "<<volume<<endl;
    }
};

//Factory Classes
class HotDrinkFactory{
public:
    HotDrinkFactory(){}
    virtual unique_ptr<HotDrink> make() = 0;
};

class TeaFactory : public HotDrinkFactory{
public:
    TeaFactory(){}
    unique_ptr<HotDrink> make() override{
        return make_unique<Tea> ();
    }
};

class CoffeeFactory : public HotDrinkFactory{
public:
    CoffeeFactory(){}
    unique_ptr<HotDrink> make() override{
        return make_unique<Coffee>();
    }
};

//One interface to handle all the factories
class DrinkFactory{
    map<string,unique_ptr<HotDrinkFactory>> factories;
public:
    DrinkFactory(){
        factories["tea"] = make_unique<TeaFactory>();
        factories["coffee"] = make_unique<CoffeeFactory>(); 
    }
    void make_drink(string type){
        auto drink = factories[type]->make();
        drink->preapre(200);
    }
};



int main(){
    DrinkFactory df;
    df.make_drink("tea");
    df.make_drink("coffee");
    return 0;
}