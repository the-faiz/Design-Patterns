//This pattern is called inner factory class patterns

#define _USE_MATH_DEFINES
#include<iostream>
#include<cmath>
using namespace std;


class Point{
private:
    float x,y;
    Point(const float& x, const float& y): x(x) , y(y){}
public:
    friend ostream& operator<<(ostream& os,const Point& obj){
        os<<"x : "<<obj.x<<" y: "<<obj.y<<endl;
        return os;
    }
    class PointFactory{
    public:
        static Point NewCartesian(float x ,float y){
            return {x,y};
        }
        static Point NewPolar(float r, float theta){
            return {r*cos(theta),r*sin(theta)};
        }
    
    };
};



int main(){
    auto p = Point::PointFactory::NewPolar(5,M_PI_4);
    cout<<p<<endl;
    return 0;
}