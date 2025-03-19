//We use static functions to create an object rather than using constructor to handle different initialization with same set of type of arguments -> The static functions are called factory methods

#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;


class Point{
private:
    float x,y;
    Point(const float& x, const float& y): x(x) , y(y){}
public:
    static Point NewCartesian(float x ,float y){
        return {x,y};
    }
    static Point NewPolar(float r, float theta){
        return {r*cos(theta),r*sin(theta)};
    }
    friend ostream& operator<<(ostream& os,const Point& obj){
        os<<"x : "<<obj.x<<" y: "<<obj.y<<endl;
        return os;
    }
};


int main(){
    auto p = Point::NewPolar(5,M_PI_4);
    cout<<p<<endl;
    return 0;
}