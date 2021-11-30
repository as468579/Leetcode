from DisjointSetInterface import DisjointSetInterface

class DisjointSetForest(DisjointSetInterface):
    def __init__(self, n):
        self.parents = [x for x in range(n)]
        self.sizes   = [1 for _ in range(n)]

    def find(self, n):
        if self.parents[n] == n: return n
        self.parents[n] = self.find(self.parents[n])  # path compression
        return self.parents[n]

    def getCardinality(self, x):
        return self.sizes[self.find(x)]

    def merge(self, x, y):
        parent_x, parent_y = self.find(x), self.find(y)
        if parent_x == parent_y: return False

        if self.sizes[parent_x] < self.sizes[parent_y]:
            self.parents[parent_x] = parent_y
            self.sizes[parent_y] += self.sizes[parent_x]
        else:
            self.parents[parent_y] = parent_x
            self.sizes[parent_x] += self.sizes[parent_y]
        return True

    def isEquivalent(self, x, y):
        return self.find(x) == self.find(y)
        
        

