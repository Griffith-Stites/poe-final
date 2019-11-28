# https://docs.opencv.org/4.1.2/df/d9d/tutorial_py_colorspaces.html
import cv2 as cv
import numpy as np

blue = np.uint8([[[255, 102, 51]]]) # BGR
red = np.uint8([[[0, 0, 255]]])
pink = np.uint8([[[164, 109, 254]]])
yellow = np.uint8([[[152, 186, 190]]])
hsvTarget = cv.cvtColor(yellow, cv.COLOR_BGR2HSV) #convert to HSV
print(hsvTarget)
h = hsvTarget[0, 0, 0]
lower = np.array([h-15,50,50])
upper = np.array([h+15,255,255])

# cap = cv.VideoCapture(0)
cap = cv.VideoCapture('swipeUp.mp4')

while(1):
    # Take each frame
    _, frame = cap.read()
    # Convert BGR to HSV
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    # Get the color for that frame
    mask = cv.inRange(hsv, lower, upper)

    # Bitwise-AND mask and original image
    res = cv.bitwise_and(frame, frame, mask=mask)
    cv.imshow('frame',frame) # original
    cv.imshow('mask',mask) # blue layer
    # cv.imshow('res',res) # white layer
    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break
cv.destroyAllWindows()
