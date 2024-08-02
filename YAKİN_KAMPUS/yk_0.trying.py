metin = """Deniz kenarında oturmak, denizden gelen rüzgarın yüzüne çarpmasıyla birlikte huzur verir. Deniz sesi, denizin mavi tonları, denizdeki dalgaların hareketi insana dinginlik katar. Her dalga, denizin ne kadar sonsuz olduğunu hatırlatır. Denizdeki balıkların yüzüşünü izlemek, deniz kenarında yürüyüş yapmak, deniz kokusunu içine çekmek insanı mutlu eder. Deniz, her zaman bir kaçış noktasıdır. Denizin serin suları, denizde yüzmenin keyfi, deniz manzarasıyla birleştiğinde insanın ruhu dinlenir. Deniz, her şeyden uzaklaşmak için ideal bir yerdir."""

# Bir metin dosyasındaki kelimeleri sayan ve her kelimenin kaç kez geçtiğini belirten bir program.

# kelimeleri ayırıp sayma genel

special_char = ["," , "."]
kelimeler = metin.split(" ")

for x in range(len(kelimeler)):
    kelimeler[x] = kelimeler[x].lower()
    for c in special_char:
        kelimeler[x] = kelimeler[x].replace(c,"")
    
print(kelimeler)
    
print(f"Kelime sayısı: {len(kelimeler)}")

# ayrı ayrı kelime sayısı

ayri_kelimeler = {}
for i in kelimeler:
    if i not in ayri_kelimeler:
        ayri_kelimeler[i] = 1
    else:
        ayri_kelimeler[i] += 1
        
for a , b in ayri_kelimeler.items():
    print(f"{a} kelimesinden {b} tane var.")