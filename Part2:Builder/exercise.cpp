#include<iostream>
#include<string>
#include<vector>
using namespace std;

class CodeBuilder;

class Code{
private:
    friend class CodeBuilder;
    string name; //Name of the class
    vector<pair<string,string>> field; //type ,name
public:
    Code(){};
    Code(const string& name) : name(name){}
};

class CodeBuilder{
    Code c;
public:
    CodeBuilder(const string& name){
        c.name = name;
    }
    CodeBuilder& add_field(const string& type, const string& name){
        c.field.push_back({type,name});
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& cb){
        os<<"class "<<cb.c.name<<"\n";
        os<<"{\n";
        for(auto x:cb.c.field){
            os<<" "<<x.first<<" "<<x.second<<"\n";
        }
        os<<"};\n";
        return os;
    }

};

int main(){
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    cout << cb;
    return 0;
}