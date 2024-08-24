import random

print(random.random()) # bu komut (0,1) arasında random sayı seçer
print(random.uniform(1,101)) # bu komut belirlenen aralıkta random sayı seçer
print(random.randint(1,101)) # bu komut belirlenen aralıkta random tam sayı seçer

print(random.choice(range(101))) # choice komutu liste benzeri tiplerde random öge seçer
print(random.choice(["a" , "b" , "c" , "d" , "e"]))

print(random.sample(range(101) , k=5)) # bu komuta kaç kere random seçeceğini k ile belirtiriz
print(random.sample(["a" , "b" , "c" , "d" , "e"] , k=2))

liste = [*range(10)]
print(liste)
random.shuffle(liste) # bu komut listeyi rastgele karıştırır
print(liste)

import math

print(math.ceil(7.1)) # bu komut ondalık sayıyı sonraki tam sayıya yuvarlar
print(math.floor(7.9)) # bu komut ondalık sayıyı bir önceki tam sayıya yuvarlar
print(math.factorial(5))
print(math.pow(3,2)) # 3'ün 2. kuvvetini alır