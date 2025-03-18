#include<iostream>
#include<fstream>
#include<vector>
#include<string>

using namespace std;

// Forward Declaration
class PersistenceManagener;

class Journal {
    string title;
    vector<string> entries;
    int count;

public:
    Journal(string& title) : title(title), count(0) {}

    void add_entry(string& entry) {
        count++;
        entries.push_back(to_string(count)+"."+entry);
    }

    // Friend function declaration
    friend class PersistenceManagener;
};

class PersistenceManagener {
public:
    static void save(const Journal& j, const string& filename) {
        ofstream ofs(filename);
        for (auto entry : j.entries) {
            ofs << entry << endl;
        }
        ofs.close();
    }
};

int main() {
    string title = "My Journal";
    Journal j(title);
    
    string entry1 = "I started learning C++ today!";
    string entry2 = "I understood what is a friend function.";

    j.add_entry(entry1);
    j.add_entry(entry2);

    PersistenceManagener::save(j, "journal.txt");

    return 0;
}
