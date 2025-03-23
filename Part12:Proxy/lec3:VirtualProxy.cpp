//Working with objects that has not been created
//Problem statment -> We don't want to load the image unless someone draw it

#include<iostream>
#include<string>
using namespace std;

//We have been given with the following interface
struct Image{
    virtual void draw() = 0;
};

struct Bitmap : Image{
    Bitmap(const string& filename){
        cout<<"Code to load the bitmap"<<endl;
    }
    void draw() override{
        cout<<"Drawing the object"<<endl;
    }
};

//Objective is to create a wrapper class that does not load the image unless and until someone draws it

struct LazyBitmap:Image{
    string filename;
    Bitmap* bmp{nullptr};
    LazyBitmap(const string& filename) : filename(filename){}
    void draw() override{
        if(!bmp){
            bmp = new Bitmap(filename);
        }
        cout<<"Drawing the object"<<endl;
    }

};

int main(){
    LazyBitmap lbmp("pokemon.png");
    cout<<"Calling draw"<<endl;
    lbmp.draw();
    return 0;
}