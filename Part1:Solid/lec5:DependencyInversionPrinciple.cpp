#include<iostream>
#include<string>
#include<vector>
#include<tuple>
using namespace std;

//Dependency inversion Principle
//high level module should not depend on low level module. Both should depend on abstractions
//Abstractions should not depend on detail rather detail should depend on abstraction

enum class Relation{
    parent,
    child,
    sibling
};

class Person{
public:
    string name;
};

class RelationshipBrowser{ //Abstraction
public:
    virtual vector<Person> get_all_child_of(const string name)  = 0; //purely virtual
};

class Relationship : RelationshipBrowser{ //low-level module
    vector<tuple<Person,Relation,Person>> relations;
public:
    void add_parent_and_child(Person parent, Person child){
        relations.push_back({parent,Relation::parent,child});
        relations.push_back({child,Relation::child,parent});
    }
    vector<Person> get_all_child_of(const string name) override{
        vector<Person> result;
        for(auto&& [first,rel,second]:relations){
            if(first.name==name && rel==Relation::parent) result.push_back(second);
        }
        return result;
    }
};

class Research{ //high level module -> should always depend on abstractions rather than low level module because low level module may change in future ->  This is called dependency inversion principle
public:
    Research(RelationshipBrowser& browser){
        //This is dependency injection-> Injecting dependency via a constructor
        for(auto& child:browser.get_all_child_of("John")){
            cout<<"John is the parent of  "<<child.name<<endl;
        }
    }
};


int main(){
    return 0;
}