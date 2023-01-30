
def checkCycle(idx, n, isConnected, visited):
    visited[idx] = 1
    for i in range(n):
        if(visited[i] or not(isConnected[idx][i])):
            continue
        checkCycle(i, n, isConnected, visited)

def findCircleNum(isConnected):
    res = 0
    numCities = len(isConnected)
    visited = [0] * numCities
    for i in range(numCities):
        if visited[i]:
            continue
        checkCycle(i, numCities, isConnected, visited)
        res += 1
    
    return res
