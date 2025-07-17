from item import Item
from basket import Basket

urun1 = Item(123, "Chocolate", 10, 5)
urun2 = Item(456, "Water", 15, 2)
urun3 = Item(789, "Cips", 20, 3)
urun4 = Item(000, "Cheese", 30, 4)

cart = Basket(0)

def menu():
    while True:
        print("\n--- Menu ---")
        print("1. Add Product")
        print("2. Basket Info")
        print("3. Calculate Total Basket Price")
        print("4. Exit")
        secim = input("Your choice: ")

        if secim == "1":
            print("\n1. Chocolate\n2. Water\n3. Cips\n4. Cheese")
            urun_sec = input("Choose what do you want to add: ")
            if urun_sec == "1":
                cart.addItem(urun1)
            elif urun_sec == "2":
                cart.addItem(urun2)
            elif urun_sec == "3":
                cart.addItem(urun3)
            elif urun_sec == "4":
                cart.addItem(urun4)
            else:
                print("Invalid Product!")
        elif secim == "2":
            cart.basketInfo()
        elif secim == "3":
            cart.calculateTotalPrice()
        elif secim == "4":
            print("Exit successfull.")
            break
        else:
            print("Invalid Choice!")

if __name__ == "__main__":
    menu()
