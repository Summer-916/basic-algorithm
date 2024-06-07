// - Binary Search Tree
#include<iostream>
using namespace std;

// - 1.二叉搜索树定义
template<typename T>
struct TreeNode{
    T val;
    TreeNode<T>* left;
    TreeNode<T>* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

template<typename T>
class binarySearchTree{
private:
    TreeNode<T>* root;
    TreeNode<T>* insertNode(TreeNode<T>* node, T x);
    TreeNode<T>* removeNode(TreeNode<T>* node, T x);
    bool searchNode(TreeNode<T>* node, T x);
    void inOrder(TreeNode<T>* node);
public:
    binarySearchTree():root(nullptr){}
    ~binarySearchTree();
    void destoryNode(TreeNode<T>* node);
    void insert(T val){
        root = insertNode(root,val);
    }
    void remove(T val){
        root = removeNode(root,val);
    }
    bool search(T val){
        if(searchNode(root,val)) return true;
        else return false;
    }
    void inOrderTraversal(){
        inOrder(root);
        cout<<endl;
    }
};

// - 1-0. destory function
template<typename T>
binarySearchTree<T>::~binarySearchTree(){
    destoryNode(root);
}

template<typename T>
void binarySearchTree<T>::destoryNode(TreeNode<T>* node){
    if(node){
        destoryNode(node->left);
        destoryNode(node->right);
        delete node;
    }
}

// - 1-1. insert function
template<typename T>
TreeNode<T>* binarySearchTree<T>::insertNode(TreeNode<T>* node,T x){
    if(node == nullptr){
        return new TreeNode<T>(x);
    }

    if(x<node->val){
        node->left = insertNode(node->left,x);
    }else if(x>node->val){
        node->right = insertNode(node->right,x);
    }
    return node;
}

// - 1-2. remove function
template<typename T>
TreeNode<T>* binarySearchTree<T>::removeNode(TreeNode<T>* node,T x){
    if(node == nullptr){
        return nullptr;
    }
    
    if(x<node->val){    
        node->left = removeNode(node->left,x);
    }else if(x>node->val){
        node->right = removeNode(node->right,x);
    }else{
        if(node->left==nullptr&&node->right==nullptr){
            delete node;
            node = nullptr;
            return nullptr;
        }else if(node->left == nullptr){
            TreeNode<T>* tem = node->right;
            delete node;
            node = tem;
            return node;
        }else if(node->right == nullptr){
            TreeNode<T>* tem = node->left;
            delete node;
            node = tem;
            return node;
        }else{
            TreeNode<T>* replacement = node->right;
            while(replacement->left){
                replacement = replacement->left;
            }
            node -> val = replacement->val;
            node -> right = removeNode(node->right,replacement->val);
        }
    }
    return node;
}

// - 1-3. search function
template<typename T>
bool binarySearchTree<T>::searchNode(TreeNode<T>* node,T x){
    if(node == nullptr) return false;

    if(x<node->val){
        return searchNode(node->left,x);
    }else if(x>node->val){
        return searchNode(node->right,x);
    }else return true;
}

// - 1-4.in-order function
template<typename T>
void binarySearchTree<T>::inOrder(TreeNode<T>* node){
    if(node == 0) return;
    inOrder(node->left);
    cout<<node->val<<" ";
    inOrder(node->right);
}
// - test zone
int main(){
    binarySearchTree<int> b1;
    b1.insert(4);
    b1.insert(2);
    b1.insert(5);
    b1.insert(6);
    b1.insert(1);
    b1.insert(3);
    b1.inOrderTraversal();
}