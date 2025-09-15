#include <iostream>
using namespace std;

template <typename type>
class BST
{
protected:
    // FILE *pointer = fopen("out.txt", "w");

    struct bstnode
    {
        type data;
        struct bstnode *left;
        struct bstnode *right;
    };
    // Structure for tree node.

    struct bstnode *root, *currentnode;

    struct bstnode *createnode(type data)
    {
        struct bstnode *temp = new (struct bstnode);
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    void InorderTraverse(struct bstnode *node)
    {
        if (node == NULL)
            return;
        this->InorderTraverse(node->left);
        cout << node->data << " ";
        // fprintf(pointer, "%d ", node->data);
        this->InorderTraverse(node->right);
    }

    void PreorderTraverse(struct bstnode *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        // fprintf(pointer, "%d ", node->data);
        this->PreorderTraverse(node->left);
        this->PreorderTraverse(node->right);
    }

    void PostorderTraverse(struct bstnode *node)
    {
        if (node == NULL)
            return;
        this->PostorderTraverse(node->left);
        this->PostorderTraverse(node->right);
        cout << node->data << " ";
        // fprintf(pointer, "%d ", node->data);
    }

    void printsubtree(struct bstnode *node)
    {
        if (node == NULL)
        {
            return;
        }
        cout << node->data;
        // fprintf(pointer, "%d", node->data);
        if (node->left != NULL || node->right != NULL)
        {
            cout << "(";
            // fprintf(pointer, "(");
            printsubtree(node->left);
            cout << ",";
            // fprintf(pointer, ",");
            printsubtree(node->right);
            cout << ")";
            // fprintf(pointer, ")");
        }
        else
        {
            return;
        }
    }

public:
    BST()
    {
        root = NULL;
        currentnode = NULL;
    }

    void Insert(type data)
    {
        if (root == NULL)
        {
            root = createnode(data);
        }
        else if (data < currentnode->data)
        {
            if (currentnode->left == NULL)
            {
                currentnode->left = createnode(data);
            }
            else
            {
                currentnode = currentnode->left;
                Insert(data);
            }
        }
        else if (data > currentnode->data)
        {
            if (currentnode->right == NULL)
            {
                currentnode->right = createnode(data);
            }
            else
            {
                currentnode = currentnode->right;
                Insert(data);
            }
        }
        currentnode = root;
    }

    void Delete(type key)
    {
        bool flag;
        int dir;
        currentnode = root;
        struct bstnode *parrent;

        while (1)
        {
            if (currentnode == NULL)
            {
                flag = false;
                break;
            }
            else if (root->data == key)
            {
                parrent = NULL;
                currentnode = root;
                flag = true;
                break;
            }
            else if (currentnode->left != NULL && currentnode->left->data == key)
            {
                parrent = currentnode;
                currentnode = currentnode->left;
                flag = true;
                dir = 1;
                break;
            }
            else if (currentnode->right != NULL && currentnode->right->data == key)
            {
                parrent = currentnode;
                currentnode = currentnode->right;
                flag = true;
                dir = 2;
                break;
            }
            else if (key < currentnode->data)
            {
                currentnode = currentnode->left;
            }
            else if (key > currentnode->data)
            {
                currentnode = currentnode->right;
            }

            // if (flag)
            //     break;
        }
        // Codes for deletion
        cout<<endl<<currentnode->data<<endl;
        if (flag)
        {
            if (currentnode->left == NULL && currentnode->right == NULL)
            {
                if (currentnode == root)
                {
                    delete currentnode;
                    currentnode = root = NULL;
                }
                else
                {
                    if (dir == 1)
                    {
                        parrent->left = NULL;
                        delete currentnode;
                    }
                    else if (dir == 2)
                    {
                        parrent->right = NULL;
                        delete currentnode;
                    }
                }
            }
            else if (currentnode->left == NULL || currentnode->right == NULL)
            {
                if (currentnode == root)
                {
                    if (currentnode->left == NULL)
                    {
                        root = currentnode->right;
                    }
                    else if (currentnode->right == NULL)
                    {
                        root = currentnode->left;
                    }
                }
                else if (currentnode->left == NULL)
                {
                    if (dir == 1)
                    {
                        parrent->left = currentnode->right;
                    }
                    else if (dir == 2)
                    {
                        parrent->right = currentnode->right;
                    }
                }
                else if (currentnode->right == NULL)
                {
                    if (dir == 1)
                    {
                        parrent->left = currentnode->right;
                    }
                    else if (dir == 2)
                    {
                        parrent->right = currentnode->right;
                    }
                }
                delete currentnode;
            }
            else if (currentnode->left != NULL && currentnode->right != NULL)
            {
                struct bstnode *temp = currentnode->right;
                type minimum = temp->data;
                if (temp->left == NULL)
                {
                    currentnode->data=minimum;
                    currentnode->right=NULL;
                    delete temp;
                }
                else
                {
                    while (temp->left != NULL)
                    {
                        if (temp->left->left != NULL)
                        {
                            temp = temp->left;
                            minimum = temp->left->data;
                        }
                    }
                    currentnode->data = minimum;
                    delete temp->left;
                    temp->left = NULL;
                }
            }
        }
    }

