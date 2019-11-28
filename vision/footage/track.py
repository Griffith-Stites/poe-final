# https://docs.opencv.org/4.1.2/df/d9d/tutorial_py_colorspaces.html
import cv2 as cv
import numpy as np

green = np.uint8([[[74, 173, 2]]]) # BGR
purple = np.uint8([[[91, 53, 53]]])
lightPurple = np.uint8([[[246, 189, 169]]])
blue = np.uint8([[[253, 142, 63]]])
hsvTarget = cv.cvtColor(green, cv.COLOR_BGR2HSV) #convert to HSV
print(hsvTarget)
h = hsvTarget[0, 0, 0]
s = hsvTarget[0, 0, 1]
v = hsvTarget[0, 0, 2]
lower = np.array([h-10,50,50])
upper = np.array([h+10,200,200])

# cap = cv.VideoCapture('lightPurpleUp.mp4')
cap = cv.VideoCapture(0)
cap.set(cv.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv.CAP_PROP_FRAME_HEIGHT, 720)
cap.set(cv.CAP_PROP_FPS, 60)

while(1):
    # Take each frame
    _, frame = cap.read()
    # Convert BGR to HSV
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    # Get the color for that frame
    mask = cv.inRange(hsv, lower, upper)
    cv.imshow('mask',mask) # color layer

    k = cv.waitKey(5) & 0xFF
    if k == 27:
        break
cv.destroyAllWindows()
