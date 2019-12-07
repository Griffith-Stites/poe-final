# Learn how to read an image, display it, and how to save it back
# https://docs.opencv.org/4.1.2/dc/d2e/tutorial_py_image_display.html

import numpy as np
import cv2 as cv

# Read an image
# Load a color image in grayscale
img = cv.imread('cat.jpg',0)

# Display an image
cv.imshow('image',img) # Window name, image
k = cv.waitKey(0) & 0xFF
if k == 27:         # wait for ESC key to exit
    cv.destroyAllWindows()
elif k == ord('s'): # wait for 's' key to save and exit
    cv.imwrite('messigray.png',img)
    cv.destroyAllWindows()

# key input does not work
