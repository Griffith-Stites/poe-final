# Approach
The approach for code
1. Color recognition - output should just be white and black
2. Object recognition - can we look for a rectangle?
3. Draw around this rectangle
4. Track the movement of this rectangle

Old:
1. Image recognition - output should just be the white and black
2. Blob count - Find the highest concentration of the desired colors
 - This is a form of feature recognition
3. Draw around the biggest blob (or two blobs?)
4. Track the movement of the box around the blob count. If it does something notable, move the bot (Ex: swipe left, move robot left)

## Options
1. Have backlit item, look for the bright thing

## Resources
[SURF](https://docs.opencv.org/4.1.2/df/dd2/tutorial_py_surf_intro.html)
Blob count stuff
