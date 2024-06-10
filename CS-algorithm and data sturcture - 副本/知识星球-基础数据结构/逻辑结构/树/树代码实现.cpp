#include<iostream>

using namespace std;

// - 1.节点定义
template<typename T>
struct ListNode{
    T data;
    ListNode* next;
    ListNode(T d):data(d),next(nullptr){}
};

// - 2.树的节点定义
template<typename T>
struct TreeNode{
    T data;
    ListNode<TreeNode<T>*> *childrenHead; // - 孩子链表

    TreeNode(){
        childrenHead = nullptr;
    }

    void AddChild(TreeNode<T> *node){
        ListNode<TreeNode<T>*> *childNode = new ListNode<TreeNode<T>*> (node);
        if(childrenHead == nullptr){
            childrenHead = childNode;
        }else{
            childrenHead->next = childNode;
        }
    }
};

// - 3.树类的定义
template<typename T>
class Tree{
private:
    TreeNode<T> *nodes;
    TreeNode<T> *root;
public:
    Tree();
    Tree(int maxNodes);
    ~Tree();
    TreeNode<T>* getTreeNode(int id);
    void setRoot(int rootId);
    void AddChild(int parentId,int sonId);
    void setData(int nodeId,T d);
    void print(TreeNode<T> *node = nullptr);
};

// - 3-1.树的创建与销毁
template<typename T>
Tree<T>::Tree(){
    nodes = new TreeNode<T> [100001];
}

template<typename T>
Tree<T>::Tree(int maxNodes){
    nodes = new TreeNode<T> [maxNodes];
}

template<typename T>
Tree<T>::~Tree(){
    delete[] nodes;
}

// - 3-2.获取树的节点
template<typename T>
TreeNode<T>* Tree<T>::getTreeNode(int id){
    return &nodes[id];
}

// - 3-3.设置树的根节点
template<typename T>
void Tree<T>::setRoot(int rootId){
    root = getTreeNode(rootId);
}

// - 3-4.设置树的变边
template<typename T>
void Tree<T>::AddChild(int parentId,int sonId){
    TreeNode<T>* parentNode = getTreeNode(parentId);
    TreeNode<T>* sonNode = getTreeNode(sonId);
    parentNode->AddChild(sonNode);
}

// - 3-5.设置节点的值
template<typename T>
void Tree<T>::setData(int nodeId,T d){
    getTreeNode(nodeId)->data = d;
}

// - 3-6.树的深度优先遍历
template<typename T>
void Tree<T>::print(TreeNode<T>* node){
    if(node == nullptr){
        node = root;
    }
    cout<<node->data;
    ListNode<TreeNode<T>*> *tem = node->childrenHead;
    while(tem){
        print(tem->data); // - 先打印孩子的孩子，在打印孩子的兄弟
        tem = tem->next;
    }
}

// - test zone
int main(){
    Tree<char> T(9);
    T.setRoot(0);
    T.setData(0,'a');
    T.setData(1,'b');
    T.setData(2,'c');
    T.setData(3,'d');
    T.setData(4,'e');
    T.setData(5,'f');
    T.setData(6,'g');
    T.setData(7,'h');
    T.setData(8,'i');

    T.AddChild(0,1);
    T.AddChild(0,2);
    T.AddChild(1,3);
    T.AddChild(2,5);
    T.AddChild(2,4);
    T.AddChild(3,8);
    T.AddChild(3,7);
    T.AddChild(3,6);

    T.print();

    return 0;
}