# 1 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino"
# 1 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino"
# 2 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino" 2
# 3 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino" 2
# 4 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino" 2
# 5 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino" 2
# 15 "c:\\Users\\Tobias\\Documents\\Git\\TTK8-C++\\Sodaq_dummy\\Sodaq_dummy.ino"
static rn2xx3 lorawan(Serial1);
unsigned long time;

void setup() {
    SerialUSB.begin(57600);
    Serial1.begin(57600);
    Serial.begin(57600);
    Serial1.flush();
    SerialUSB.flush();
    Serial.flush();
    // Set user button as INPUT:
    pinMode(19, (0x0));
    // Enable LED'S:
    pinMode(14, (0x1));
    pinMode(15, (0x1));
    pinMode(16, (0x1));
    // Enable GPS:
    pinMode(18, (0x1));

    const char *appeui = "70B3D57ED0013824";
    const char *appkey = "0222B8B8AE6A77BE0C040ABF13B8E8E7";
    digitalWrite(14, (0x1));
    //digitalWrite(green_led, HIGH);
    //digitalWrite(blue_led, HIGH);
    bool joined = false;
 joined = lorawan.initOTAA(appeui, appkey);
    // Set data-rate to SF7/125kHz. See. Lorawan regional paramaeters p. 16.
    lorawan.setDR(5);
    SerialUSB.print("Initialized");

};

void loop() {
    byte end = 0b00000010;
    if((millis()-time) > 15000 || digitalRead(19) == (0x0)){
        digitalWrite(14, (0x0));
        digitalWrite(16, (0x1));
        for(int i = 0; i<5; i++){
            lorawan.setDR(i);
            lorawan.txBytes(&end, 1);
            delay(1000);
            time = millis();
        }
        digitalWrite(16, (0x0));
        digitalWrite(14, (0x1));
    };
}
