import cv2 as cv
import numpy as np

img = cv.imread(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\stretched_image.jpeg")

lower = np.array([10,10,100])
upper = np.array([150,150,160])
mask = cv.inRange(img, lower, upper)

contours, _ = cv.findContours(mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)

if contours:
    big_contour = max(contours, key=cv.contourArea)
    x, y, w, h = cv.boundingRect(big_contour)
    cv.rectangle(img, (x,y), (x+w,y+h), (0,0,255), 2)
    cv.putText(img, "BALIK", (x,y-10), cv.FONT_HERSHEY_COMPLEX, 0.8, (0,0,255), 1)
    
cv.imshow("Filtered Image", img)
cv.waitKey(0)
cv.destroyAllWindows()

cv.imwrite(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\filtered_image(RGB).jpeg", img)