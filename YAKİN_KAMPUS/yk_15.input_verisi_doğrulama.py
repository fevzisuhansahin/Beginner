# isdigit(): string karakter dizisinin sadece sayılarda oluşup oluşmadığını sorgular. 
# True dönmesi için sayı değerli karakter dizilerinin bir tam sayıdan oluşması gerekiyor.

def sayi_kontrol():
    sayi = input("Kontrol etmek istediğniz karakterleri girin: ")
    if sayi.isdigit():
        print("Tüm karakterler sayı karakteridir.")
    else:
        print("Sayı olmayan karakter/karakterler mevcut")
        
#sayi_kontrol()

def sayi_kontrol_dögüsü():
    sayi1 = input("Kontrol etmek istediğniz karakterleri giriniz: ")
    
    while not(sayi1.isdigit()):
        sayi1 = input("Sayı olmayan karakter/karakterler mevcut. Tekrar deneyin: ")
    else:
        print("Tüm karakterler sayı karakteridir.")
        
#sayi_kontrol_dögüsü()

def gmail_control_döngüsü():
    gmail = input("Kontrol etmek istediğniz gmail adresini girin: ")
    
    while not(("@" in gmail) and ("gmail" in gmail) and (".com" in gmail)):
        gmail = input("Geçerli bir gmail değil. Tekrar deneyin: ")
    else:
        print(f"'{gmail}' geçerli bir gmail adresidir.")
        
#gmail_control_döngüsü()