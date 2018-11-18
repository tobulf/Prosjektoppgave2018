import os
from json import dumps



current_directory = os.getcwd()



def WriteMetaToFile(dev_id, Metadata, date):
    #Create directory for each day
    directory = 'Logs '+str(dev_id)
    final_directory = os.path.join(current_directory, (r''+directory))
    if not os.path.exists(final_directory):
        os.makedirs(final_directory)
    for i in range(len(Metadata[6])):
        temp = list(Metadata[6][i])
        try:
            Log = open(directory+"/"+str(Metadata[6][i][0])+" "+date+".txt",'x')
            # Save datarate instead of the name of the Gateway:
            temp[0] = Metadata[3]
            Log.write(dumps(temp)+"\n")
            Log.close()
        except OSError:
            Log = open(directory+"/"+str(Metadata[6][i][0])+" "+date+".txt",'a')
            # Save datarate instead of the name of the Gateway:
            temp[0] = Metadata[3]
            Log.write(dumps(temp)+"\n")
            Log.close()




some_date = "10.11.2018"
#Metadata format:

meta = ["2018-11-08T11:41:52.772067729Z", 868.1, "LORA", "SF12BW125", 1155072000, "4/5", [
["trt-vm-loragw01", True, 1040756148, "2018-11-08T11:39:10Z", 0, -120, -8.75, 1, 63.42883, 10.385698, 20], 
["trt-sluppen-loragw01", True, 1338177276, "2018-11-08T11:39:43Z", 0, -114, 2.75, 1, 63.397568, 10.400948, 21], 
["trt-samf-loragw01", True, 1567384756, "2018-11-08T12:02:07Z", 0, -111, 3.5, 1, 63.422485, 10.395755, 20], 
["eui-008000000000a447", 1628454124, "2018-11-08T13:04:42.647744Z", 0, -119, -13.8, 0, 63.41785, 10.4021, 112],
["trt-olav-loragw01", True, 3798105164, "2018-11-08T11:40:27Z", 0, -117, -14.25, 1, 63.43338, 10.403285, 19], 
["ntnu1", True, 2597174828, "2018-11-08T11:41:52Z", 0, -119, -15, 1, 63.41831, 10.400998, 60, "registry"]]
]

WriteMetaToFile("lorakeypad",meta, some_date)
