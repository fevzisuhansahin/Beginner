import random

class Field:
    def __init__(self):
        self.minefield = [[0 for _ in range(16)] for _ in range(16)]
        self.current_minefield = [[" #" for _ in range(16)] for _ in range(16)]
        
        for i in range(16):
            self.minefield[0][i] = i
            self.minefield[i][0] = i
            self.current_minefield[0][i] = i
            self.current_minefield[i][0] = i

    def level(self):
        print("""
1 - Hard (40 mines)
2 - Normal (30 mines)
3 - Easy (20 mines)
              """)
        decision = int(input("Please select level: "))
        if decision==1:
            maximum = 40
        elif decision==2:
            maximum = 30
        elif decision==3:
            maximum = 20

        count = 0
        while count < maximum:
            row = random.randint(1, 15)
            col = random.randint(1, 15)
            if self.minefield[row][col] == 0:
                self.minefield[row][col] = 1
                count += 1


    def display_current_field(self):
        for row in range(16):
            for col in range(16):
                print(f"{(self.current_minefield[row][col]):2}", end=" ")
            print()
    
    def display_field(self):
        for row in range(16):
            for col in range(16):
                print(f"{(self.minefield[row][col]):2}", end=" ")
            print()

    def get_input(self):
        print("\nMake a choice.")
        self.row = int(input("Enter the row: "))
        self.col = int(input("Enter the col: "))

    def check_bomb(self, x, y):
        if self.minefield[x][y]:
            print("\n               !!! GAME OVER !!!\n")
            self.display_field()
            exit()
        else:
            self.clear_boxes(x, y)
    
    def count_mines(self, x, y):
        count = 0
        for row in range(x - 1, x + 2):
            for col in range(y - 1, y + 2):
                if 1 <= row < 16 and 1 <= col < 16 and self.minefield[row][col]:
                    count += 1
        return count

    def clear_boxes(self, r, c, visited=None):
        if visited is None:
            visited = set()
        
        if (r, c) in visited or not (1 <= r < 16 and 1 <= c < 16):
            return
        
        visited.add((r, c))
        count = self.count_mines(r, c)
        
        if count == 0:
            self.current_minefield[r][c] = "  "
            self.clear_boxes(r - 1, c, visited)  # up
            self.clear_boxes(r + 1, c, visited)  # down
            self.clear_boxes(r, c - 1, visited)  # left
            self.clear_boxes(r, c + 1, visited)  # right
        else:
            self.current_minefield[r][c] = count
            

class Minefield:
    def __init__(self):
        self.field = Field()

    def game(self):
        print("\n                   MINESFIELD\n")
        self.field.level()
        while True:
            self.field.display_current_field()
            self.field.get_input()
            self.field.check_bomb(self.field.row, self.field.col)


minefield = Minefield()
minefield.game()