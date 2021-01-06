import cv2
from matplotlib import pyplot
I = cv2.imread("./lenna.png")
print(I.shape)
print(type(I))
pyplot.imshow(I)
pyplot.show()