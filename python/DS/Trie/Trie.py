class TrieNode:
    def __init__(self):
        self.next = [None] * 26
        self.isWord = False
        
class Trie(object):

    def __init__(self):
        self.__root = TrieNode()
        
    def __convert_index(self, c):
        """
        :type c: char
        :rtype: int
        """
        return ord(c) - ord('a')
    
    def __traverse(self, word):
        """
        :type word: str
        :rtype: TrieNode (or None)
        """
        curr = self.__root
        for char in word:
            index = self.__convert_index(char)
            if(not curr.next[index]):
                return None
            curr = curr.next[index]
        return curr    

    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        curr = self.__root
        for char in word:
            index = self.__convert_index(char)
            if(not curr.next[index]):
                curr.next[index] = TrieNode()
            curr = curr.next[index]
        curr.isWord = True
        

    def search(self, word):
        """
        :type word: str
        :rtype: boolean
        """
        curr = self.__traverse(word)
        if(curr and curr.isWord):
            return True
        return False
        

    def startsWith(self, word):
        """
        :type word: str
        :rtype: boolean
        """
        curr = self.__traverse(word)
        if curr:
            return True
        return False
        
