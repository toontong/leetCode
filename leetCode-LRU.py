class LRUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.cap = capacity
        self.items={}
        self.sort_keys=[]

    def get(self, key):
        """
        :rtype: int
        """
        if self.items.has_key(key):
            self.move2front(key)
        return self.items.get(key, -1)

    def move2front(self, k):
        l = self.sort_keys
        if l[0] == k:return
        l.pop(l.index(k))
        l.insert(0,k)

    def set(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: nothing
        """
        if self.items.has_key(key):
            self.items[key]=value
            self.move2front(key)
            # print 'change k=',key, "value=",value
            return
        else:
            self.sort_keys.insert(0, key)
            self.items[key]=value

        if len(self.sort_keys)>self.cap:
            k = self.sort_keys.pop(-1)
            assert self.items.has_key(k),k
            self.items.pop(k)
            # print 'pop key=%s, cap=%d' %(k, self.cap)


l=LRUCache(1)
l.set(2,1)
assert 1==l.get(2)
l.set(3,2)
assert -1==l.get(2),l.get(2)
assert 2==l.get(3)


cap=10
lru = LRUCache(cap)
for i in range(cap):
    lru.set(i,i)

assert lru.get(11)==-1
lru.set(12,12)
assert lru.get(10)==-1
assert lru.get(12)==12

