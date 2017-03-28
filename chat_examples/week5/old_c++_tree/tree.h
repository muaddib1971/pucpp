#include <iostream>
/**************************************************************************
 * Example of a tree class written in old style c++. Note: your tree class
 * for assignment 1 MUST be a modern c++ class with unique_ptr. This example
 * is provided for those struggling with the binary search tree data 
 * structure. If you use this code you must have a comment explaining where
 * you got the code from, as you should be doing with any other code. 
 *************************************************************************/
class tree
{
    /* the node struct for our tree - I've used a struct as it should be 
     * public to the tree class but it is private to those outside of 
     * this class.
     */
    struct node
    {
        /* a tree node is made up of left and right pointers to nodes */
        node * left;
        node * right;
        /* don't forget to change the stored datatype */
        int data;
        node(int mydata) : left(nullptr), right(nullptr), data(mydata)
        {
        }

        /* adding data to a tree is a recursive function. if the value
         * we wish to insert is greater than the current node, it goes
         * to the left and otherwise it goes to the right of the current
         * node. 
         */
        bool add(int mydata)
        {
            /* insert in the left subtree if the value is less than the 
             * current node
             */
            if(mydata < data)
            {
                /* if there is a pointer to the left already, add to the 
                 * subtree
                 */
                if(left)
                {
                    return left->add(mydata);
                }
                else
                {
                    /* otherwise allocate new data here */
                    left = new node(mydata);
                    if(left)
                    {
                        return true;
                    }
                    return false;
                }
            }
            else
            {
                if(right)
                {
                    return right->add(mydata);
                }
                else
                {
                    right = new node(mydata);
                    if(right)
                    {
                        return true;
                    }
                    return false;
                }
            }
        }

        /* this is what we call an in-order traversal: we print the left
         * subtree then the current node then the right subtree
         */
        void print(void)
        {
            if(left)
            {
                left->print();
            }
            std::cout << data << std::endl;
            if(right)
            {
                right->print();
            }
        }

        /* deleting data is recursive too - delete the left subtree and 
         * then the right subtree 
         */
        virtual ~node(void)
        {
            if(left)
            {
                delete left;
            }
            if(right)
            {
                delete right;
            }
        }
    };

    node * root;
    public:
    tree() : root(nullptr) {}

    /* adding to the tree is really just adding to the root and then 
     * allowing the recursive nature of the tree decide where the 
     * element should be stored
     */
    bool add(int data)
    {
        if(root)
        {
            return root->add(data);
        }
        root = new node(data);
        if(root)
        {
            return true;
        }
        return false;
    }

    void print(void)
    {
        root->print();
    }

    virtual ~tree(void)
    {
        delete root;
    }
};
