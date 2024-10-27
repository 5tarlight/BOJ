from collections import*;X,Y,N=map(int,input().split());p={(lambda:tuple(map(int,input().split())))()for _ in range(N)};q,v=deque([(0,0,0)]),{(0,0)}
while q:
 x,y,d=q.popleft()
 if(x,y)==(X,Y):print(d);break
 for dx,dy in[(0,1),(1,0),(0,-1),(-1,0)]:
  nx,ny=x+dx,y+dy
  if(nx,ny)not in v and(nx,ny)not in p:v.add((nx,ny));q.append((nx,ny,d+1))
