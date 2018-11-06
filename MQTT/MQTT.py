from ttn import*
from time import sleep
from base64 import*

access_key = "ttn-account-v2.iM6CNuP5YeytK_pQCm14-FK1_uBh4B_a7I8xaer_jjE"
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
    #Check-code
    if check_code(code, Database):
        print("code found: ", code)
        payload = b64encode("Y".encode())
        client.send(msg.dev_id, payload, port=1, confirmation=False, schedule="replace")
    else: 
        print("code not found : ", code)
        payload = b64encode("N".encode())
        client.send(msg.dev_id, payload, port=1, confirmation=False, schedule="replace")

handler = HandlerClient(app_id, access_key)

mqtt_application = handler.application()

# using mqtt client
mqtt_client = handler.data()
mqtt_client.set_uplink_callback(uplink_callback)
mqtt_client.connect()
print("Serving ", app_id)
payld = b64encode("Y".encode())
print(payld)
while True:
    sleep(2000)
    mqtt_client.send(dev_id, payld, port=1, confirmation=False, schedule="replace")
    pass

mqtt_client.close()

