class Solution(object):
    
    def __init__(self):
        self.visited = set()
        self.success = False
        
    def dfs(self, arr, node):
        if node in self.visited: return
        if arr[node] == 0:  self.success = True
        if self.success: return     
        
        self.visited.add(node)
        left = node - arr[node]
        right = node + arr[node]
        if (left >= 0):
            self.dfs(arr, left)
        if (right < len(arr)):
            self.dfs(arr, right)
        
    def canReach(self, arr, start):
        """
        :type arr: List[int]
        :type start: int
        :rtype: bool
        """
        
        self.dfs(arr, start)
        return self.success
        
        