import sys, random
from PyQt5.QtWidgets import QWidget, QApplication
from PyQt5.QtGui import QPainter, QColor, QPen
from PyQt5.QtCore import Qt
from Utils.PointRect import Point,Rect
from warnings import *

warn("DebugWindow deprecated", DeprecationWarning)
class DebugWindow(QWidget):
    def __init__(self):

        super().__init__()
        self.initUI()
        self.rectangles = list()
        self.rectangles.append(Rect(Point(10,20),Point(30,40)))

    def initUI(self):
        #self.setGeometry(300,300,280,170)
        self.setWindowTitle("Debug Window")
        self.show()

    def paintEvent(self, qPaintEvent):
        qp = QPainter()
        qp.begin(self)
        self.drawPoints(qp)
        qp.end()

    def drawPoints(self, qp):
        qp.setPen(Qt.red)
        size = self.size()
        for rect in self.rectangles:
            qp.drawRect( rect.left,rect.top, rect.right - rect.left, rect.bottom - rect.top)


if __name__ == '__main__':
    app = QApplication(sys.argv)
    win = DebugWindow()
    sys.exit(app.exec())

