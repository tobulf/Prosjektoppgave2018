import os
import datetime

metadata = ["2018-11-07T19:34:50.286891292Z", 868.3, "LORA", "SF12BW125", 1155072000, "4/5", 
[
["eui-008000000000a447", 3735560404, "2018-11-07T20:57:40.379936Z", 1, -119, -18.2, 0, 63.41785, 10.4021, 112], 
["ntnu1", "true", 898761012, "2018-11-07T19:34:50Z", 1, -117, -6.5, 1, 63.41831, 10.400998, 60, "registry"], 
["trt-sluppen-loragw01", "true", 3445234500, "2018-11-07T19:32:41Z", 1, -113, -7.75, 1, 63.397568, 10.400948, 21], 
["trt-samf-loragw01", "true", 3674536196, "2018-11-07T19:55:05Z", 1, -101, -1.25, 1, 63.422485, 10.395755, 20]
]
]

now = datetime.datetime.now()
print(now.day, now.month, now.year)
print (now.isoformat())
for i in range(len(metadata[6])):
    log_file = open(str(metadata[6][i][0])+"_RSSI_LOG.txt","a+")
