import random

def create_matrix(size):
    return [[0 for _ in range(int(size))] for _ in range(int(size))]
def cut_to_2x2_matrix(matrix):
    size = len(matrix)
    new_matrix = create_matrix(size//2)
    add = 0
    for i in range(0,size,2):
        for j in range(0,size,2):
            add += matrix[i][j] + matrix[i+1][j+1]
            new_matrix[i//2][j//2] = matrix[i][j] + matrix[i+1][j+1]
    return new_matrix,add

def rotate_90_degrees(matrix):
    size = len(matrix)
    new_matrix = create_matrix(size)
    for i in range(size):
        for j in range(size):
            new_matrix[(size-1)-j][i] = matrix[i][j]
    return new_matrix
            
def print_matrix(matrix):
    for row in matrix:
        for element in row:
            print(f"{element:2}", end=" ")
        print()
            
def game(matrix16):
    matrix8 = create_matrix(8)
    matrix8rotated = create_matrix(8)
    matrix4 = create_matrix(4)
    matrix4rotated = create_matrix(4)
    matrix2 = create_matrix(2)

    total = 0

    # 16x16 Matrix
    print("\nMATRİX 16x16")
    print_matrix(matrix16)
    # 16x16 to 8x8 Matrix
    matrix8, add = cut_to_2x2_matrix(matrix16)
    total += add
    print("\nMATRİX 8x8")
    print_matrix(matrix8)
    # Rotate 8x8 Matrix
    matrix8rotated = rotate_90_degrees(matrix8)
    print("\nMATRİX 8x8(ROTATED)")
    print_matrix(matrix8rotated)
    # 8x8 to 4x4 Matrix
    matrix4, add = cut_to_2x2_matrix(matrix8rotated)
    total += add
    print("\nMATRİX 4x4")
    print_matrix(matrix4)
    # Rotate 4x4 Matrix
    matrix4rotated = rotate_90_degrees(matrix4)
    print("\nMATRİX 4x4(ROTATED)")
    print_matrix(matrix4rotated)
    # 4x4 to 2x2
    matrix2, add = cut_to_2x2_matrix(matrix4rotated)
    total += add
    print("\nMATRİX 2x2")
    print_matrix(matrix2)
    return matrix2,total
    
matrix16 = [[random.randint(1,10) for _ in range(16)]for _ in range(16)]
matrix2,total = game(matrix16)
diagonal = matrix2[0][0] + matrix2[1][1]
anti_diagonal = matrix2[0][1] + matrix2[1][0]

mustafa = total*anti_diagonal
emir_can = total*diagonal
print(f"\nMustafa: {mustafa}\nEmir Can: {emir_can}\n")

if mustafa < emir_can:
    print("Winner is EMIR CAN")
elif mustafa == emir_can:
    print("Draw")
else:
    print("Winner is MUSTAFA")