#include<iostream>
#include<vector>
#include<initializer_list>
#include<string>
using namespace std;

class Tag{
protected:
    string name;
    string text;
    vector<Tag> child;
    Tag(const string &name,const string &text) : name(name), text(text){}
    Tag(const string &name,const vector<Tag> &child) : name(name),child(child){}
    static const int indent_l = 2;
public:
    friend ostream& operator<<(ostream& os, const Tag& t){
        os << "<" << t.name << ">\n";
        if(t.text.size()>0)
            os << "  "<<t.text<<"\n";
        for(auto& ele:t.child){
            os << ele;
        }
        os << "<" << t.name <<"/>\n";
        return os;
    }

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
};

class P:public Tag{
public:
    P(const string& name, const string& text) : Tag(name,text){}
    P(initializer_list<Tag> child) : Tag("p",child){} //this is the main crux of this code...building using intializer_list
};

class H:public Tag{
public:
    H(const string& name, const string& text) : Tag(name,text){}
    H(const string& text) : Tag("h",text){}
    H(initializer_list<Tag> child) : Tag("h",child){}
};


int main(){
    cout<<
        P{
            H{
                P{
                    H{"hello world"}
                }
            }
        }
    <<endl;


    // string temp = P{
    //     H{"Hey world"},
    //     H{"Machake"}
    // }.str();
    // cout<<temp<<endl;

    // string temp = P{
    //         H{
    //             P{
    //                 H{"hello world"}
    //             }
    //         }
    //     }.str();
    // cout<<temp<<endl;

    return 0;
}