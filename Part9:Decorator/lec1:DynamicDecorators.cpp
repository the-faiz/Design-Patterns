//Dynamic and Static Decorators
#include<iostream>
#include<sstream>
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

//Decorating objects of classes Square and Circle
class ColoredShape: public Shape{ //Decorator class 1 
    Shape& shape;//--> Dynamic Decorator
    string color;
public:
    ColoredShape(Shape& shape,string color):shape(shape),color(color){}
    string str() override{
        ostringstream oss;
        oss<<shape.str()<<" has the color"<<color<<endl;
        return oss.str();
    }
};

class TransparentShape: public Shape{ //Decorator class 2
    Shape& shape; //--> Dynamic Decorator
    int transparency;
public:
    TransparentShape(Shape& shape, int transparency): shape(shape), transparency(transparency){}
    string str() override{
        ostringstream oss;
        oss<<shape.str()<<" has transparency "<<transparency<<endl;
        return oss.str();
    }
};  

int main(){
    Square sq{5};
    ColoredShape red_sq{sq,"red"};
    TransparentShape trans_red_sq{red_sq,52};
    //red_sq.resize(10); //invalid
    // trans_red_sq.resize(10); --> error -> disadvantage
    cout<<trans_red_sq.str()<<endl;
    return 0;
}
