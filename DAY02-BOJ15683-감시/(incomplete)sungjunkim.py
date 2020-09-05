myList = originalList #input

total = N * M
camera1area = -1
camera2area = -1
camera3area = -1
camera4area = -1
camera5area = -1

for i in range(0, M): # running base on original list's rows
    for j in range(0,N): # running base on original list's cols
        l = j    # leftwork to do whenever list iterates
        r = N - j # right
        u = i     # up
        d = M - i # down
        if myList[i][j] == 1: #when it meets 1
            newtotal = total
            newList = []
            # calculate how much area it will take care of for each directions
            # and save it to the corresponding variable
            # also make a list which Work functions modified
            area_left, currentList_1 = leftWork(i, l, myList)
            area_right, currentList_2 = rightWork(i, r, myList)
            area_up, currentList_3 = upWork(i, u, myList)
            area_down, currentList_4 = downWork(i, d, myList)
            # get the maximum of them
            cameara1area = max(area_left, area_right, area_up, area_down)
            
            # newlist will be determined by the maximum area consumed.
            if area_left == camera1area:
                newList = currentList_1
            elif area_right = camera1area:
                newList = currentList_2
            elif area_up = camera1area:
                newList = currentList_3
            elif area_down = camera1area:
                newList = currentList_4
            #whenever there is a # in newList and there is 0 in myList
            #change myList's elements to the '#'
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList[i][j]
                        myList[i][j] = '#'
            
            
        elif myList[i][j] == 2:
            newtotal = total
            newList1 = []
            newList2 = []
            area_left, currentList1 = leftWork(i, l, myList)
            area_right, currentList2 = rightWork(i, r, myList)
            area_up, currentList3 = upWork(i, u, newtotal)
            area_down, currentList4 = downWork(i, d, newtotal)
            
            camera2area = max(area_left+area_right, area_up+area_down)
            # here we need to follow two newList therefore two if statements
            if area_left + area_right == camera2area:
                newList1 = currentList1
                newList2 = currentList2
            else:
                newList1 = currentList3
                newList2 = currentList4

            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList1[i][j]
                        myList[i][j] = '#'
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList2[i][j]
                        myList[i][j] = '#'
            
            
        elif myList[i][j] == 3
            newtotal = total
            newList1 = []
            newList2 = []
            area_left, currentList1 = leftWork(i, l, myList)
            area_right, currentList2 = rightWork(i, r, myList)
            area_up, currentList3 = upWork(i, u, myList)
            area_down, currentList4 = downWork(i, d, myList)
            
            camera3area = max(area_up + area_right, area_right + area_down,
                              area_down + area_left, area_left + area_up)
            
            if area_up + area_right == camera3area:
                newList1 = currentList3
                newList2 = currentList2
            elif area_right + area_down:
                newList1 = currentList2
                newList2 = currentList4
            elif area_down + area_left:
                newList1 = currentList4
                newList2 = currentList1
            elif area_left + area_up:
                newList1 = currentList1
                newList2 = currentList3
            
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList1[i][j]
                        myList[i][j] = '#'
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList2[i][j]
                        myList[i][j] = '#'
                        
       elif myList[i][j] == 4
            newtotal = total
            newList1 = []
            newList2 = []
            newList3 = []
            area_left, currentList1 = leftWork(i, l, myList)
            area_right, currentList2 = rightWork(i, r, myList)
            area_up, currentList3 = upWork(i, u, myList)
            area_down, currentList4 = downWork(i, d, myList)
            
            camera4area = max(area_left + area_up + area_right,
                              area_left + area_down + area_right)
            
            if area_left + area_up + area_right == camera2area:
                newList1 = currentList1
                newList2 = currentList3
                newList3 = currentList2
            else:
                newList1 = currentList1
                newList2 = currentList4
                newList3 = currentList2

            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList1[i][j]
                        myList[i][j] = '#'
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList2[i][j]
                        myList[i][j] = '#'
             for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != newList3[i][j]
                        myList[i][j] = '#'
            
        elif myList[i][j] == 5
            newtotal = total
            area_left, currentList1 = leftWork(i, l, newtotal)
            area_right, currentList2 = rightWork(i, r, newtotal)
            area_up, currentList3 = upWork(i, u, newtotal)
            area_down, currentList4 = downWork(i, d, newtotal)
        
            camera5area = area_left + area_right + area_up + area_down
            #here we only need to follow 1 list therefore whenever there is difference between
            # mylist and any othere list change the elements in the mylist to the elements in currentList
            for i in range(0, M):
                for j in range(0,N):
                    if myList[i][j] != currentList1[i][j] or
                         myList[i][j] != currentList2[i][j] or
                           myList[i][j] != currentList3[i][j] or
                             myList[i][j] != currentList4[i][j]
                        myList[i][j] = '#'

                        
    # so each if statements will take the maximum area of each camera can consume.
    # also whenever the function is called, the modified list will be the mylist
    # therefore, when i = M-1 and j = N-1 cameraXarea will have maximum area each camera consumes
    # So total - sum of cameraXarea will be the minimnum.
    return total - camera1area - camera2area - camera3area - camera4area- camera5area
# worked: number of indices that has been changed 0 to #
# newList: the list that is modified
# while iterating only left side until the column ends, 
# whenever it meets the 0 change it to # and increment worked by 1
# when it meets 6 just break out of the for loop and return worked and modified list
def leftWork(self, row, worktodo, newList):
    worked = 0
    for x in range(worktodo, 0):
        if newList[row][x] == 0:
            newList[row][x] = '#'
            worked = worked + 1
        elif newList[row][x] == 6
            break

    return worked, newList

# worked: number of indices that has been changed 0 to #
# newList: the list that is modified
# while iterating only right side until the column ends, 
# whenever it meets the 0 change it to # and increment worked by 1
# when it meets 6 just break out of the for loop and return worked and modified list
def rightWork(self, row, worktodo, newList):
    worked = 0
    for x in range(worktodo, 0):
        if newList[row][x] == 0:
            newList[row][x] = '#'
            worked = worked + 1
        elif newList[row][x] == 6
            break

    return worked, newList

# worked: number of indices that has been changed 0 to #
# newList: the list that is modified
# while iterating only down side until the column ends, 
# whenever it meets the 0 change it to # and increment worked by 1
# when it meets 6 just break out of the for loop and return worked and modified list
def downWork(self, col, worktodo, newList):
    worked = 0
    for x in range(worktodo, 0):
        if newList[x][col] == 0:
            newList[x][col] = '#'
            worked = worked + 1
        elif newList[x][col] == 6
            break

    return worked, newList

# worked: number of indices that has been changed 0 to #
# newList: the list that is modified
# while iterating only up side until the column ends, 
# whenever it meets the 0 change it to # and increment worked by 1
# when it meets 6 just break out of the for loop and return worked and modified list
def upWork(self, row, worktodo, newList):
    worked = 0
    for x in range(worktodo, 0):
        if newList[x][col] == 0:
            newList[x][col] = '#'
            worked = worked + 1
        elif newList[x][col] == 6
            break

    return worked, newList
