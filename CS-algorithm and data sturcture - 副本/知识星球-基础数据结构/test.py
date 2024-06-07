def preorderTraversal(root):
    if root is None:
        return []
    # 访问根节点的值，然后递归访问左子树和右子树
    return [root.val] + preorderTraversal(root.left) + preorderTraversal(root.right)


# 定义树节点
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

# 构建一棵树
#       1
#      / \
#     2   3
#    / \
#   4   5
root = TreeNode(1)
root.left = TreeNode(2, TreeNode(4), TreeNode(5))
root.right = TreeNode(3)

# 执行遍历
print("前序遍历:", preorderTraversal(root))
#print("中序遍历:", inorderTraversal(root))
#print("后序遍历:", postorderTraversal(root))
