import unittest
from DisjointSetArray import DisjointSetArray
from DisjointSetForest import DisjointSetForest

class DisjointSetTestCase(unittest.TestCase):

    def setUp(self):
        # self.ds1 = DisjointSetArray(5)
        self.ds1 = DisjointSetForest(5)

    def testFind(self):
        for i in range(5):
            self.assertEqual(self.ds1.find(i), i)

    def testGetCardinality(self):
        expected = [1, 1, 1, 1, 1]
        for i in range(len(expected)):
            self.assertEqual(self.ds1.getCardinality(i), expected[i])

    def testMerge(self):
        self.assertFalse(self.ds1.find(2) == self.ds1.find(3))
        self.assertTrue(self.ds1.merge(2, 3))
        self.assertTrue(self.ds1.find(2) == self.ds1.find(3))
        self.assertFalse(self.ds1.merge(2, 3))
        exp_cardinality = [1, 1, 2, 2, 1]
        for i in range(len(exp_cardinality)):
            self.assertEqual(exp_cardinality[i], self.ds1.getCardinality(i))

    def testIsEquivalent(self):
        for i in range(1, 5):
            self.assertFalse(self.ds1.isEquivalent(i-1, i))
        self.assertTrue(self.ds1.merge(2, 3))
        self.assertTrue(self.ds1.isEquivalent(2, 3))


    # def tearDown(self):

if __name__ == '__main__':
    unittest.main()