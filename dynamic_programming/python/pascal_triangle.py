class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        list = []
        list.append([1])
        for i in range(1,numRows):
            temp = []
            size = len(list[len(list)-1])
            temp.append(1)
            if size>1:
                for j in range(size-1):
                    temp.append(list[size-1][j]+list[size-1][j+1])
            temp.append(1)
            list.append(temp)
        return list

