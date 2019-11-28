# https://docs.opencv.org/4.1.2/dd/d43/tutorial_py_video_display.html

import numpy as np
import cv2 as cv
cap = cv.VideoCapture(0)
cap.set(cv.CAP_PROP_FRAME_WIDTH, 1280)
cap.set(cv.CAP_PROP_FRAME_HEIGHT, 720)
# Define the codec and create VideoWriter object
fourcc = cv.VideoWriter_fourcc(*'mp4v')
out = cv.VideoWriter('output.mp4', fourcc, 20.0, (1280,  720))
while cap.isOpened():
    ret, frame = cap.read()
    if not ret:
        print("Can't receive frame (stream end?). Exiting ...")
        break
    # frame = cv.flip(frame, 0)
    # write the flipped frame
    out.write(frame)
    cv.imshow('frame', frame)
    if cv.waitKey(1) == ord('q'):
        break
# Release everything if job is finished
cap.release()
out.release()
cv.destroyAllWindows()

# CODEC INSTALL
# https://stackoverflow.com/questions/30103077/what-is-the-codec-for-mp4-videos-in-python-opencv
# sudo pacman -Su ffmpeg x264b
# Had to run as root to save?
# https://wiki.archlinux.org/index.php/Codecs_and_containers
