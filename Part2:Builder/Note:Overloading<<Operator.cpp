#include<iostream>
#include<string>
using namespace std;


class Myclass{
    int a,b,c;
public:
    Myclass(const int& a, const int& b, const int& c) : a(a),b(b),c(c){}
    friend ostream& operator<<(ostream& os, const Myclass& obj) {
        os << obj.a << obj.b << obj.c; 
        return os;
    }
};

int main(){
    cout<<Myclass{1,2,3}<<endl;;
    cout<<"Created class"<<endl;
    return 0;
}