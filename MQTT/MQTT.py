from ttn import*
from time import sleep
from base64 import*
import json

access_key = "ttn-account-v2.xPTndt8DMHEw2PVy5lm9nq2CPEQaixaGFGM4ODnMEt8"
app_id = "lorakeypad"
dev_id = "keypad"

Database = [7020, 2012, 7063, 7568 ,1569]



def check_code(code, list):
    if code in list:
        return True
    else:
        return False


def uplink_callback(msg, client):
    print("Received uplink from ", msg.dev_id)
    code = int.from_bytes(b64decode(msg.payload_raw), byteorder = 'big')
    
    meta = msg.metadata
    print(json.dumps(meta))
    print(len(meta[6]))
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


