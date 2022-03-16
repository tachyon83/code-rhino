def toBase(n, b):
	if n < b:
		return [n]
	return toBase(int(n/b), b) + [n%b]

def IsPal(n):
	return n == n[::-1]
	
def GetCands(n):
	res = set()
	i = 1
	while i * i <= n:
		if n % i == 0:
			res.add(i-1)
			res.add(int(n/i)-1)
		res.add(i)
		i += 1
	return res

n = int(input())

for x in sorted(GetCands(n)):
	if x > 1:
		if IsPal(toBase(n,x)):
			print (x)
