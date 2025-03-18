//My code should be open to extension
//Specification Pattern in C++
//Problem Statement -> You have to make a class of products that has a name, color, size and rating
//-> Then you need to ask user to select the color,size and rating of the product they want and return all those prodcuts satisfying the conditions put up by the user
//-> It should be noted that there may be 100 features related to a product (we are only dealing with 3 here) so optimize your code so that you need to check only the features the user is interested in rather than iterating on all the features
//Your code should be extensible



#include<iostream>
#include<vector>
using namespace std;


enum class Color{red,green,blue};
enum class Size{small,medium,large};
enum class Rating{low,average,high};

class Product{
    public:
        string name;
        Color color;
        Size size;
        Rating rating;
        Product(string name, Color color, Size size, Rating rating) : name(name),color(color),size(size),rating(rating){}
};

class Specification{
    //Base class for all the Specification that I have
    public:
        virtual bool is_satisfied(Product* item) const = 0;
};

class ColorSpecification:public Specification{
    Color color;
    public:
        ColorSpecification(Color& color):color(color){}
        bool is_satisfied(Product* item) const override {
            return item->color==color;
        }
};

class SizeSpecification:public Specification{
    Size size;
    public:
        SizeSpecification(Size& size):size(size){}
        bool is_satisfied(Product* item) const override {
            return item->size==size;
        }
};

class RatingSpecification:public Specification{
    Rating rating;
    public:
        RatingSpecification(Rating &rating):rating(rating){}
        bool is_satisfied(Product* item) const override {
            return item->rating==rating;
        }
};

class AndSpecification:public Specification{
    const Specification& s1;
    const Specification& s2;
    public:
        AndSpecification(const Specification& s1,const Specification&s2) : s1(s1), s2(s2){}
        bool is_satisfied(Product* item) const override {
            return s1.is_satisfied(item) && s2.is_satisfied(item);
        }
};

AndSpecification operator && (const Specification& s1,const Specification& s2){
    return {s1,s2};
}

class FilterProduct{
    public:
        static vector<Product*> filter(vector<Product*> product,const  Specification& spec){
            cout<<"starting"<<endl;
            vector<Product*> result;
            for(auto ele:product){
                if(spec.is_satisfied(ele)){
                    result.push_back(ele);
                }
            }
            return result;
        }          
};

int main(){
    Product lambo("Lamborghini",Color::red,Size::large,Rating::high),wagen("Wagen",Color::blue,Size::small,Rating::average);
    Product nano("Tata Nano",Color::green,Size::small,Rating::low);
    Product bmw("BMW",Color::red,Size::large,Rating::high);
    vector<Product*> input;
    input.push_back(&lambo);
    input.push_back(&wagen);
    input.push_back(&nano);
    input.push_back(&bmw);

    auto red = Color::red;
    auto large = Size::large;
    auto high = Rating::high;
    ColorSpecification cspec(red);
    SizeSpecification sspec(large);
    RatingSpecification rspec(high);
    
    auto temp = (cspec && sspec);
    auto spec = temp && rspec;
    cout<<"here are the results"<<endl;
    auto result = FilterProduct::filter(input,spec);
    for(auto x:result){
        cout<<x->name<<" ";
    }cout<<endl;
    return 0;
}