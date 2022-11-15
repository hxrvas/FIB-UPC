def absValue(x):
	if x < 0:
		return -x
	else: 
		return x
	
def power(x,p):
	return x**p

def isPrime(x):

	if x < 2:
		return False
		
	for i in range(2, (x//2)+1):
		if (x%i) == 0:
			return False
			
	return True

def slowFib(n):
	if n == 0:
		return 0
	if n == 1:
		return 1
	return slowFib(n-1)+slowFib(n-2)
	