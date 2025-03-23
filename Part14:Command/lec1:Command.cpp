#include<iostream>
#include<vector>
using namespace std;

enum class Action{deposit,withdraw};

class Bankaccount{
private:
    int balance;
public:
    Bankaccount(const int& balance): balance(balance){}
    bool deposit(int amount){
        balance+=amount;
        cout<<"Successfully Deposited : "<<amount<<endl;
        return true;
    }
    bool withdraw(int amount){
        if(balance<amount) return false;
        balance-=amount;
        cout<<"Successfully withdrawn : "<<amount<<endl;
        return true;
    }
    friend ostream& operator<<(ostream& os,const Bankaccount& ba){
        os << "Currrent balance: "<<ba.balance<<endl;
        return os;
    }
};

class Command {
protected:
    bool succeeded;
    virtual void call() = 0;
    virtual void undo() = 0;
};

class BankaccountCommand:Command{
    Bankaccount& ba; //remember -> put here an &
    Action action;
    int amount;
public:
    BankaccountCommand(Bankaccount& ba, Action action, int amount) : ba(ba) , action(action), amount(amount){succeeded = false;}
    void call() override{
        if(action==Action::deposit){
            succeeded = ba.deposit(amount);
            cout<<"succeeded:"<<succeeded<<endl;
        }else{
            succeeded = ba.withdraw(amount);
            cout<<"succeeded:"<<succeeded<<endl;
        }
    }
    void undo() override{
        cout<<"succeeded:"<<succeeded<<endl;
        if(!succeeded) return;
        if(action==Action::deposit){
            ba.withdraw(amount);
        }else{
            ba.deposit(amount);
        }
    }
};



int main(){
    Bankaccount ba(100);
    vector<BankaccountCommand> commands{
        BankaccountCommand{ba,Action::deposit,100},
        BankaccountCommand{ba,Action::withdraw,200}
    };
    cout<<ba;
    for(auto& command:commands){
        command.call();
    }
    cout<<ba;
    for(int i=commands.size()-1;i>=0;i--){
        commands[i].undo();
    }
    cout<<ba;
    return 0;
}