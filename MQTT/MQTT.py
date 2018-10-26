from ttn import*
from time import sleep
from base64 import* 

access_key = "ttn-account-v2.r1GHuXo2c-yLQF-F0QYDod7Mapk4zfzrrnefFYAs60I"
app_id = "lorakeypad"
dev_id = "sodaqone"
discovery_address="discovery.thethings.network:1900"

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
        payload = b64encode("Y")
        client.send(dev_id, payload, port=1, confirmation=False, schedule="replace")
    else: 
        print("code not found : ", code)
        payload = b64encode("N")
        client.send(dev_id, payload, port=1, confirmation=False, schedule="replace")

handler = HandlerClient(app_id, access_key)

mqtt_application = handler.application()

# using mqtt client
mqtt_client = handler.data()
mqtt_client.set_uplink_callback(uplink_callback)
mqtt_client.connect()
print("Serving ", app_id)
while True:
    pass

mqtt_client.close()


"""
# using application manager client
app_client =  handler.application()
my_app = app_client.get()
print(my_app)
my_devices = app_client.devices()
print(my_devices)
"""








"""
 
Handler_obj = HandlerClient(app_id, access_key, discovery_address, cert_path="")
#App_obj = ApplicationClient(app_id, access_key, handler_address="", cert_content="", discovery_address="discovery.thethings.network:1900")

Client_obj = Handler_obj.data() 
App_obj = Handler_obj.application()


def callback(msg, Client):
    print(msg.payload_raw())


payload={ "code": "ok"}




Client_obj.set_uplink_callback(callback)
Client_obj.send(dev_id, payload, port=1)


while(True):
    pass
    

"""
