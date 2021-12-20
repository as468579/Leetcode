class Solution(object):
    def decodeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        if  not "[" in s:
            return  s
        
        times = 0
        start = 0
        queue = []
        ret = ""
        for idx, char in enumerate(s):
            if ord(char)>=ord("0") and ord(char) <= ord("9"):
                if not queue:
                    times = times*10 + int(char)
            elif char == "[":
                if not queue:
                    start = idx+1    
                queue.append("[")
            elif char == "]":
                queue.pop()
                if not queue:
                    tmp = self.decodeString(s[start:idx])
                    print(tmp)
                    for i in range(times):
                        ret += tmp
                    times = 0
            else:
                if not queue:
                    ret += char
        return ret