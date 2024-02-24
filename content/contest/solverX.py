from sys import setrecursionlimit
import threading # kaizo
setrecursionlimit(10**6+100)
threading.stack_size(10**6)
t=threading.Thread(target=solve)
t.start()
t.join()