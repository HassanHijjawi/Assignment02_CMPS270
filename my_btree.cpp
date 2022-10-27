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

    void addNode(treeNode<T>* node)
    {
        root =addNode(root,node);
    }
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

    treeNode<T>* search(T value)
    {
        return search_Helper(root,value);
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

    void deleteNode (T value)
    {
        treeNode<T>* node = search(value);
        if((node ==NULL) || (node->left != NULL) || (node->right != NULL))
            cout << "CANNOT DELETE THIS NODE";

        else
        {
            delete(node);
        }
    }

    int treeSize()
    {
        return treeSize_Helper(root);
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

    int subtree(T value)
    {
        treeNode<T>* node = search(value);
        int size = 1+ treeSize_Helper(node);
        return size;
    }

    void postorder_Traversal()
    {
        cout << "Post order Traversal:";
        postOrder(root);
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

      void preorder_Traversal()
    {
        cout << "Pre Order Traversal:";
        preOrder(root);
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

    void inorder_Traversal()
    {
        cout << "In order Traversal:";
        inOrder(root);
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

};


int main()
{
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
    cout << "After deleting the node that has the value 9, the in order traversal becomes:" << endl;
    tree -> inorder_Traversal();
    cout << endl;


    delete(root);
    delete(node1);
    delete(node2);
    delete(node3);
    delete(node4);
    delete(node5);

    return 0;
}