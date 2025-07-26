import cv2 as cv
import numpy as np

def callback():     # function do nothing
    pass

cv.namedWindow("Camera", cv.WINDOW_NORMAL)

# Trackbar creation
cv.createTrackbar("lowH", "Camera", 0, 179, callback)
cv.createTrackbar("highH", "Camera", 179, 179, callback)

cv.createTrackbar("lowS", "Camera", 0, 255, callback)
cv.createTrackbar("highS", "Camera", 255, 255, callback)

cv.createTrackbar("lowV", "Camera", 0, 255, callback)
cv.createTrackbar("highV", "Camera", 255, 255, callback)

cap = cv.VideoCapture(0)    # open camera
if not cap.isOpened():
    raise IOError("Camera is not opened!")

while True:
    ret, frame = cap.read()
    if not ret:
        print("There is no frame. Exiting...")
        break
    
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)  # BGR to HSV

    # get value of trackbar
    currLowH = cv.getTrackbarPos("lowH", "Camera")
    currHighH = cv.getTrackbarPos("highH", "Camera")
    
    currLowS = cv.getTrackbarPos("lowS", "Camera")
    currHighS = cv.getTrackbarPos("highS", "Camera")
    
    currLowV = cv.getTrackbarPos("lowV", "Camera")
    currHighV = cv.getTrackbarPos("highV", "Camera")
    
    # filter processing
    lower = np.array([currLowH,currLowS,currLowV])
    upper = np.array([currHighH,currHighS,currHighV])
    
    mask = cv.inRange(hsv, lower, upper)
    result = cv.bitwise_and(frame, frame, mask = mask)
    
    cv.imshow("Source", frame)
    cv.imshow("Mask", mask)
    cv.imshow("Result", result)
    if cv.waitKey(1) & 0xFF == 27:      # wait until ESC key is pressed
        break    
    
cap.release()           # close camera
cv.destroyAllWindows()    