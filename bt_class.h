// FILE: bt_class.h
// For Project 2 in Chapter 10 of "Data Structures and Other Objects Using C++"
// TEMPLATE CLASS PROVIDED: binary_tree<Item> (a binary tree where each node has
//   an item) The template parameter, Item, is the data type of the items in the
//   tree's nodes. It may be any of the C++ built-in types (int, char, etc.),
//   or a class with a default constructor, a copy constructor and an assignment
//   operator.
//
// NOTE: Each non-empty tree always has a "current node."  The location of
// the current node is controlled by three member functions: shift_up,
// shift_to_root, shift_left, and shift_right.
//
// CONSTRUCTOR for the binary_tree<Item> template class:
//   binary_tree( )  
//     Postcondition: The binary tree has been initialized as an empty tree
//     (with no nodes).
//
// MODIFICATION MEMBER FUNCTIONS for the binary_tree<Item> template class:
//   void create_first_node(const Item& entry)
//     Precondition: size( ) is zero.
//     Postcondition: The tree now has one node (a root node), containing the
//     specified entry. This new root node is the "current node."
//
//   void shift_to_root( )
//     Precondition: size( ) > 0.
//     Postcondition: The "current node" is now the root of the tree.
//
//   void shift_up( )
//     Precondition: has_parent( ) returns true.
//     Postcondition: The "current node" has been shifted up to the parent of
//     the old current node.
//
//   void shift_left( )
//     Precondition: has_left_child( ) returns true.
//     Postcondition: The "current node" been shifted down to the left child
//     of the original current node.
//
//   void shift_right( )
//     Precondition: has_right_child( ) returns true.
//     Postcondition: The "current node" been shifted down to the right child
//     of the original current node.
//
//   void change(const Item& new_entry)
//     Precondition: size( ) > 0.
//     Postcondition: The data at the "current node" has been changed to the
//     new entry.
//
//   void add_left(const Item& entry)
//     Precondition: size( ) > 0, and has_left_child( ) returns false.
//     Postcondition: A left child has been added to the "current node,"
//     with the given entry.
//
//   void add_right(const Item& entry)
//     Precondition: size( ) > 0, and has_right_child( ) returns false.
//     Postcondition: A right child has been added to the "current node,"
//     with the given entry.
//
// CONSTANT MEMBER FUNCTIONS for the binary_tree<Item> template class:
//   size_t size( ) const
//     Postcondition: The return value is the number of nodes in the tree.
//
//   Item retrieve( ) const
//     Precondition: size( ) > 0.
//     Postcondition: The return value is the data from the "current node."
//
//   bool has_parent( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a parent.
//
//   bool has_left_child( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a left child.
//
//   bool has_right_child( ) const
//     Postcondition: Returns true if size( ) > 0, and the "current node"
//     has a right child.
//
// VALUE SEMANTICS for the binary_tree<Item> template class:
//   Assignments and the copy constructor may be used with binary_tree objects.
//
// DYNAMIC MEMORY USAGE by the binary_tree<Item> template class:
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc:
//   create_first_node, add_left, add_right, the copy constructor, and the 
//   assignment operator.

#ifndef BT_CLASS_H
#define BT_CLASS_H
#include <cstdlib>    // Provides size_t
#include <cassert>    // Provides assert
#include "bintree.h"  // Provides binary_tree_node<Item> template class

namespace main_savitch_10
{
    template <class Item>
    class binary_tree
    {
    public:
        // CONSTRUCTORS and DESTRUCTOR
        binary_tree( );
        binary_tree(const binary_tree& source);
        ~binary_tree( );
        // MODIFICATION MEMBER FUNCTIONS
        void create_first_node(const Item& entry);
        void shift_to_root( );
        void shift_up( );
        void shift_left( );
        void shift_right( );
        void change(const Item& new_entry);
        void add_left(const Item& entry);
        void add_right(const Item& entry);
        // CONSTANT MEMBER FUNCTIONS
        std::size_t size( ) const;
        Item retrieve( ) const;
        const binary_tree_node<Item>* return_root() const;
        const binary_tree_node<Item>* return_current() const;
        bool has_parent( ) const;
        bool has_left_child( ) const;
        bool has_right_child( ) const;    
    private:
        // Private member variables to be specified by the student.
        // My own implementation has a root pointer and a pointer to
        // the "current" node, plus a member variable to keep track of
        // the number of nodes in this tree.
        binary_tree_node<Item> *root_ptr;
        binary_tree_node<Item> *current_ptr;
        size_t count;
    };

// ---------------------------
// TEMPLATE IMPLEMENTATION
// ---------------------------
    
    template <class Item>
    binary_tree<Item>::binary_tree( )
    {
        root_ptr = nullptr;
        current_ptr = nullptr;
        count = 0;
    }
    
    template <class Item>
    binary_tree<Item>::binary_tree(const binary_tree& source)
    {
        count = source.size(); // magic
        root_ptr = tree_copy(source->return_root);
        current_ptr = source->return_current();
    }
    
    
    template <class Item>
    void binary_tree<Item>::create_first_node(const Item& entry)
    {
        if (count == 0)
        {
            root_ptr = new binary_tree_node<Item>(entry);
            current_ptr = root_ptr;
        } else {
            std::cout << "Can't create first node for tree that has a first node already." << std::endl;
        }
    }
    
    template <class Item>
    void binary_tree<Item>::shift_to_root( )
    {
        if (count > 0)
        {
            
        }
    }
    
    template <class Item>
    void binary_tree<Item>::change(const Item& new_entry)
    {
        current_ptr->set_data(new_entry);
    }
    
    template <class Item>
    const binary_tree_node<Item>* binary_tree<Item>::return_root() const
    {
        return root_ptr;
    }
    
    template <class Item>
    const binary_tree_node<Item>* binary_tree<Item>::return_current() const{
        return current_ptr;
    }

    
    

}
#endif 
