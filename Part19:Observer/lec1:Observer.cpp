#include<bits/stdc++.h>
using namespace std;

template<typename T> class Observer{
public:
    virtual void field_change(T& source, string& field_name) = 0;
};

template<typename T> class Observable{
public:
    vector<Observer<T>*> observers;
    void notify_all(T& source, string fieldname){
        for(auto& observer:observers){
            observer->field_change(source,fieldname);
        }
    } 
    void subscribe(Observer<T>& observer){
        observers.push_back(&observer);
        cout<<"subscribed"<<endl;
    }
    void unsubscribe(Observer<T>& observer){
        observers.erase(remove(observers.begin(),observers.end(),&observer),observers.end());
        cout<<"unsubscribed"<<endl;
    }
};


class Person: public Observable<Person>{
    int age;
public:
    Person(int age):age(age){}
    int get_age() {return age;}
    void set_age(int age){
        if(this->age == age) return;
        this->age = age;
        notify_all(*this,"age");
    }
};

class PersonObserver:public Observer<Person>{
public:
    void field_change(Person& source, string& fieldname) override{
        if(fieldname=="age"){
            cout<<fieldname<<" changed to : "<<source.get_age()<<endl;;
        }
    }
};

int main(){
    Person p{10};
    PersonObserver po;
    p.subscribe(po);
    p.set_age(15);
    p.set_age(16);
    p.unsubscribe(po);
    p.set_age(20);
    return 0;
}