import sys

words,t=dict(),0
for ln in sys.stdin:
	ln=ln.rstrip()
	if ln not in words:
		words[ln]=0
	words[ln]+=1
	t+=1

sortedKeys=sorted(words.keys())
for key in sortedKeys:
	print("%s %0.4f" % (key,words[key]/t*100))
	
