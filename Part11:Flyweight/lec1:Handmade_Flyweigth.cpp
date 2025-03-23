//Problem statement : John Simth and Jane Smith -> store effectively
#include<iostream>
#include<map>
#include<string>
using namespace std;

class User{
public:
    User(const string&first_name, const string& last_name): first_name(add(first_name)),last_name(add(last_name)){}
    string get_first_name() const{
        return name_dict[first_name];
    }
    string get_last_name() const{
        return name_dict[last_name];
    }

    friend ostream& operator<<(ostream& os,const User& u){
        os << u.get_first_name()<<" "<<u.get_last_name()<<endl;
        return os;
    }
protected:
    int first_name,last_name;
    static map<int,string> name_dict;
    static map<string,int> key_dict;
    static int seed;
    int add(const string& name){
        if(key_dict.find(name)==key_dict.end()){
            seed++;
            name_dict.insert({seed,name});
            key_dict.insert({name,seed});
        }
        return key_dict[name];
    }
};

map<int,string> User::name_dict{};
map<string,int> User::key_dict{};
int User::seed{0};


int main(int args, char* argv[]){
    User u1{"John","Smith"};
    User u2{"Jane","Smith"};
    cout<<u1<<endl<<u2<<endl;
    return 0;
}