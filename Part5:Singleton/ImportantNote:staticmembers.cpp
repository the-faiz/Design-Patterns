// Static members which are not const must be intialized outside the class.
// consider a class of the type

template<typename T, typename Key> class Myclass{
    static map<Key, shareed_ptr<T>> instances;
};

//initialization
template<typename T,typename Key> 
map<Key,shared_ptr<T>> Myclass<T,Key>::instances;
