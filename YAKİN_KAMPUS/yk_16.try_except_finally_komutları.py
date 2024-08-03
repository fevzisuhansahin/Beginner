print(round(1.8)) # round yuvarlama yapar

def yuvarla(): # eğer ben buraya sayı hariç bir şey girersem ValueError verir
    sayi = float(input("Yuvarlamak istediğiniz ondalık sayıyı yazınız: "))
    print(f"{sayi} sayısının yuvarlanmış hali {round(sayi)} dır")
    
#yuvarla() 


# try-except kullanımı: kodun hata verip durmasını engellemek için kullanılır

def yuvarla_1():
    sayi = input("Yuvarlamak istediğiniz ondalık sayıyı yazınız: ")
    
    try:
        sayi = float(sayi)
        print(f"{sayi}'nin yuvarlanmış hali {round(sayi)} dır")
    except: # eğer hiçbir hata tanımlamazsak tüm hataları içerir.
        print(f"'{sayi}' ondalık tipe çevirilemiyor")

"""def yuvarla_1():  # try dan sonra yapılacak şeyi else ile de yazılabilir
    sayi1 = input("Yuvarlamak istediğiniz ondalık sayıyı yazınız: ")
    
    try:
        sayi1 = float(sayi1)
    except:
        print(f"'{sayi1}' ondalık tipe çevirilemiyor")
    else:
        print(f"{sayi1}'nin yuvarlanmış hali {round(sayi1)} dır")"""
        
#yuvarla_1()


# finally kullanımı: try veya except dizininden hangisi çalışırsa çalışsın sonda çalışan dizin

def yuvarla_2():
    sayi = input("Yuvarlamak istediğiniz ondalık sayıyı yazınız: ")
    a = ""
    
    try:
        sayi = float(sayi)
        print(f"{sayi}'nin yuvarlanmış hali {round(sayi)} dır")
        a = "başarılı"
    except: 
        print(f"'{sayi}' ondalık tipe çevirilemiyor")
        a = "başarısız"
    finally:
        print(f"Yuvarlama işlemi {a}")
        
# yuvarla_2()


def yuvarla_dongu():
    
    while True:
        sayi = input("Yuvarlamak istediğiniz sayıyı giriniz: ")
        try:
            sayi = float(sayi)
            print(f"{sayi}'nin yuvarlanmış hali {round(sayi)} dır")
            break
        except:
            print(f"'{sayi}' ondalık tipe çevirilemiyor")
            pass
            
#yuvarla_dongu()