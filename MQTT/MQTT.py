from ttn import*
from time import sleep
from datetime import datetime
from base64 import*
from threading import*
from Logger import WriteMetaToFile
import json

access_key = "ttn-account-v2.wgnue4Mnikv-AdVHu0qfFM56FtSVcFvZRqVWFIZP08s"
app_id = "lorakeypad"


Database = [7020, 2012, 7063, 7568 ,1569]
Start_date = datetime.now()
date = str(Start_date.day)+"." + str(Start_date.month)+"." + str(Start_date.year)




def check_code(code, list):
    if code in list:
        return True
    else:
        return False


def uplink_callback(msg, client):
    global date
    print("Received uplink from ", msg.dev_id)
    #Convert received data to int:
    code = int.from_bytes(b64decode(msg.payload_raw), byteorder = 'big')
    meta = msg.metadata
    # Log the metadata to file.
    WriteMetaToFile(msg.dev_id, meta, date)
    #Check-code
    if check_code(code, Database):
        print("code found: ", code)
        payload = b64encode("Y".encode()).decode("utf-8")
        client.send(msg.dev_id, str(payload), port=1, conf=True, sched="first")
    else: 
        print("code not found : ", code)
        payload = b64encode("N".encode()).decode("utf-8")
        client.send(msg.dev_id, payload, conf=True, sched="first")

handler = HandlerClient(app_id, access_key,discovery_address="discovery.thethings.network:1900")

mqtt_application = handler.application()

# using mqtt client
mqtt_client = handler.data()
mqtt_client.set_uplink_callback(uplink_callback)
mqtt_client.connect()
print("Serving ", app_id)
my_app = mqtt_application.get()
print(my_app)
my_devices = mqtt_application.devices()
print(my_devices)


while True:
    pass

mqtt_client.close()


