//Liskov Subsutitution Priciple -> If a derived class can be passed to a function accepting a pointer to the base class without any problem

//This program violates the Liskov Subsutitution Principle because on subsituting square in place of rectangle in the function process we are not getting expected answer

#include<iostream>
using namespace std;

class Rectangle{
protected:
    int width,height;
public:
    Rectangle(int width,int height) : width(width),height(height){}
    virtual void setHeight(int height){
        this->height = height;
    }
    int getHeight() const{
        return height;
    }
    virtual void setWidth(int width){
        this->width = width;
    }
    int getWidth() const{
        return width;
    }
    int area(){return width*height;}
};

class Square: public Rectangle{
public:
    Square(int size):Rectangle(size,size){}
    void setWidth(int width) override{
        this->width =this->height = width;
    }
    void setHeight(int height) override{
        this->height =this->width = height;
    }
};

void process(Rectangle &r){
    int w = r.getHeight();
    r.setWidth(10);
    cout<<"Expected Area ="<<w*r.getWidth()<<", got ="<<r.area()<<endl;
}

int main(){
    Rectangle r{3,4};
    process(r);
    Square sq{4};
    process(sq);
    return 0;
}