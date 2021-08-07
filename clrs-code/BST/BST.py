
class BSTNode(object):
    '''A node in the vanilla BST tree.'''

    def __init__(self, parent, k):
        '''Create a node.
        Argus:
            parent: The node's parent.
            k: The key of the node.
        '''
        self.key = k
        self.parent = parent
        self.left = None
        self.right = None

    def find(self, k):
        '''Find and returns the node with key from subtree rooted at this node.
            Argus:
                k: The key of the node we want to find.
        '''
        if k == self.key:
            return self
        elif k < self.key:
            if self.left is None:
                return None
            else:
                return self.left.find(k)
        else:
            if self.right is None:
                return None
            else:
                return self.right.find(k)

    def find_min(self):
        '''Finds the node with the minimum key in the subtree rooted at this node.
        Returns:
            The node with the minimum key.
        '''
        current = self
        while current.left is not None:
            current = current.left
        return current
    
    def next_larger(self):
        '''Returns the node with the next larger key (the successor) in the BST.'''
        if self.right is not None:
            return self.right.find_min()
        current = self
        while current.parent is not None and current is current.parent.right:
            current = current.parent
        return current.parent
    
    def insert(self, node):
        '''Inserts a node into the subtree rooted at this node.
        Argus:
            node: The node to be inserted.
        '''
        if node is None:
            return
        if node.key < self.key:
            if self.left is None:
                node.parent = self
                self.left = node
            else:
                self.left.insert(node)
        else:
            if self.right is None:
                node.parent = self
                self.right = node
            else:
                self.right.insert(node)