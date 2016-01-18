class Solution(object):
    def canWinNim(self, n):
        """
        :type n: int
        :rtype: bool
        """
        return bool(n &3 )


def assertT(n):
    return Solution().canWinNim(n)


for i in range(1,3):
    assert assertT(i), True

assert assertT(4) == False
assert assertT(5) == True
assert assertT(6) == True
assert assertT(7) == True
assert assertT(8) == False
assert assertT(9) ==True
assert assertT(10)== True