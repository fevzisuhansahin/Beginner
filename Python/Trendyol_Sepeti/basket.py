from item import Item

class Basket:
    def __init__(self,ID):
        self.id = ID
        self.items = []
    
    def addItem(self, newItem):
        uniqueBarcode = {i.no for i in self.items}
        countUnique = len(uniqueBarcode)
        alreadyInBasket = newItem.no in uniqueBarcode
        
        if countUnique >= 3 and not alreadyInBasket:
            print(f"Only 3 different items are allowed in basket. {newItem.name} is didn't add in basket")
            input("\nPress ENTER to continue")
            return
        
        for item in self.items:
            if item.no == newItem.no:
                item.increaseCount()
                return
            
        newItem.increaseCount()
        self.items.append(newItem)
        print(f"\n{newItem.name} added successfully")
        input("\nPress ENTER to continue")
    
    def basketInfo(self):
        if not self.items:
            print("Basket is empty!!")
            input("\nPress ENTER to continue")
            return
        
        print("\n\t\tBasket Info")
        print("-" * 50)
        for item in self.items:
            print(f"{item.name:<10} | Count: {item.amountInBasket:<5} | Total Price: {item.getPrice():<5} TL")
        print("-" * 50)
        print(f"Total Number of Items: {sum([item.amountInBasket for item in self.items])}")
        input("\nPress ENTER to continue")
    
    def calculateTotalPrice(self):
        total = sum(item.getPrice() for item in self.items)
        print(f"\nTotal Basket Price: {total} TL")
        input("\nPress ENTER to continue")