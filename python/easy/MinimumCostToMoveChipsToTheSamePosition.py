class Solution(object):
    def minCostToMoveChips(self, position):
        """
        :type position: List[int]
        :rtype: int
        """
        
        odd_count = 0
        for p in position:
            if (p&1): odd_count += 1           

        return min((len(position) - odd_count), odd_count)