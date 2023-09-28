class Solution(object):
    def isPalindrome(self, x):
        result = True
        strx = str(x)
        rstrx = strx[::-1]
        lenx = int(len(strx)/2)
        for i in range(lenx):
            if strx[i]!=rstrx[i]:
                result = False
        return result  

print(Solution().isPalindrome(1331))