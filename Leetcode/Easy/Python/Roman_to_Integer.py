class Solution(object):
    def romanToInt(self, s):
        revs = s[::-1]
        result = 0
        n=0
        j=0

        i=revs[::-1]

        while i=="I" and n<3:
            i=revs[::-n-1]
            n=n+1
            result=result+1
            print(result)
        """for i in s[::-1]:
            j=j+1
            if i=="I" and n<3:
                result+=1
                n=n+1
            elif i=="V" and i!=0:
                if revs[0]=="I":
                
                    print("biim baim aba")
        """
            
        
Solution().romanToInt("I")
Solution().romanToInt("II")
Solution().romanToInt("III")
print("\n")
Solution().romanToInt("IV")
"""
Solution().romanToInt("V")
Solution().romanToInt("VI")

Solution().romanToInt("VII")
Solution().romanToInt("VIII")
Solution().romanToInt("IX")
Solution().romanToInt("X")
print("\n")
"""
Solution().romanToInt("XI")
Solution().romanToInt("XII")
Solution().romanToInt("XIII")
print("\n")
Solution().romanToInt("XIV")
Solution().romanToInt("XV")

Solution().romanToInt("XVI")
