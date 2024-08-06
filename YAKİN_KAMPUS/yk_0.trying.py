while True:
    s = input("Saati giriniz: ")
    
    if not s.isdigit():
        print("Sayı girmediniz. Tekrar giriniz.")
        continue
    elif not (int(s)>=0 and int(s)<24):
        print("Saat bu aralıkta olamaz.")
        continue
    else:
        break
    
while True:    
    d = input("Dakikayı giriniz: ")
    
    if not d.isdigit():
        print("Sayı girmediniz. Tekrar giriniz.")
        continue
    elif not (int(d)>=0 and int(d)<60):
        print("Dakika bu aralıkta olamaz.")
        continue
    else:
        break
    
print(f"Saat: {s} - Dakika: {d}")