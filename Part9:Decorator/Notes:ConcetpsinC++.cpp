//Concepts are way to restric the template class
template<typename T>
class Myclass{
    T a;
}
// Here T can take any values;

template<typename T>
concept IsShape = std::is_base_of<Shape,T>::value; //(any boolean expression in the rhs)

template<IsShape T>
class Myclass{
    T a;
}

// Now T can be derived classes of a base class Shape only