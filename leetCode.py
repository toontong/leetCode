class Solution(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        FIND = -10
        GUESS=-100

        secret, guess = [int(c) for c in secret], [int(c) for c in guess]
        a,b = 0, 0
        remain = {}
        unguess={}
        for i, c in enumerate(guess):
            s =  secret[i]
            if c == s: 
               a += 1
            else:
                remain[s]=remain.setdefault(s, 0) + 1
                unguess[s]=unguess.setdefault(s, 0) + 1
                # unguess.append(c)
        for i, c in unguess.iteritems():
            if remain.has_key(i):
                b+=remain.get(i,0)+c
            # if remain.get(c)>0:
            #     b += 1
            #     remain[c] -= 1
        return "%dA%dB" %(a, b)
            # for j,s in enumerate(secret):
            #     if s == FIND: 
            #         continue
            #     elif c == s:
            #         if i<j: 
            #             secret[j]=FIND
            #             # secret.remove(s)
            #         b+=1
            #         break

        return "%dA%dB" %(a, b)

    def getHint2(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        FIND = -10
        GUESS=-100

        # secret, guess = [c for c in secret], [c for c in guess]
        a,b = 0, 0
        remain = {}
        unguess=[]
        for i, c in enumerate(guess):
            s =  secret[i]
            if c == s: 
               a += 1
            else:
                remain[s]=remain.setdefault(s, 0) + 1
                unguess.append(c)
        for c in unguess:
            if remain.get(c)>0:
                b += 1
                remain[c] -= 1
        return "%dA%dB" %(a, b)

def assertT(s,g, r):
    o = Solution().getHint2(s,g) 
    assert o == r,(s,g,o,r)
assertT("1122","1222","3A0B")
assertT("011","110","1A2B")
assertT("2822013305","5706322849", "0A6B") 
assertT("1122","2211", "0A4B") 
assertT("11","10", "1A0B")
assertT("1807","7810" , "1A3B")
assertT("1234","0111" , "0A1B")
