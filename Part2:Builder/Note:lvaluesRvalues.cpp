#include<iostream>
using namespace std;

void fun1(string& name){
    //Only accepts l value becasue the reference is lvalue refrence
    name = "Mr. "+name;
    cout<<name<<" from fun1"<<endl;
}

void fun2(string&& name){
    //Only accepts r value because the reference is rvalue reference
    name = "Mr. "+name;
    cout<<name<<" from fun2"<<endl;
}

void fun3(const string& name){
    //Accepts both lvalue and rvalue
    // name = "Mr. "+name; --> error 
    cout<<name<<endl;
}


int main(){
    string firstName = "Atif";
    string lastName = "Faizan";
    string fullName = firstName+lastName;
    fun1(fullName);
    // fun1(firstName+lastName); --> error
    // fun2(fullName); --> error
    fun2(firstName+lastName);
    fun3(fullName);
    fun3(firstName+lastName);
    return 0;
}