#include <initializer_list>
#include <iostream>
#include <cassert>
// Class declarations
class Set;
class Node;
// Function declarations
// Prints elements of the set (this code is given below)
std::ostream &operator<<( std::ostream &out, Set const &rhs );
// Class definitions
class Set {
    public:
    // This is new and will be clearly explained
    Set( std::initializer_list<int> initial_values ):
        p_head_{ nullptr } {
            for ( int const &value : initial_values ) {
                insert( value );
            }
        }
    
    ~Set();
    // The instructions will describe exactly what to do
    Set( Set const &orig );
    Set( Set &&orig );

    // The instructions will describe exactly what to do
    Set &operator=( Set const &rhs );
    Set &operator=( Set &&rhs );

    // Size operations
    bool empty() const;
    std::size_t size() const;

    // Clear all items out of the set
    void clear();
    
    // Find the value item in the set
    // - Return the address of the node if found,
    // and nullptr otherwise.
    Node *find( int const &item ) const;
    
    // Insert the item into the set if it
    // is not already in the set.
    // - Return 1 if the item is new,
    // and 0 otherwise.
    std::size_t insert( int const &item );

    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    // - Return the number of items inserted
    // into the set.
    std::size_t insert( int const array[],
    std::size_t const begin,
    std::size_t const end );

    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase( int const &item );

    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'.
    // Leave any items that already appear
    // in both sets, in both sets.
    std::size_t merge( Set &other );

    // Set operations (Automatic Assigment)
    Set &operator|=( Set const &rhs ); // union
    Set &operator&=( Set const &rhs ); // intersection
    Set &operator^=( Set const &rhs ); // symmetric difference
    Set &operator-=( Set const &rhs ); // minus

    // Set operations (Binary)
    Set operator|( Set const &other ) const; // union
    Set operator&( Set const &other ) const; // intersection
    Set operator^( Set const &other ) const; // symmetric difference
    Set operator-( Set const &other ) const; // minus

    // Returns 'true' if 'this' set is a
    // superset of 'other' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator>=( Set const &other ) const;

    // A superset but not equal to.
    bool operator>( Set const &other ) const;

    // Is 'this' a subset of the other set?
    bool operator<=( Set const &other ) const;

    // A subset but not equal to.
    bool operator<( Set const &other ) const;
    bool operator==( Set const &other ) const;
    bool operator!=( Set const &other ) const;
    private:
        Node *p_head_;
    friend std::ostream &operator<<( std::ostream &out, Set const &rhs );
};

class Node {
    public:
        Node( int new_value, Node *new_next );
        int value() const;
        Node *next() const;
    private:
        int value_;
        Node *next_;
        // Allow any member function in the class
        // 'Set' to access or modify the member
        // variables of any instance of this class.
        friend class Set;
};

std::ostream &operator<<( std::ostream &out, Set const &rhs ) {
    out << "{";
    if ( !rhs.empty() ) {
        out << rhs.p_head_->value();
        for ( Node *ptr{ rhs.p_head_->next() }; ptr != nullptr; ptr = ptr->next() ) {
            out << ", " << ptr->value();
        }
    }
    out << "}";
    return out;
}

int Node::value() const {
    return value_;
}

Node *Node::next() const {
    return next_;
}

Set::Set ( Set const &orig){
    for ( Node *ptr{ orig.p_head_ }; ptr != nullptr; ptr = ptr->next() ) {
        // Call 'insert(...)' with the value returned by ptr->value()
        insert(ptr->value());
    }
}

Set &Set::operator|=( Set const &rhs ){
    for(Node *ptr{rhs.p_head_};ptr != nullptr; ptr = ptr->next()){
        insert(ptr->value());
    }
    return *this;
}

Set::Set (Set &&orig){
    p_head_ = nullptr;
    std::swap( p_head_, orig.p_head_ );
}

Set &Set::operator=( Set const &rhs ){
    if (this == &rhs){
        return *this;
    }
    this->clear();
    for ( Node *ptr{ rhs.p_head_ }; ptr != nullptr; ptr = ptr->next() ) {
        // Call 'insert(...)' with the value returned by ptr->value()
        insert(ptr->value());
    }
    return *this;
}

Set &Set::operator=(Set &&rhs){
    std::swap( p_head_, rhs.p_head_ );
    return *this;
}

Set &Set::operator&=( Set const &rhs ){
    for(Node *ptr{p_head_};ptr != nullptr;){
        Node *holder = ptr->next();
        if (rhs.find(ptr->value()) == nullptr){
            erase(ptr->value());
            ptr = holder;
        } else {
            ptr = ptr->next();
        }
    }
    return *this;
}

