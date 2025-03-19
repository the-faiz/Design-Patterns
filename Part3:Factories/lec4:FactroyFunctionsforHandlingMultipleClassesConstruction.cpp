//We are having various classes derived from an abstract base class for which we need to construct the factory classes. We follow the similar hierarchy in factory classes too with one abstract factory class and then we use an interface to call different factories based on the user input. This is called Abstract Factory Pattern
#include<iostream>
#include<memory> //To use smart pointers
#include<map>
#include<functional>
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

//Factory Classes--> No need of abstract factory classes

//One interface to handle all the factories
class DrinkFactory{
    map<string,function<unique_ptr<HotDrink>()>> factories;
public:
    DrinkFactory(){
        factories["tea"] = []{
            auto tea = make_unique<Tea>();
            tea->preapre(100);
            return tea;
        };
        factories["coffee"] = []{
            auto coffee = make_unique<Coffee>();
            coffee->preapre(50);
            return coffee;
        };
    }
    void make_drink(string type){
        factories[type]();
    }
};



int main(){
    DrinkFactory df;
    df.make_drink("tea");
    df.make_drink("coffee");
    return 0;
}