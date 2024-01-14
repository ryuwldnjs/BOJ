import sys
sys.setrecursionlimit(200000)
input= sys.stdin.readline

dist = []

def dfs(start,target):
    visited[start] = True

    if start == target :
        print(sum(dist) - max(dist))
        return

    for next,cost in graph[start]:
        if not visited[next]:
            dist.append(cost)
            dfs(next,target)
            dist.pop()


N,S,E = map(int,input().split())

graph=[[] for i in range(N+1)]

for i in range(N-1):
    s,e,cost =map(int,input().split())
    graph[s].append((e,cost))
    graph[e].append((s,cost))

if S == E :
    print(0)
    exit(0)

visited=[False] * (N+1)
dfs(S,E)




