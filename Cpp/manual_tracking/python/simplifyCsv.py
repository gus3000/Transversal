#!/bin/python3

import sys
import csv
import os
import json
from optparse import OptionParser
from collections import OrderedDict
parser = OptionParser()
parser.add_option("-o",dest="output",help="output directory")

(options,args) = parser.parse_args()
outputDir = options.output
if not outputDir.endswith(os.sep):
    outputDir = outputDir + os.sep

if len(args) == 0:
    print("Gimme a fyl pliz")
    exit(-1000)
    print("Personne ne verra jamais ce message mwahaha")

for i in range(len(args)):
    print (args[i])
    csvFullPath = args[i]
    csvDir,csvName = os.path.split(csvFullPath)
    prefix,ext = os.path.splitext(csvName)
    newCsv = list()
    newJson = list()
    with open(csvFullPath,'r') as csvFile:
        reader = csv.reader(csvFile, delimiter=',')
        oldX=-1
        oldY=-1
        for row in reader:
            frame = row[0]
            x = row[1]
            y = row[2]
            
            if x == oldX and y == oldY:
                continue
            
            newCsv.append(row)
            newJson.append(OrderedDict([('frame',int(frame)), ('x',int(x)), ('y',int(y))]))
            oldX = x
            oldY = y

    jsonName=prefix + ".json"
    jsonFullPath = outputDir + jsonName
    with open(jsonFullPath,'w+') as jsonFile:
        print('writing',jsonFullPath)
        json.dump(newJson,jsonFile)
    
#    with open(csvName,"w+") as csvFile:
#        writer = csv.writer(csvFile, delimiter=',')
#        for row in newCsv:
#            writer.writerow(row)
                   
