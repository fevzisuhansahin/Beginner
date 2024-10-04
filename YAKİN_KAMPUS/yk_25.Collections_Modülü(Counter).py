import random
from collections import Counter

liste1 = random.sample(range(10), k=4) # 4 tane liste oluştu
liste2 = random.sample(range(10), k=4)
liste3 = random.sample(range(10), k=4)
liste4 = random.sample(range(10), k=4)

listeler_listesi = [liste1,liste2,liste3,liste4] # listeleri öge alarak liste oluşturdu
listeler_toplam = liste1 + liste2 + liste3 + liste4 # listelerin ögelerini öge aarak liste oluşturdu

print(listeler_listesi)
print(listeler_toplam)

for index,oge in enumerate(listeler_listesi):
    print(f"{index+1}. liste: {oge}")
    
# Counter
    
print(Counter(listeler_toplam)) # Counter her ögeden ne kadar olduğunu sayar
print(Counter("kjgnbşofjgbojşi")) # string türü de harflerden oluşa liste gibi

sarki = """Yine bana gel
Yana yana yine beni sev
Yine bana gel
Yana yana yine beni sev"""

print(Counter(sarki)) # sarki string olduğu için harf harf sayıyor

print(Counter(sarki.split())) # burada da küçük ve büyük harf farkı oluyor

print(Counter(sarki.lower().split()))

# most_comman(): parantez içi kaç tane yaygın öge gösterileceğini belirtir

print(Counter(sarki.lower().split()).most_common(1))
