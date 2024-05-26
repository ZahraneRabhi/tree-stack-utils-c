# Binary Search Tree(BST) hand execution based on 4 traverse Algorithms

- Depth-first traversals can be prefixed, infixed or suffixed. The depth-first traversals are as follows:

- Given an array of integers A = [100, 20, 30, 150, 110, 10, 25, 45, 160, 200]
### ***Prefix (or pre-order):*** 
###### Visit node, then left subtree, then right subtree.
> ***Result for A:*** 100, 20, 10, 5, 30, 25, 45, 150, 110, 120, 160, 200.

### ***Infix (or average order):*** 
###### Visit left subtree, then node, then right subtree.
> ***Result for A:*** 5, 10, 20, 25, 30, 45, 100, 110, 120, 150, 160, 200.

### Suffix (or post-order):
##### Visit left subtree, then right subtree, then node.
> ***Result for A:*** 5, 10, 25, 45, 30, 20, 120, 110, 200, 160, 150, 100.

### Elements of A after a width traversal(parcours en largeur):

##### The width-traversal visits nodes in levels, from root to leaves.

>***Result for A:*** 100, 20, 150, 10, 30, 110, 160, 5, 25, 45, 120, 200.