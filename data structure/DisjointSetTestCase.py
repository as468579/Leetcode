import unittest
from DisjointSetArray import DisjointSetArray

class DisjointSetTestCase(unittest.TestCase):

    # def setUp(self):
    # def tearDown(self):
    def test_isEquivalent(self):
        ds1 = DisjointSetArray(range(5))
        ds2 = DisjointSetArray(range(5))
        res = ds1.isEquivalent(ds2)
        self.assertTrue(res)

if __name__ == '__main__':
    unittest.main()