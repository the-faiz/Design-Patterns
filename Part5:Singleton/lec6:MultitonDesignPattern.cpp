//I want only one instance of a class but each for different purpose -> Multiton
#include<iostream>
#include<memory>
#include<map>
using namespace std;


enum class Importance{
    primary,
    secondary,
    tertiary
};

template<typename T, typename Key>
class Multiton{
private:
    static map<Key,shared_ptr<T>> instances; //using map to ensure only one instance of a T with specification Key
public:     
    static shared_ptr<T> get(const Key& k){
        if(instances.find(k)==instances.end())
            instances[k] = make_shared<T>();
        return instances[k];
    }
};

template<typename T,typename Key>
map<Key,shared_ptr<T>> Multiton<T,Key>::instances;

class Printer{
public:
    static int instanceCount;
    Printer(){
        instanceCount++;
        cout<<"Istances count of the printer "<<instanceCount<<endl;
    }
};

int Printer::instanceCount = 0;

int main(){
    typedef Multiton<Printer,Importance> mt;
    auto main_printer = mt::get(Importance::primary);
    auto aux_printer1 = mt::get(Importance::secondary);
    auto aux_printer2 = mt::get(Importance::secondary);
    return 0;
}