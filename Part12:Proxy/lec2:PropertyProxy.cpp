//A property is nothing but a field with its getters and setters  
//Property proxy is a template class
#include<iostream>
using namespace std;

template <typename T> class Property{
public:
    T value;
     
    Property(T value){
        this->value = value;
    }
    void operator=(T new_value){
        cout<<"Assignment"<<endl;
        value = new_value;
    }
    operator T(){
        return value; //Type conversion--> remember this
    }

};
class Creature{
public:
    Property<int> strength{10};
    Property<int> agility{15};
};

int main(int args, char* argv[]){
    Creature c;
    c.strength = 5;
    int x = c.agility;
    return 0;
}