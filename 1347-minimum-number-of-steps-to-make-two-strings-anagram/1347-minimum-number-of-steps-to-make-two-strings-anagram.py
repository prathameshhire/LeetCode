class Solution:
    def minSteps(self, s: str, t: str) -> int:
        f={}
        for char in s:
            if char in f:
                f[char]+=1
            else:
                f[char]=1
        for char in t:
            if char in f:
                f[char]-=1
            else:
                f[char]=-1
        change = 0
        for cnt in f.values():
            change += abs(cnt)
        return change//2