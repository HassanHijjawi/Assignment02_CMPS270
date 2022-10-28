/*
    !! For the specifications, we assume the existence of the btree Tree that can access all functions of the struct btree.

    struct treeNode<T>* createNode (T data)

    requires: The type T must be either an int or char.
    effects: It creates a node whose value is T data, and its left and right children are NULL. A pointer to the created node is returned.

    TestCases -> Output:
    1) Covers if NULL is passed: 
    createNode (NULL) --> No node created.   

    2) Covers if positive integer is passed: 
    createNode (5) --> Returns a pointer to a node of value 5, left child is NULL, right child is node.

    3) Covers if negative integer is passed: 
    createNode (-7) --> Returns a pointer to a node of value -7, left child is NULL, right child is node.

    4) Covers if zero is passed:createNode (0) --> 
    Returns a pointer to a node of value 0, left child is NULL, right child is node.

    5) Covers is a lowercase char is passed: 
    createNode ('a') --> Returns a pointer to a node of value 'a', left child is NULL, right child is node.

    6) Covers if UpperCase char is passed:
    createNode ('Z') --> Returns a pointer to a node of value 'Z', left child is NULL, right child is node.

    7) Covers if an int is passed as a char:
    createNode ('9') --> Returns a pointer to a node of value '9', left child is NULL, right child is node.


    *****************************************************************************************************************************************
     void addNode(treeNode<T>* node)

     Requires: A node whose value is of type int or char
     Effects: Adds the node to the highest place while preserving the BST properties.

     This function checks if the passed node is NULL or not before procceeding by calling its helper function to reduce bugs.

     !!!  treeNode<T>* addNode(treeNode<T>* root, treeNode<T>*node)
    
    requires: The type T must be an int or char.
    effects: On the first call, it creates the root. Later passed node in other calls will be correctly positioned in the BST.

    TestCases:
    addNode (NULL) --> Root is still null.

    Sequence of operations if T is int:
    addNode (5) --> Root is 5.
    addNode (6)  --> Node is right child of 5.
    addNode (7) --> Node is right child of 6.
    addNode (4) --> Node is left child of 5.
    addNode(3) --> Node is left child of 4.

    Sequence of operations if T is char:
    addNode ('b') --> Root is 'b'.
    addNode ('c')  --> Node is right child of 'b'.
    addNode ('d') --> Node is right child of 'c'.
    addNode ('a') --> Node is left child of 'b'.
    addNode('Z') --> Node is left child of 'a'.

    *****************************************************************************************************************************************

    int treeSize_Helper(treeNode<T>* root)
    requires: The type T must be an int or char.
    effects: Returns the number of nodes in the tree.

    TestCases:
    1) Covers when we have no nodes
    treeSize(root) when the root is null --> returns 0
    2) Covers for even sizes
    treeSize (root) when we inserted 4 nodes --> returns 4.
    3)Covers for odd sizes
    treeSize(root) when we inserted 9 nodes --> returns 9.

    *****************************************************************************************************************************************

    int subtree(T value)

    Very similar to the treeSize_Helper function.
    It treats the tree rooted at the node whose data is equal to the passed value as a seperate tree and returns its sub-children.

    ****************************************************************************************************************************************

    The functions:
    1)void postorder_Traversal() --> Prints the postorder traversal of the tree (left -> right -> node)  //Effects
    2)void preorder_Traversal() --> Prints the pre-order traversal of the tree (root -> left -> right)   //Effects
    3)void inorder_Traversal() --> Prints the inorder traversal of the tree (left -> node -> right)      //Effects

     requires: The type T must be an int or char.

     If the root is empty, nothing gets printed.

    ***************************************************************************************************************************************

*/
#include <iostream>
using namespace std;

template <typename T>
struct treeNode {
T *data;
struct treeNode * left;
struct treeNode * right;

};

template <typename T>
struct treeNode<T>* createNode (T data)
{
    if(data == NULL)
        return NULL;
    treeNode <T>* node = new struct treeNode<T>;
    T *ptrData = new T;
    *ptrData = data; 
    node ->data = ptrData;
    node ->left = NULL;
    node -> right = NULL;
    return node;
}

template<typename T>
struct btree {
     treeNode<T>* root = NULL;

    private:

     //If type T is a char, values are compared according to their ASCII values.
     treeNode<T>* addNode(treeNode<T>* root, treeNode<T>*node)
    {
        if(root==NULL)
        {
            root = node;
            return root;
        }
        else if (*(root->data)>=*(node->data))
        {
            root->left = addNode(root->left,node);
        }
        else
        {
            root->right = addNode(root->right,node);
        }
        return root;
    }

