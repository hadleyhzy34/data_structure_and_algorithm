class Solution:
    def checkGraph(self,idx, rooms, visited):
        visited[idx] = 1
        for i in range(len(rooms[idx])):
            if visited[rooms[idx][i]]:
                continue
            self.checkGraph(rooms[idx][i], rooms, visited)

    def canVisitAllRooms(self, rooms):
        n = len(rooms)
        visited = [0] * n

        self.checkGraph(0, rooms, visited)
        
        for i in range(n):
            if not(visited[i]):return False;

        return True
