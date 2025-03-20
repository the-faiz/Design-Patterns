// => Before smart pointers let us know about static and dynamic allocation
// => In C++ all the variables are static allotcated (during compile time -> size must be known) or dynamic allocated (during runtime -> size may not be known). E.g. vector<int> v(n) where n is an input from the user is dynamically allocated.
// => int *p = new int(10); --> everything using new keyword is also dynamically allocated 
// static allocation happens on stack while dynamic allocation happens on heap 
// All the variables that are static allocated are automatically deleted when they get out of the scope while the dynamically created variables must be deleted explicitly using delete function otherwise they remain undeleted and it may lead to memory leak (overflow)
//Destructors are only called for stack (static allocated) variables not for heap (dynamic allocated) variables when they go out of scope

// 0. Smart pointer is a class which sraps a raw pointer, to manage the life time of the pointer
// 1. The most fundamental job of smart pointer is to remove the chances of memory leak.
// 2. It makes sure that the object is deleted if it is not reference any more

// There are three types of smart pointers ->
// 1. unique_ptr
// 2. shared_ptr
// 3. weak_ptr


// => Unique Pointer in C++
// Notes:
// 0. unique_ptr is a class template
// 1. unique_ptr is one of the smart pointer porvided by C++11 to prevent meomory leaks
// 2. unique_ptr wraps a raw pointer in it, and de-allocates the raw pointer, when unique_pointer object goes out of the scope.
// 3. similar to actaul pointers we can use -> and * on the object of the unique pointer becasue it is overlaoded in unique_ptr class
// 4. When exception comes then also it will de-allocate the memory hence no memeory leak.
// 5. Not only object we can create array of objects of unique_ptr

//Operations
//realease, reset, swap, get, get_deleter

#include<iostream>
#include<memory>

class Foo{
    int x;
public:
    explicit Foo(int x):x(x){}
    int getX() {return x;}
};

int main(){
    unique_ptr<Foo> p1(new Foo(10));
    unique_ptr<Foo> p2 = make_unique<Foo> (20);
    Foo f; 
    Foo* x = &f;
    unique_ptr<Foo> p3(f);
    
    // p4=p1;  -> invalid because same normal _pointer cannot be owned by two different unique_ptr
    unique_ptr<Foo> p4 = move(p1); //p1 loses the ownership of the new Foo(10) and becomes nullptr while p4 gains the ownership of new Foo(10)

    Foo* normal_p1 = p2.get(); //just returns the pointer whose ownership is with p2
    Foo* noraml_p2 = p2.release(); //returns as well as loose the ownership of the pointer it was holding
    p1.reset(normal_p2); //The previously owned pointer by p1 is deleted and p1 gains the ownerewhip of new pointer normal_p2
    
    return 0;
}



//SHARED POINTER
// 1.shared_ptr is a smart pointer which can share the ownership of object (managed object)
// 2. Several shared_ptr can point ot the same object (managed object)
// 3. It keep a reference count to maintain how many shared_ptr are pointing to the same object and once last shared_ptr goes out of scope then the managed object get deleted.
// 4. The reference count forms the control block of the shared pointer.
// 5. Control block is thread safe( even if you are using multithreading in whihc you use different shared_ptr to point to the same object and reference count will be intact).
// 6. The main block is not thread safe and has to be handled explicitly by using mutexes.
// 7. There are three ways shared_ptr will destroy managed object
// a. If the last shared_ptr goes out of scope
// b. If you initialize shared_ptr with some other shared_ptr
// c. If you reset shared prevent
// 8. Reference count does not increment when you use reference to a shared pointer passed to another shared pointer.


//note: shared_ptr<class> sp1(obj1); shared_ptr<class> sp2;
// sp2 = sp1; --> Allowed -> Reference count 
//sp.use_count() --> to get the reference count
