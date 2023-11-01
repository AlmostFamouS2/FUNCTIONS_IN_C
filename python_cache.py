from functools import lru_cache
import time
  
# Function that computes Fibonacci 
# numbers without lru_cache
def fib_without_cache(n):
    if n < 2:
        return n
    return fib_without_cache(n-1) + fib_without_cache(n-2)
      
# Execution start time
begin = time.time()
fib_without_cache(30)
  
# Execution end time
end = time.time()
  
print("Time taken to execute the\
function without lru_cache is", end-begin)
  
# Function that computes Fibonacci
# numbers with lru_cache
@lru_cache(maxsize = 128)
def fib_with_cache(n):
    if n < 2:
        return n
    return fib_with_cache(n-1) + fib_with_cache(n-2)
      
begin = time.time()
fib_with_cache(30)
end = time.time()
  
print("Time taken to execute the \
function with lru_cache is", end-begin)

Syntax:
  @lru_cache(maxsize=128, typed=False)

'''
Parameters:
maxsize:This parameter sets the size of the cache, the cache can store upto maxsize most recent function calls, if maxsize is set to None, the LRU feature will be disabled and the cache can grow without any limitations
typed:
If typed is set to True, function arguments of different types will be cached separately. For example, f(3) and f(3.0) will be treated as distinct calls with distinct results and they will be stored in two separate entries in the cache
'''
