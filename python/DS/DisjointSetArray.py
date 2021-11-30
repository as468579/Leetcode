from DisjointSetInterface import DisjointSetInterface

class DisjointSetArray(DisjointSetInterface):
    def __init__(self, n):
        self.groups = [x for x in range(n)]
        self.sizes   = [1 for _ in range(n)]

    def find(self, x):
        return self.groups[x]

    # Merge the sets that belong to x and y individually
    def merge(self, x, y):
        if self.groups[x] == self.groups[y]: return False

        gsmall, glarge = self.groups[x], self.groups[y]
        if self.sizes[self.groups[x]] > self.sizes[self.groups[y]]:
            gsmall, glarge = self.groups[y], self.groups[x]
        
        self.sizes[glarge] += self.sizes[gsmall]
        self.sizes[gsmall] = 0

        for index in range(len(self.groups)):

            if self.groups[index] == gsmall:
                self.groups[index] = glarge
        return True

    def isEquivalent(self, x, y):
        return (self.groups[x] == self.groups[y])

    # Calculate the cardinality of the set which x belongs to
    def getCardinality(self, x):
        return self.sizes[self.groups[x]]

    # def merge(self, x, y):
    


    # def isSingleton(self, x):

# if __name__ == '__main__':

        