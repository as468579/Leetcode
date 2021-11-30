
from typing import Sized


class DisjointSetArray:
    def __init__(self, arr):
        self.groups = list(arr)
        self.size   = [0 for _ in self.groups]

        # Count number of elements in each groups
        for g in self.groups:
            self.size[g] += 1
        

    def isEquivalent(self, ds2):
        for (g1, g2) in zip(self.groups, ds2.groups):
            if (g1 != g2):
                return False
        return True

    def find(self, x):
        return self.groups[x]

    # Merge the sets that belong to x and y individually
    def merge(self, x, y):
        if self.groups[x] == self.groups[y]: return 

        gsmall, glarge = self.groups[x], self.groups[y]
        if self.size[self.groups[x]] > self.size[self.groups[y]]:
            gsmall, glarge = self.groups[y], self.groups[x]
        
        self.size[glarge] += self.size[gsmall]
        self.size[gsmall] = 0
        for index in range(len(self.groups)):

            if self.groups[index] == gsmall:
                self.groups[index] = glarge



    # Calculate the cardinality of the set which x belongs to
    def getCardinality(self, x):
        return self.size[self.groups[x]]

    # def merge(self, x, y):
    


    # def isSingleton(self, x):

# if __name__ == '__main__':

        