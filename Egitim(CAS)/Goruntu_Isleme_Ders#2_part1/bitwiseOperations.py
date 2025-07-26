import cv2 as cv
import numpy as np

backward =np.zeros((400,400), dtype=np.uint8)

circle = backward.copy()
cv.circle(circle, center=(200,200), radius=125, color=255, thickness=-1)

square = backward.copy()
cv.rectangle(square, (100,100), (300,300), 255, -1)

not_square = cv.bitwise_not(square)

and_img = cv.bitwise_and(square, circle)
or_img = cv.bitwise_or(square, circle)
xor_img = cv.bitwise_xor(square, circle)

cv.imshow("Daire", circle)
cv.imshow("Kare", square)
cv.imshow("AND", and_img)
cv.imshow("OR", or_img)
cv.imshow("XOR", xor_img)

cv.waitKey(0)
cv.destroyAllWindows()