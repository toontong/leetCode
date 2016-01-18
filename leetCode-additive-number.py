class Solution(object):
    def isAdditiveNumber(self,num):
        '''a = s[:i]
            b = s[i+1:n=(for n=1;n+i+1<length;++n)]
                c = s[n:m=(for m=1;m+n+1<length;++m)]
        '''
        def f(s,l):
            length = len(s)
            for i in range(l, length-1):
                a = s[:i]
                if i>1 and a[0]=='0':break

                for j in range(i+1, length):
                    b = s[i:j]
                    if len(b)>1 and b[0]=='0':break

                    for h in range(j+1, length+1):
                        c = s[j:h]
                        if len(c) >1 and c[0]=='0':break

                        eq = cmp(int(a)+int(b), int(c))
                        if eq==-1:
                            break
                        if eq == 0:
                            if f(s[i:], len(b)):
                                return True
                            if h==length:
                                return True

            return False
        return f(num, 1)


def isAdditiveNumber(num, yes):
    assert Solution().isAdditiveNumber(num) is yes, num

isAdditiveNumber("101020305080130210", True)
isAdditiveNumber("011235", True)
isAdditiveNumber("12012122436", True)
isAdditiveNumber("120122436", False)
isAdditiveNumber("0235813", False)
isAdditiveNumber("1203", False)
isAdditiveNumber("10112", True)
isAdditiveNumber("1023", False)
isAdditiveNumber("111", False)
isAdditiveNumber("112358", True)
isAdditiveNumber("199100199", True)

