import unittest
from DisjointSetArray import DisjointSetArray

class DisjointSetTestCase(unittest.TestCase):

    # def setUp(self):

    # def tearDown(self):
    def testIsEquivalent(self):
        ds1 = DisjointSetArray(range(5))
        ds2 = DisjointSetArray(range(5))
        res = ds1.isEquivalent(ds2)
        self.assertTrue(res)

    def testFind(self):
        ds1 = DisjointSetArray(range(5))
        for i in range(5):
            self.assertEqual(ds1.find(i), i)

    def testMerge(self):
        ds1 = DisjointSetArray([0, 0, 2 ,2, 4, 5, 2, 4, 2, 2])
        ds2 = DisjointSetArray([0, 0, 2 ,2, 4, 5, 2, 4, 2, 2])

        ds1.merge(2, 3)
        self.assertTrue(ds1.isEquivalent(ds2))
        expected_cardinality = [2, 2, 5, 5, 2, 1, 5, 2, 5, 5]
        for i in range(len(expected_cardinality)):
            self.assertEqual(expected_cardinality[i], ds1.getCardinality(i))

        ds3 = DisjointSetArray([0, 0, 2, 2, 2, 5, 2, 2, 2, 2])
        ds1.merge(3, 7)
        self.assertTrue(ds1.isEquivalent(ds3))
        

    def testGetCardinality(self):
        arr      = [0, 0, 2 ,2, 4, 5, 2, 4, 2, 2]
        expected = [2, 2, 5, 5, 2, 1, 5, 2, 5, 5]
        ds = DisjointSetArray(arr)
        for i in range(len(arr)):
            self.assertEqual(ds.getCardinality(i), expected[i])


if __name__ == '__main__':
    unittest.main()