import sys
si=sys.stdin.readline

def maskToAddr(v):
	v,ret=bin(v)[2:],''
	if len(v)<32:
		for _ in range(32-len(v)):v='0'+v
			
	for i in range(4):
		ret+=str(int('0b'+v[i*8:i*8+8],2))
		if i<3:ret+='.'
	return ret

n,ips,netMask,mask=int(si()),[],0,0

for i in range(n):
	temp=si()
	if temp[-1]=='\n':temp=temp[:-1]
	temp=temp.split('.')
	
	mask=0
	for j in range(4):mask|=int(temp[j])<<((4-j-1)*8)
	ips.append(mask)

flag=False
for i in range(32-1,-1,-1):
	for j in range(n):
		if not j:
			hold=ips[j]&(1<<i)
			continue
		if (ips[j]&(1<<i))!=hold:
			flag=True
			break
	if flag:break
	netMask|=(1<<i)

print(maskToAddr(netMask&mask))
print(maskToAddr(netMask))
