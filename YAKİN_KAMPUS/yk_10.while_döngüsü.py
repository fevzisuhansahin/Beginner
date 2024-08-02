# While Faktöriyel

print("FAKTÖRİYEL HESAPLAMA")
sonuç = 1
x = int(input("Sayı giriniz: "))
azalan = x

while azalan > 0:
    sonuç = sonuç * azalan
    azalan -= 1
print(f"{x}! = {sonuç}")

# For Faktöriyel
"""
print("FAKTÖRİYEL HESAPLAMA")
a = int(input("sayı giriniz: "))
sonuc = 1

for sayı in range(a+1):
    if sayı > 0:
        sonuc = sayı * sonuc
        
print(f"{a}! = {sonuc}")

--------------------------------

print("FAKTÖRİYEL HESAPLAMA")
a = int(input("sayı giriniz: "))
sonuc = 1

for sayı in range(1 , a+1):
    sonuc = sayı * sonuc
        
print(f"{a}! = {sonuc}")
"""

# while asal sayı sorgulayıcı

print("Asal sayı sorgulayıcı")
deger = int(input("Sayı girin"))
x = deger - 1
while x > 1:
    if deger%x == 0:
        print(f"{deger} asal sayı değil")
        break
    else:
        x -= 1
else:
    print(f"{deger} asal sayıdır")


