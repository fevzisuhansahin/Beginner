class Item:
    def __init__(self,barcodeNo,itemName,price,count):
        self.name = itemName
        self.no = barcodeNo
        self.price = price
        self.count = count
        self.amountInBasket = 0
        
    def getPrice(self):
        return self.price * self.amountInBasket
        
    def increaseCount(self):
        if self.amountInBasket < self.count:
            self.amountInBasket += 1
        else:
            print(f"\n{self.name} is out of stock !")
            input("\nPress ENTER to continue")
