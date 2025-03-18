//Problem Statement -> 
// You are the head of a firm which handles various machines which can perform functions from print, scan and fax (May not perform all the functions). Write a code to design class structure for each of the machines.
//Note: All class starting with I denote interfaces

//Wrong approach
// struct Document;
// class IMachine{ //Base class for all the machines
// public:
//     virtual void print(Document &doc) = 0;
//     virtual void scan(Document &doc) = 0;
//     virtual void fax(Document &doc) = 0;
// };
// class Printer:public IMachine{
//     void print(Document &doc) override{
//         //ok
//     }
//     void scan(Document &doc) override{
//         //not needed since printer cannot perform the scanning function
//     }
//     void fax(Document &doc) overrid{
//         //not needed since printer cannot perform the faxxing function
//     }
// };

struct Document;

class IPrint{
public:
    virtual void print(Document& doc) = 0;
};

class IScan{
public:
    virtual void scan(Document& doc) = 0;
};

class IFax{
public:
    virtual void fax(Document& doc) = 0;
};

class Printer: public IPrint{
    void print(Document& doc) override{
        //ok
    }
};
class IMachine: public IPrint,public IScan{};

class Machine:public IMachine{
    //This machine can both print and scan
    IPrint& printer;
    IScan& scanner;
public:
    Machine(IPrint& printer,IScan& scanner): printer(printer),scanner(scanner){}
    void print(Document& doc){
        printer.print(doc);
    }
    void scan(Document& doc){
        scanner.scan(doc);
    }
};

//This approach is called interface segregation principle -> We don't stuff too many interfaces in a single class

int main(){
    return 0;
}

