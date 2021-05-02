class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        def count(s: str) -> int:
        	return sum(c in 'aeiouAEIOU' for c in s)
        n = len(s)
        return count(s[:n//2]) == count(s[n//2:])