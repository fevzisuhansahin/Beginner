# (a , b , c , d , e , a )
#  0 | 1 | 2 | 3 | 4 | 5  
#  0 |-6 |-5 |-4 |-3 |-2 

liste = ["a" , "b" , "c" , "d" , "e" , "a"]
print(liste)

tuple = ("a" , "b" , "c" , "d" , "e" , "a")  # list tipinin aksine tup tipinin elemanları değişmez
print(tuple)

liste[3] = "a"
print(liste)

"""tuple[3] = "a"  # bu dizin hata veriyor
print(tuple)"""

print(tuple.count("a"))
print(tuple.index("c"))