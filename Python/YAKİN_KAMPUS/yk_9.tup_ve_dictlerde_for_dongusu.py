tup1 = (1,3,5,7)
for sayi in tup1:
    print(sayi)
    
    
kullanici1 = {'ad': 'Naz', 'soyad':'Yagcioglu'}
for key, value in kullanici1.items():
    print("Key: {} \t Value: {}".format(key, value))


kullanici1 = {'ad': 'Naz', 'soyad':'Yagcioglu'}
for key in kullanici1.keys():
    print("Key: {}".format(key))
    

kullanici1 = {'ad': 'Naz', 'soyad':'Yagcioglu'}
for value in kullanici1.values():
    print("Value: {}".format(value))