import sys
si=sys.stdin.readline

n,m=[int(e) for e in si().split()]
fam,blood=dict(),dict()
king=si()[:-1]

def process(name,pt):
	global fam,blood
	if name not in blood:
		blood[name]=0
	blood[name]+=pt
	for child in fam[name]:
		process(child,pt/2)

def find(name):
	if name not in blood:return 0
	return blood[name]
	
for _ in range(n):
	a,b,c=[e for e in si().split()]
	if a not in fam:
		fam[a]=[]
	if b not in fam:
		fam[b]=[]
	if c not in fam:
		fam[c]=[]
	
	fam[b].append(a)
	fam[c].append(a)

process(king,1)

ans=0
for _ in range(m):
	a=si()
	if a[-1]=='\n':
		a=a[:-1]
	if find(ans)<find(a):
		ans=a

print(ans)
	
	
