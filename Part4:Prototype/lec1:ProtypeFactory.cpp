#include<iostream>
#include<memory>
using namespace std;

class Address{
public:
    string street;
    string city;
    int suite;
    Address(){}
    Address(const string& street, const string& city, const int& suite) : street(street), city(city), suite(suite){}
};

class Employee{
public:
    string name;
    Address* address; //All this trouble because address is a pointer
    Employee(const string&name, Address* address) : name(name) , address(address) {}
    Employee(const string&name, const string& street, const string& city, const int&suite):name(name), address(new Address(street,city,suite)) {};
    Employee(Employee& other){
        name = other.name;
        // address = otther.address;
        address = new Address(other.address->street,other.address->city,other.address->suite); //Deep copying
    }
    friend ostream& operator<<(ostream&os, const Employee& e){
        cout<<e.name<<" "<<e.address->street<<" "<<e.address->city<<" "<<e.address->suite<<endl;
        return os;
    }
};

class EmployeeFactory{
public:
    static unique_ptr<Employee> get_office_employee(const string&name , const int& suite){
        auto result = make_unique<Employee> ("","Ashok Raj Path", "Patna",0);
        result->name = name;
        result->address->suite = suite;
        return result; 
    }
};

int main(){
    auto john = EmployeeFactory::get_office_employee("John",123); //making an office employee from the prototype of the office employee

    cout<<*john<<endl;
    return 0;
}