import sys

from PyQt5.QtWidgets import *
from Utils.PointRect import Point,Rect


class Zone:
    pass

class ZoneRect:
    def __init__(self, *argv):
        if len(argv) == 4:
            self.initWithCoords(*argv)
        elif len(argv) == 1:
            self.initWithRect(argv[0])


    def initWithCoords(self, x1,y1, x2,y2):
        self.x1 = x1
        self.y1 = y1
        self.x2 = x2
        self.y2 = y2
        self.center = Point(x=(x1+x2)/2, y=(y1+y2)/2)

    def initWithRect(self, rect):
        self.x1 = rect.left
        self.y1 = rect.top
        self.x2 = rect.right
        self.y2 = rect.bottom
        self.center = Point(x=(self.x1+self.x2)/2, y=(self.y1+self.y2)/2)

    def show(self):
        print(self.x1,self.y1, self.x2,self.y2)

    def isInThisZone(self, obsel):
        pass


z1 = ZoneRect(0,0,10,20)
z1.show()
#z2 = ZoneRect(Rect(Point(0,0),Point(10,20)))
