class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """

        r = []
        m = {}

        for i in range(len(s)):
            c= s[i]
            for j in range(i+1, len(s)):
                if c == s[j]:
                    if r and c in m  and c not in r:
                        r.append(c)
                    else:
                        m[c] = True
                    break

            else:
                if c not in r:r.append(c)

        
        return ''.join(r)

def assertR(s, r):
    rr = Solution().removeDuplicateLetters(s) 
    assert rr == r,(s,rr,r)


assertR("ccacbaba", "acb")
assertR("bbcaac", "bac")

assertR("bcabc", "abc")
assertR("cbacdcbc", "acdb")
