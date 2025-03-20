#include<iostream>
#include<map>
#include<fstream>
using namespace std;

class Database{
private:
    map<string,int> mp;
    Database(){
        ifstream file("database.txt");
        if (file.is_open()) {
            string subject;
            while (getline(file, subject)) {
                string x;
                getline(file,x);
                // cout<<x<<endl;
                int marks = stoi(x);
                mp[subject] = marks;
            }
            file.close();
        } else {
            cerr << "Unable to open file" << endl;
        }
    }
public:
    int get_marks(const string& subject){
        return mp[subject];
    }

    static Database& get(){
        static Database db;
        return db;
    }
    Database(Database const& ) = delete;
    void operator =(Database const&) = delete;
};

int main(){
    int m = Database::get().get_marks("Physics");
    cout<<m<<endl;
    return 0;
}

