#!/usr/bin/python3

import json
import sys

class Zone:
    def __init(self,x,y):
        self.x = x
        self.y = y

input = sys.stdin.read()
json_input = json.loads(input)
#print(json_input)

for obs in json_input:
    x = obs["x"]
    y = obs["y"]
    print(x,y)
    
