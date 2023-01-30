#include <stdlib.h>

void checkGraph(int idx, int** rooms, int* roomsColSize, int* visited){
    visited[idx] = 1;
    for(int i = 0; i < roomsColSize[idx]; i++){
        if(visited[rooms[idx][i]])continue;
        checkGraph(rooms[idx][i], rooms, roomsColSize, visited);
    }
}

int canVisitAllRooms(int** rooms, int roomsSize, int* roomsColSize){
    int* visited = (int*)calloc(roomsSize,sizeof(int));

    checkGraph(0, rooms, roomsColSize, visited);

    for(int i = 0;i < roomsSize;i++){
        if(!visited[i])return 0;
    }
    return 1;
}