    // void Delete(type key)
    // {
    //     deleteNode(root, key);
    // }

    // struct bstnode *deleteNode(struct bstnode *node, type key)
    // {
    //     if (node == NULL)
    //         return node;

    //     if (node->data > key)
    //     {
    //         node->left = deleteNode(node->left, key);
    //         return node;
    //     }
    //     else if (node->data < key)
    //     {
    //         node->right = deleteNode(node->right, key);
    //         return node;
    //     }

    //     // If one of the children is empty
    //     if (node->left == NULL)
    //     {
    //         struct bstnode *temp = node->right;
    //         delete node;
    //         return temp;
    //     }
    //     else if (node->right == NULL)
    //     {
    //         struct bstnode *temp = node->left;
    //         delete node;
    //         return temp;
    //     }

    //     // If both children exist
    //     else
    //     {

    //         struct bstnode *succParent = node;
    //         struct bstnode *succ = node->right;
    //         while (succ->left != NULL)
    //         {
    //             succParent = succ;
    //             succ = succ->left;
    //         }
    //         if (succParent != node)
    //             succParent->left = succ->right;
    //         else
    //             succParent->right = succ->right;

    //         node->data = succ->data;

    //         delete succ;
    //         return node;
    //     }
    // }

    bool Find(type key)
    {
        bool flag;
        currentnode = root;
        while (1)
        {
            if (currentnode == NULL)
            {
                flag = false;
                break;
            }
            else if (currentnode->data == key)
            {
                flag = true;
                break;
            }
            else if (key < currentnode->data)
            {
                currentnode = currentnode->left;
            }
            else if (key > currentnode->data)
            {
                currentnode = currentnode->right;
            }
        }
        currentnode = root;
        // if (flag)
        // {
        //     fprintf(pointer, "found\n");
        // }
        // else
        // {
        //     fprintf(pointer, "not found\n");
        // }
        return flag;
    }
    void InorderTraverse()
    {
        InorderTraverse(root);
        // fprintf(pointer, "\n");
        cout << endl;
    }
    void PreorderTraverse()
    {
        PreorderTraverse(root);
        // fprintf(pointer, "\n");
        cout << endl;
    }
    void PostorderTraverse()
    {
        PostorderTraverse(root);
        // fprintf(pointer, "\n");
        cout << endl;
    }

    void printsubtree()
    {
        cout << "(";
        // fprintf(pointer, "(");
        printsubtree(root);
        cout << ")";
        // fprintf(pointer, ")\n");
    }
};

int main()
{
    BST<int> b1;
    b1.Insert(1);
    b1.Insert(5);
    b1.Insert(3);
    b1.Insert(15);
    b1.Insert(100);
    b1.Insert(4);
    b1.Insert(8);
    b1.Insert(11);
    b1.Insert(12);
    b1.Insert(9);
    b1.Insert(6);

    // b1.Insert(8);
    // b1.Insert(3);
    // b1.Insert(1);
    // b1.Insert(6);
    // b1.Insert(4);
    // b1.Insert(7);
    // b1.Insert(10);
    // b1.Insert(14);
    // b1.Insert(15);
    cout << "\nPrinting Inorder traversal\n";
    b1.InorderTraverse();
    cout << "\nPrinting Preorder traversal\n";
    b1.PreorderTraverse();
    cout << "\nPrinting Postorder\n";
    b1.PostorderTraverse();

    // if (b1.Find(13))
    // {
    //     cout << "\nFound\n";
    // }
    // else
    // {
    //     cout << "\nNot Found\n";
    // }
    cout << endl;
    cout << "1" << endl;
    b1.printsubtree();
    //b1.Delete(12);
    b1.Delete(5);
    cout << endl;
    cout << "2" << endl;
    b1.printsubtree();
    cout<<endl;
    b1.InorderTraverse();
}