import cv2 as cv
import numpy as np

img = cv.imread(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\image.jpeg")
if img is None:
    print("Image is not found!")

def stretch_channel(chnl):
    chnl_f = chnl.astype(np.float32)
    min_val = np.min(chnl_f)
    max_val = np.max(chnl_f)
    
    stretched = ((chnl - min_val) * 230 / (max_val - min_val)) + 10
    stretched = np.clip(stretched,0,255)
    return stretched.astype(np.uint8)

b, g, r = cv.split(img)

b_new = stretch_channel(b)
g_new = stretch_channel(g)
r_new = stretch_channel(r)

new_img = cv.merge([b_new,g_new,r_new])

cv.imshow("Source Image", img)
cv.imshow("New Image", new_img)
cv.waitKey(0)
cv.destroyAllWindows()

cv.imwrite(r"c:\Users\YUNUS\Desktop\Beginner\Python\Goruntu_Isleme\stretched_image.jpeg", new_img)