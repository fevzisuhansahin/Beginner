import cv2
import numpy as np

img = cv2.imread(r"C:\Users\YUNUS\Desktop\Beginner\Egitim(CAS)\egitim_part2\shi-tomasi.jpeg")
gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)

corners = cv2.goodFeaturesToTrack(gray, maxCorners=50, qualityLevel= 0.05, minDistance= 10)
corners = np.int0(corners)

for i in corners:
    x,y = i.ravel()
    cv2.circle(img, (x,y), 3, 255, -1)

cv2.imshow("shi-tomasi", img)
cv2.waitKey(0)
cv2.destroyAllWindows()