import math

print("HESAP MAKİNESİ")
print("""[1] Toplama İşlemi
[2] Çıkarma İşlemi
[3] Çarpma İşlemi
[4] Bölme İşlemi
[5] Üs alma İşlemi
[6] Karekök alma İşlemi""")

while True:
    
    numara= int(input("İşlem Numarası Seçiniz: "))

    if numara == 1:
        sayi1= int(input("1. sayıyı giriniz: "))
        sayi2= int(input("2. sayıyı giriniz: "))
        print("İşlem sonucu: ", (sayi1+sayi2))

    elif numara == 2:
        sayi1= int(input("1. sayıyı giriniz: "))
        sayi2= int(input("2. sayıyı giriniz: "))
        print("İşlem sonucu: ", (sayi1-sayi2))

    elif numara == 3:
        sayi1= int(input("1. sayıyı giriniz: "))
        sayi2= int(input("2. sayıyı giriniz: "))
        print("İşlem sonucu: ", (sayi1*sayi2))

    elif numara == 4:
        sayi1= int(input("1. sayıyı giriniz: "))
        sayi2= int(input("2. sayıyı giriniz: "))
        print("İşlem sonucu: ", (sayi1/sayi2))
        
    elif numara == 5:
        sayi1 = int(input("Tabanı gir: "))
        sayi2 = int(input("Üssü gir: "))
        print("İşlem sonucu: ", (sayi1**sayi2))

    elif numara == 6:
        sayi1 = int(input("Karekökü alınacak sayıyı gir: "))
        print("İşlem sonucu: ", math.sqrt(sayi1))


    else:
        print("YOK")
 
   
"""
numara= int(input("İşlem Numarası Seçiniz: "))   #bu şekilde yaparsan işlem numarasını "1,2,3,4" den başka bir şey girsende senden "sayi1" ve "sayi2" yi isteyecek
sayi1= int(input("1. sayıyı giriniz: "))
sayi2= int(input("2. sayıyı giriniz: "))


if numara == 1:
    
    print("İşlem sonucu: ", (sayi1+sayi2))

elif numara == 2:
    
    print("İşlem sonucu: ", (sayi1-sayi2))

elif numara == 3:
    
    print("İşlem sonucu: ", (sayi1*sayi2))

elif numara == 4:
    
    print("İşlem sonucu: ", (sayi1/sayi2))

else:
    print("YOK")
"""