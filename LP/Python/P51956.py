def myLength(L):
	length = 0
	for i in L:
		length += 1
	return length
	
def myMaximum(L):
	max = L[0]
	for x in L:
		if x > max:
			max = x
	return max

def average(L):
	sum = 0
	for i in L:
		sum += i
	return sum/myLength(L)

def buildPalindrome(L):
	rev = list(reversed(L))
	return rev + L 

def remove(L1, L2):
	diff = []
	for element in L1:
		if element not in L2:
			diff.append(element)
	return diff

def flatten(L):
	if len(L) == 0:
		return []
	if isinstance(L[0], list):
		return flatten(L[0]) + flatten(L[1:])
	return L[:1] + flatten(L[1:])

def oddsNevens(L):
	odds = []
	evens = []
	for i in L:
		if i % 2 == 0:
			evens.append(i)
		else:
			odds.append(i)
			
	return (odds, evens)
	
	
def isPrime(x):

	if x < 2:
		return False
		
	for i in range(2, (x//2)+1):
		if (x%i) == 0:
			return False
			
	return True
	
def primeDivisors(n):
	return [x for x in range(1, n+1) if n % x == 0 and isPrime(x)] 