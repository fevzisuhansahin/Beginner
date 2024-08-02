# break 

harfler = ["a" , "b" , "c" , "d" , "e"]
for index,harf in enumerate(harfler):
    if harf == "c":                                        # bu durumda sıkıntı yok çünkü bir tane c harfi var
        print(f"{harf} harfi {index} numaralı indexte")
        
harfler1 = ["a" , "b" , "c" , "d" , "e"] * 100
for index1,harf1 in enumerate(harfler1):                   # burada ise sadece ilk c'nin indexini istiyorum
    if harf1 == "c":                                       # bu yüzden break kullandım
        print(f"{harf1} harfi {index1} numaralı indexte")  # kullanmazsam bütün c'lerin indexini yazdırır
        break
    
# continue

for i in range(1,11):
    if i%2 == 1:  # tek çift kontrol etme yöntemi
        continue  # continue döngüyü kesip başa alır
    print(f"Çift Sayı: {i}")
## continue kullanmadan şu şekilde de yapılabilir
for x in range(1,11):
        if x%2 == 1:
            print(f"Tek Sayı: {x}")
            
# pass

for a in range(1,11):
    if a%2 == 1:
        pass
    else:
        print(f"Çift Sayı: {a}")
        
## pass geçmek istediğimiz bir koşul için de kullanılır

for b in range(1,11):
    if b <= 5:
        pass
    else:
        print("OK")