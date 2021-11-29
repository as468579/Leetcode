
class DisjointSetArray:
    def __init__(self, arr):
        self.groups = list(arr)

    def isEquivalent(self, ds2):
        for (g1, g2) in zip(self.groups, ds2.groups):
            if (g1 != g2):
                return False
        return True

    def find(self, x):
        
    # def merge(self, x, y):
    
    # def getCardinality(self, x):

    # def isSingleton(self, x):

# if __name__ == '__main__':

        