import time, sys

def Move(cell, N) :
    if N != 0 :
        tmp = cell[N]
        cell[N] = cell[0]
        cell[0] = tmp
    
def Add_boxes(grid, cell, statement, R, C, count) :
    while True :
        N = 0
        if cell[0][0] == -1 : break
        Current_cell = cell[0]
        h, x, y = Current_cell[0], Current_cell[1][0], Current_cell[1][1]
        if N == 0 :
            i = 1
            while cell[i][0] == cell[0][0] : i += 1
            N = i
        if statement[x][y] == 2 : 
            del cell[0]
            N -= 1
            continue
        
        del cell[0]
        N -= 1
        
        if x != 0 : 
            if statement[x-1][y] == 0 :
                if grid[x-1][y] < h - 1 :
                    count += h - 1 - grid[x-1][y]
                    grid[x-1][y] = h - 1
                    statement[x-1][y] = 1
                    cell = [(h-1, (x-1, y))] + cell
                    Move(cell, N)
                    
        if x != R-1 : 
            if statement[x+1][y] == 0 :
                if grid[x+1][y] < h - 1 :
                    count += h - 1 - grid[x+1][y]
                    grid[x+1][y] = h - 1
                    statement[x+1][y] = 1
                    cell = [(h-1, (x+1, y))] + cell
                    Move(cell, N)
                    
        if y != 0 : 
            if statement[x][y-1] == 0 :
                if grid[x][y-1] < h - 1 :
                    count += h - 1 - grid[x][y-1]
                    grid[x][y-1] = h - 1
                    statement[x][y-1] = 1
                    cell = [(h-1, (x, y-1))] + cell
                    Move(cell, N)
                    
        if y != C-1 : 
            if statement[x][y+1] == 0 :
                if grid[x][y+1] < h - 1 :
                    count += h - 1 - grid[x][y+1]
                    grid[x][y+1] = h - 1
                    statement[x][y+1] = 1
                    cell = [(h-1, (x, y+1))] + cell
                    Move(cell, N)
        
        statement[x][y] = 2
    return count

T = int(input())
Case = []

for t in range(T) :    
    count, grid, cell, statement = 0, [], [], []
    R, C = map(int, sys.stdin.readline().rstrip().split())
    
    for r in range(R) :
        Row = list(map(int, sys.stdin.readline().rstrip().split()))
        grid.append(Row)
        S_Row = []
        for c in range(C) : S_Row.append(0)
        statement.append(S_Row)
        ## statement 0 : not yet checked
        ## statement 1 : not yet checked but changed by adjacent cell
        ## statement 2 : checked
        for c in range(C) : cell.append((Row[c], (r, c)))
    
    cell.sort(reverse=True)
    cell.append((-1, (-1, -1)))
    
    count = Add_boxes(grid, cell, statement, R, C, count)    

    Case.append(count)
        
for t in range(0, T) :
    print("Case #%d: %d" % (t+1, Case[t]))