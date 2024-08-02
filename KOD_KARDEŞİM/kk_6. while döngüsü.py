sayı = 0
while sayı < 5:
    print(sayı)
    sayı += 1

tkr = 0
while tkr < 5:
    print("coder")
    tkr +=1

'''while True:              #eğer while'a True değerii verirsek sonsuza kadar çalışır.
    print("coder")          #break komutu vererek bu döngüyü sonlandırabilirz.'''

tekrar = 0
while True:
    print("code")          #burada 5'e eşit olunca dedim ama sıfırdan başladığı için 6 kere yazdı
    if tekrar == 5:
        break
    tekrar += 1
