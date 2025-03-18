//Creational Pattern
// Some objects are simple and can be created in a single constructor call. Other objects required a lot of ceremony to create. Having an object with 10 constrcutor arguments is not productive. Instead opt for picewise construction. Builder provides and API for constructing an object step by step


//Problem statement -> dsign an efficient class based approach for html text formatting
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class HTMLBuilder;

class HTMLElement{
private:
    friend class HTMLBuilder;
    string name;
    string text;
    vector<HTMLElement> child;
    static const size_t indent_l = 2;
    HTMLElement(){}
    HTMLElement(string name,string text) : name(name),text(text){}
public:
    string str(int indent = 0){
        string result = "";
        string i(indent*indent_l,' ');
        result+=i+"<"+name+">\n";
        if(text.size()>0)
            result+=i+"  "+text+"\n";
        for(auto& ele:child){
            result+=ele.str(indent+1);
        }
        result+=i+"<"+name+"/>\n";
        return result;
    }
    static HTMLBuilder build (string root_name,string root_text);
};

class HTMLBuilder{
    HTMLElement root;
public:
    HTMLBuilder(string name,string text){
        root.name = name;
        root.text = text;
    }
    HTMLBuilder(HTMLElement &root) : root(root){};
    HTMLBuilder& add_child(string name,string text){
        HTMLElement e(name,text);
        root.child.push_back(e);
        return *this;
    }
    void str(){
        cout<<root.str()<<endl;
    }

    //Use either of the following
    HTMLElement build(){return root;}
    operator HTMLElement() const {
        return root; //Typecasting Operator OVerloading
    }
};

HTMLBuilder HTMLElement::build(string root_name, string root_text) {
    return HTMLBuilder(root_name, root_text);
}

int main(){
    HTMLBuilder builder("ul","");
    builder.add_child("li","Hello").add_child("li","Hello"); //Fluent Builder  
    // builder.add_child("li","World");
    HTMLElement ele = HTMLElement::build("ul","").add_child("li","hello").add_child("p","this is a paragraph");
    cout<<ele.str()<<endl;
    // builder.str();
    return 0;
}