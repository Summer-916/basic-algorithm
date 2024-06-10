#include<iostream>

using namespace std;

// - 1.二叉树节点及类定义
template<typename T>
struct TreeNode{
    T val;
    TreeNode* left;
    TreeNode* right;

    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(T x):val(x),left(nullptr),right(nullptr){}
};

template<typename T>
class Tree{
private:
    TreeNode<T>* root;
    TreeNode<T>* nodes;
    size_t nodeSize;

    TreeNode<T>* create(T a[], int size, int nodeId, T nullNode);
    void visit(TreeNode<T>* node);
    void preOrder(TreeNode<T>* node);
    void inOrder(TreeNode<T>* node);
    void postOrder(TreeNode<T>* node);
    void invertHelper(TreeNode<T>* node);

public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* getNode(int id);
    void createTree(T a[], int size, T nullNode);
    void preOrderTraversal();
    void inOrderTraversal();
    void postOrderTraversal();
    void invert();
};

// - 1-1.二叉树构造与析构
template<typename T>
Tree<T>::Tree(){
    nodeSize = 100001;
    nodes = new TreeNode<T> [nodeSize];
}

template<typename T>
Tree<T>::Tree(int maxSize){
    nodeSize = maxSize;
    nodes = new TreeNode<T> [nodeSize];
}

template<typename T>
Tree<T>::~Tree(){
    delete[] nodes;
}

// - 1-2.获取二叉树节点
template<typename T>
TreeNode<T>* Tree<T>::getNode(int id){
    return &nodes[id];
}

// - 1-3.访问二叉树节点
template<typename T>
void Tree<T>::visit(TreeNode<T>* node){
    cout<< node->val<< " ";
}

// - 1-4.二叉树初始化
// - 创建节点
template<typename T>
TreeNode<T>* Tree<T>::create(T a[], int size, int nodeId, T nullNode){
    if(nodeId>=size||a[nodeId] == nullNode){
        return nullptr;
    }
    TreeNode<T>* nowNode = getNode(nodeId);
    nowNode->val = a[nodeId];
    nowNode->left = create(a,size,2*nodeId,nullNode);
    nowNode->right = create(a,size,2*nodeId+1,nullNode);
    return nowNode;
}
// - 创建根节点
template<typename T>
void Tree<T>::createTree(T a[],int size,T nullNode){
    root = create(a, size, 1, nullNode);
}

// - 1-5.二叉树遍历
// - 前序遍历
template<typename T>
void Tree<T>::preOrder(TreeNode<T>* node){
    if(node){
        visit(node);
        preOrder(node->left);
        preOrder(node->right);
    }
}

template<typename T>
void Tree<T>::preOrderTraversal(){
    preOrder(root);
}
// - 中序遍历
template<typename T>
void Tree<T>::inOrder(TreeNode<T>* node){
    if(node){
        inOrder(node->left);
        visit(node);
        inOrder(node->right);
    }
}

template<typename T>
void Tree<T>::inOrderTraversal(){
    inOrder(root);
}
// - 后序遍历
template<typename T>
void Tree<T>::postOrder(TreeNode<T>* node){
    if(node){
        postOrder(node->left);
        postOrder(node->right);
        visit(node);
    }
}

template<typename T>
void Tree<T>::postOrderTraversal(){
    postOrder(root);
}

// - 1-6.反转子树
template<typename T>
void Tree<T>::invertHelper(TreeNode<T>* node){
    if(node){   
        TreeNode<T>* tem = node->left;
        node->left = node->right;
        node->right = tem;
        invertHelper(node->left);
        invertHelper(node->right);
    }
}

template<typename T>
void Tree<T>::invert(){
    invertHelper(root);
}

// - test zone
int main(){
    const int nullint = -1;
    int target[16] = {
        nullint,1,2,3,4,5,
        6,7,8,9,10,
        11,12,13,14,15
    };
    Tree<int> testTree(15);
    testTree.createTree(target,16,nullint);
    testTree.invert();
    testTree.preOrderTraversal();
}