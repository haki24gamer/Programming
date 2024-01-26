/*
 * @lc app=leetcode id=13 lang=c
 *
 * [13] Roman to Integer
 */

// @lc code=start
int romanToInt(char* s) {
    int res=0;
    int i=0;
    int mult=1;
    while (s[i]!="\0")
    {
        while (s[i]=='I')
        {
            res=res+mult*1;
        }
        
        mult=mult*10;
        i++;
    }
    
    
    return res;
}
// @lc code=end

