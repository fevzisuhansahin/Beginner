def sayfaadi():
    print("coder")

sayfaadi()


def sayfaismi():
    return "coder"

print(sayfaadi())

"""OUTPUT      #Why
coder
coder
None"""

def toplama(sayi1,sayi2):
    print("toplama sonuu: ",(sayi1+sayi2))

toplama(10,10)

    
def cevre_ve_alan(kenar1,kenar2):

    cevre = (kenar1+kenar2)*2
    alan =  (kenar1*kenar2)

    print("Çevresi: ",cevre ,"  Alanı: ",alan)

cevre_ve_alan(5,10)