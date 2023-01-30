#include <iostream>
#include <vector>
#include <queue>>

void checkGraph(int idx, std::vector<std::vector<int>>& rooms, std::vector<bool>& visited){
    visited[idx] = true;
    for(int i = 0; i < rooms[idx].size(); i++){
        if(visited[rooms[idx][i]])continue;
        checkGraph(rooms[idx][i], rooms, visited);
    }
}

bool canVisitAllRooms(std::vector<std::vector<int>>& rooms){
    int n = rooms.size();
    std::vector<bool> visited(n,false);
    checkGraph(0, rooms, visited);

    for(int i = 0;i < n;i++){
        if(!visited[i])return false;
    }
    return true;
}
