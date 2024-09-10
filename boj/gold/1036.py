n=int(input())
v,a={},[input() for _ in range(n)]
for s in a:
 for i,x in enumerate(s):
  v[x]=v.get(x,0)+36**(len(s)-i-1)*(35-int(x, 36))
for k in sorted(v,key=v.get,reverse=True)[:int(input())]:
 a=[x.replace(k, 'Z') for x in a]
ans=sum(int(s,36) for s in a)
r=[]
while ans:r.append('0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ'[ans%36]);ans//=36
print(''.join(r[::-1]) if r else '0')
