//Dynamic and Static Decorators
#include<iostream>
#include<sstream>
#include<concepts>
using namespace std;


class Shape{
public:
    virtual string str() = 0;
};

class Square: public Shape{
    int size;
public:
    Square(int size) : size(size){}
    string str() override{
        ostringstream oss;
        oss<<"The size of the srquare is "<< size << endl;
        return oss.str();
    }
    void resize(int size){
        this->size = size;
    }
};

class Circle: public Shape{
    int radius;
public:
    Circle(int size) :radius(radius){}
    string str() override{
        ostringstream oss;
        oss<<"The size of the circle is "<< radius << endl;
        return oss.str();
    }
};

template <typename T>
concept IsShape = std::is_base_of<Shape,T>::value;

//Decorators start from here
template<IsShape T> class ColoredShape:public T{
    string color;
public:
    template<typename... Args>
    ColoredShape(const string& color,Args... args) : T(forward<Args>(args)...),color(color){}
    string str() override{
        ostringstream oss;
        oss<<T::str()<<" has the color "<<color<<endl;
        //We can write T::str() since we are inheriting from T so an object of T is automatically created
    
        return oss.str();
    }
};

int main(){
    Square sq{5};
    ColoredShape<Square> red_sq{"red",5};
    red_sq.resize(10); //valid
    cout<<red_sq.str()<<endl;
    return 0;
}
