template<typename T> class Myclass:T{
    string color;
public:
    template<typename... Args> //Variadic template declaration
    Myclass(const string& color,Args ...args) : T(forward<Args>args...),color(color){}
    //Args ...args mean any number of arguments after color
    //forward is a construct used for perfect forwarding without creating copies
    
};