     treeNode<T>* search_Helper(treeNode<T> * root, T value)
    {
        if(root == NULL)
            return NULL;

        else if((*(root ->data) == value))
            return root;

            else if(value > *(root -> data))
                return search_Helper(root ->right,value);

                else if(value < *(root ->data))
                    return search_Helper(root->left,value); 

    }

     int treeSize_Helper(treeNode<T>* root)
    {
        if(root == NULL)
            return 0;

        else
        {
            return 1 + treeSize_Helper(root -> left) + treeSize_Helper(root -> right);
        }
    }

     void postOrder(treeNode<T>* root)
    {
          if (root == NULL) {
          return ;
        }
              postOrder(root->left);
              postOrder(root->right);
              cout<< *(root -> data) << " ";
    }

    void preOrder(treeNode<T>* root)
    {
          if (root == NULL) {
          return ;
        }
              
              cout<< *(root -> data) << " ";
              preOrder(root->left);
              preOrder(root->right);   
    }

     void inOrder(treeNode<T>* root)
    {
          if (root == NULL) {
          return ;
        }
              inOrder(root->left);
              cout<< *(root -> data) << " ";
              inOrder(root->right);   
    }

    public:
    void addNode(treeNode<T>* node)
    {
        if(node == NULL)
            {
                cout << "Cannot add a null node";
            }
        else
            root =addNode(root,node);
    }
   
    treeNode<T>* search(T value)
    {
        return search_Helper(root,value);
    }

    void deleteNode (T value)
    {
        treeNode<T>* node = search(value);
        if((node ==NULL) || (node->left != NULL) || (node->right != NULL))
            cout << "CANNOT DELETE THIS NODE" << endl;

        else
        {
            delete(node);
        }
    }

    int treeSize()
    {
        return treeSize_Helper(root);
    }

    int subtree(T value)
    {
        treeNode<T>* node = search(value);
        char size =  treeSize_Helper(node);
        return size;
    }

    void postorder_Traversal()
    {
        cout << "Post order Traversal:";
        postOrder(root);
    }
  
      void preorder_Traversal()
    {
        cout << "Pre Order Traversal:";
        preOrder(root);
    }

      void inorder_Traversal()
    {
        cout << "In order Traversal:";
        inOrder(root);
    }
    
};


int main()
{

    //Testing when the elements' type is int.
    treeNode<int>* root =  createNode(2);
    treeNode<int>* node1 = createNode(5);
    treeNode<int>* node2 = createNode(7);
    treeNode<int>* node3 = createNode(3);
    treeNode<int>* node4 = createNode(8);
    treeNode<int>* node5 = createNode(9);

    btree<int>* tree = new struct btree<int>;

    tree->addNode(root);
    tree->addNode(node1);
    tree->addNode(node2);
    tree->addNode(node3);
    tree->addNode(node4);
    tree->addNode(node5);

    cout << "The size of the tree is :" << tree -> treeSize() << endl;

    cout << "The size of the tree rooted at node of value 7 is: " << tree ->subtree(7) << endl;

    tree -> inorder_Traversal();
    cout << endl;

    tree -> postorder_Traversal();
    cout << endl;

    tree -> preorder_Traversal();
    cout << endl;

    tree -> deleteNode(9);
    cout << "After performig the delete function, the in-order traversal becomes:" << endl;
    tree -> inorder_Traversal();
    cout << endl;

    //Testing when the elements' type is char.

    // treeNode<char>* root =  createNode('f');
    // treeNode<char>* node1 = createNode('b');
    // treeNode<char>* node2 = createNode('v');
    // treeNode<char>* node3 = createNode('e');
    // treeNode<char>* node4 = createNode('m');
    // treeNode<char>* node5 = createNode('z');

    // btree<char>* tree = new struct btree<char>;

    // tree->addNode(root);
    // tree->addNode(node1);
    // tree->addNode(node2);
    // tree->addNode(node3);
    // tree->addNode(node4);
    // tree->addNode(node5);

    // cout << "The size of the tree is :" << tree -> treeSize() << endl;

    //  cout << "The size of the tree rooted at node of value 7 is: " << tree ->subtree('v') << endl;

    // tree -> inorder_Traversal();
    // cout << endl;

    // tree -> postorder_Traversal();
    // cout << endl;

    // tree -> preorder_Traversal();
    // cout << endl;

    // tree -> deleteNode('z');
    // cout << "After performig the delete function, the in-order traversal becomes:" << endl;
    // tree -> inorder_Traversal();
    // cout << endl;


    delete(root);
    delete(node1);
    delete(node2);
    delete(node3);
    delete(node4);
    delete(node5);

    return 0;
}