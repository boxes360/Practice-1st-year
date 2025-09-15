import cv2
import numpy as np

image = cv2.imread("test.jpg")

cv2.imshow("original", image)

cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)

cv2.imshow("blurred", blurred_image)

cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)

cv2.imshow("hsv", hsv_image)

cv2.waitKey(0)

hsv_min = np.array((20, 100, 100), np.uint8)
hsv_max = np.array((36, 255, 255), np.uint8)

yellow_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)

cv2.imshow("mask", yellow_mask)

cv2.waitKey(0)

contours, hierarchy = cv2.findContours(yellow_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)

sorted_contur = sorted(contours, key=cv2.contourArea, reverse=True)

for contour in sorted_contur:
    if cv2.contourArea(contour) < 100:
        continue
    x, y, w, h, = cv2.boundingRect(contour)
    print(x, y, w, h)
    cv2.circle(image,(int (x+w/2),int (y+h/2)),5 , (0,0,255), -1)

cv2.imshow('contours', image)
cv2.waitKey(0)
cv2.destroyAllWindows()