Set &Set::operator^=( Set const &rhs ){
    for(Node *ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next()){
        if (find(ptr->value()) != nullptr){
            erase(ptr->value());
        } else {
            insert(ptr->value());
        }
    }
    return *this;
}

Set &Set::operator-=( Set const &rhs ){
    for(Node *ptr{rhs.p_head_};ptr != nullptr; ptr = ptr->next()){
        erase(ptr->value());
    }
    return *this;
}

Set Set::operator|( Set const &other ) const {
    Set tmp{*this};
    tmp |= other;
    return tmp;
}

Set Set::operator&( Set const &other ) const {
    Set tmp{*this};
    tmp &= other;
    return tmp;
}

Set Set::operator^( Set const &other ) const {
    Set tmp{*this};
    tmp ^= other;
    return tmp;
}

Set Set::operator-( Set const &other ) const {
    Set tmp{*this};
    tmp -= other;
    return tmp;
}

Node::Node(int new_value, Node *new_next):
    value_{new_value},
    next_{new_next} {

    }

bool Set::empty() const {
    if (p_head_ == nullptr){
        return true;
    } else {
        return false;
    }
}

void Set::clear() {
    while (p_head_ != nullptr){
        Node *holder = p_head_;
        p_head_ = p_head_->next();
        delete holder;
    }
    p_head_ = nullptr;
}

std::size_t Set::size() const {
    Node *holder{p_head_};
    std::size_t counter{0};
    while (holder != nullptr){
        holder = holder->next();
        counter++;
    }
    return counter;
}

Node *Set::find(const int &item) const {
    Node *holder{p_head_};
    while (holder != nullptr){
        if ((holder->value())==item){
            return holder;
        } else {
            holder = holder->next();
        }
    }
    return nullptr;
}

Set::~Set(){
    this->clear();
}

std::size_t Set::insert( int const array[], std::size_t const begin, std::size_t const end ){
    std::size_t counter{0};
    for (std::size_t k{begin}; k < end; k++){
        if (find(array[k])==nullptr){
            insert(array[k]);
            counter++;
        }
    }
    return counter;
}

std::size_t Set::erase( int const &item ){
    Node *holder = find(item);
    if (holder==nullptr){
        return 0;
    } else {
        Node *holder2 = p_head_->next();
        Node *holder3 = p_head_;
        if (holder == p_head_){
            p_head_ = p_head_->next();
            delete holder;
        } else {
            while ((holder2!=holder) && (holder2 != nullptr)){
            holder2 = holder2->next();
            holder3 = holder3->next();
            }
            if (holder2->next() == nullptr){
                holder3->next_ = nullptr;
            } else {
                holder3->next_ = holder2->next();
            }
            delete holder;
            holder2 = nullptr;
            holder3 = nullptr;
        }
    }
    if (empty()){
        p_head_ = nullptr;
    }
    return 1;
}

std::size_t Set::merge( Set &other ){
    std::size_t counter{0};
    Node *last_ptr = nullptr;
    for (Node *ptr{other.p_head_}; ptr != nullptr;){
        if (find(ptr->value())==nullptr){
            counter++;
            Node *hold = p_head_;
            Node *hold2 = ptr->next();
            p_head_ = ptr;
            if (last_ptr != nullptr){
                last_ptr->next_ = hold2;
            } else {
                other.p_head_ = other.p_head_->next();
            }
            p_head_->next_ = hold;
            ptr = hold2;
        } else {
            last_ptr = ptr;
            ptr = ptr->next();
        }
    }
    return counter;
}

std::size_t Set::insert(int const &item){
    if (find(item)!=nullptr){
        return 0;
    }
    Node *new_node{new Node(item, p_head_)};
    p_head_ = new_node;
    return 1;
}

bool Set::operator>=( Set const &other ) const {
    for(Node *ptr{other.p_head_};ptr != nullptr; ptr = ptr->next()){
        if (find(ptr->value()) == nullptr){
            return false;
        }
    }
    return true;
}

// A superset but not equal to.
bool Set::operator>( Set const &other ) const {
    if (*this>=other){
        if (size() != other.size()){
            return true;
        }
    }
    return false;
}

// Is 'this' a subset of the other set?
bool Set::operator<=( Set const &other ) const {
    return (other >= *this);
}

// A subset but not equal to.
bool Set::operator<( Set const &other ) const {
    return (other > *this);
}

bool Set::operator==( Set const &other ) const {
    if ((other>=*this)&&(*this>=other)){
        return true;
    }
    return false;
}

bool Set::operator!=( Set const &other ) const {
    return !(*this==other);
}

