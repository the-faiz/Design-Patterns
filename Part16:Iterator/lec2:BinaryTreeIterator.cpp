#include<iostream>
#include<set>
using namespace std;

template <typename T> struct BinaryTree;

template <typename T> struct Node{
    Node<T> *left{nullptr}, *right{nullptr}, *parent{nullptr};
    int value;
    BinaryTree<T> *tree;
    
    Node(int val) : value(val){}
    Node(int val,Node<T>*left,Node<T>*right) : value(val), left(left), right(right) {
        this->left->parent = this->right->parent = this;
        this->left->tree = this->right->tree = tree;
    }
    void set_tree(BinaryTree<T>* tree){
        this->tree = tree;
        if(left) left->set_tree(tree);
        if(right) right->set_tree(tree);
    }
    ~Node(){
        //since smart pointer not used
        if(left) delete left;
        if(right) delete right;
    }
};

template <typename T> struct BinaryTree{
    Node<T>* root{nullptr};
    BinaryTree(Node<T>* root) : root(root){
        root->set_tree(this);
    }
    ~BinaryTree(){
        if(root) delete root;
    }
    template <typename U> struct PreOrderIt{
        Node<T>* current;
        set<Node<T>*> visited;
        PreOrderIt(Node<T>* current) : current(current){}
        Node<T>& operator*(){
            return *current;
        }
        void operator++(){ 
            if(current->left){
                current = current->left;
            }else if(current->right){
                current = current->right;
            }else{
                while(current && (current->right==nullptr || visited.find(current->right)!=visited.end())){
                    current = current->parent;
                }
                // cout<<"Parent:"<<current->value<<" "<<current->parent->value<<endl;
                if(current!=nullptr)
                    current = current->right;
            }
            visited.insert(current);
        }
        bool operator!=(PreOrderIt<T>& other){
            return current!=other.current;
        }
    };

    typedef PreOrderIt<T> iterator;
    iterator begin(){
        return iterator{root};
    }
    iterator end(){
        return iterator{nullptr};
    }
};


int main(){
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    BinaryTree<int> mytree{
        new Node<int>{1,
            new Node<int>{2,new Node<int>{4},new Node<int>{5}},
                new Node<int>{3}
        }
    };
    for(auto& x:mytree){
        cout<<x.value<<endl;
    }
    return 0;
}