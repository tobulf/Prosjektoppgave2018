import numpy as np
import matplotlib.pyplot as plt
from json import loads
from datetime import datetime
import dateutil.parser


dev_id = "keypad"
date = "13.11.2018"
gateway = "trt-olav-loragw01"
 
somedate = datetime

Datarates = ["SF12BW125", "SF11BW125", "SF9BW125", "SF8BW125", "SF7BW125"]


def MetadataListFromLog(dev_id, gateway, date):
    # Returns a list wich contains all metadata from given gateway at a given date.
    temp = []
    try:
        Log = open('Logs '+dev_id+"/"+gateway+" "+date+".txt",'r')
        for line in Log:
            #Load each line from Json:
            temp.append(loads(line))
        Log.close()
        return temp
    except FileNotFoundError:
        print("File not found...")
        return temp


def MakeArrays(metadatalist):
    # Takes in metadatalist, returns 
    DRarray = []
    timearray = []
    rssiarray = []
    snrarray = []
    for i in range(len(metadatalist)):
        DRarray.append(metadatalist[i][0])
        timearray.append(dateutil.parser.parse(metadatalist[i][3]))
        rssiarray.append(metadatalist[i][5])
        snrarray.append(metadatalist[i][6])
    return DRarray, timearray, rssiarray, snrarray


def PlotFigures(x, y):
    x = np.array(x)
    y = np.array(y)
    plt.plot(x,y)
    plt.show()


something = MetadataListFromLog("keypad",gateway , date)

yourdate = dateutil.parser.parse(something[0][3])

a,b,c,d = MakeArrays(something)
PlotFigures(b,d)
#meta Format ["trt-vm-loragw01", True, 1040756148, "2018-11-08T11:39:10Z", 0, -120, -8.75, 1, 63.42883, 10.385698, 20]



meta = ["trt-vm-loragw01", True, 1040756148, "2018-11-08T11:39:10Z", 0, -120, -8.75, 1, 63.42883, 10.385698, 20]
