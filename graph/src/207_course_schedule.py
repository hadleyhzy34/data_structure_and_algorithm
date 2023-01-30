
def checkCycle(curCourses, adj, visited):
    if visited[curCourses] == 1:
        return True
    
    if visited[curCourses] == 0:
        visited[curCourses] = 1
        for a in adj[curCourses]:
            if checkCycle(a, adj, visited):
                return True;

    visited[curCourses] = 2
    return False

def canFinish(numCourses: int, prerequisites) -> bool:
    adj = [[] for _ in range(numCourses)]
    for i in range(len(prerequisites)):
        adj[prerequisites[i][0]].append(prerequisites[i][1])
    
    visited = [0 for _ in range(numCourses)]
    for i in range(numCourses):
        if checkCycle(i, adj, visited):
            return False

    return True
