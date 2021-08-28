import sys
input=sys.stdin.readline

n=int(input())

def ipToBin(ip):
    a=list(map(int,ip.split('.')))
    temp=(a[0]<<24)+(a[1]<<16)+(a[2]<<8)+a[3]
    return temp

def binToIp(binary):
    temp=2**8-1
    result=""
    for i in range(4):
        a=binary&(temp<<(8*(3-i)))
        a=a>>(8*(3-i))
        result+=str(a)+"."
    return result[:-1]

ips=[ipToBin(input()) for _ in range(n)]
binary=(1<<32)-1
for ip in ips:
    binary&=ip
address=binToIp(binary)
print(address)

i=0
while ((1<<i)&binary)==0:
    i+=1
    if i==32:
        i=1
        break
mask=(1<<32)-(1<<(i-1))
print(binToIp(mask))

#실패
