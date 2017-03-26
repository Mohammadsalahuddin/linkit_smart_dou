//frimware for push temperature data to thinger.io cloud
//Remember to setup the Arduino Libraries
//@Author  Salah uddin


 
#include <YunClient.h>
#include <ThingerYun.h>
#include <Wire.h>
#include <IR_Thermometer_Sensor_MLX90614.h>

//thinger.io credential
#define USERNAME "YOUR_USER_NAME" 
#define DEVICE_ID "YOUR_DEVICE_ID FROM thinger.io"      
#define DEVICE_CREDENTIAL "YOUR_USER_CREDENTIALS"


//intialize the thinger.io
ThingerYun thing(USERNAME, DEVICE_ID, DEVICE_CREDENTIAL);

//The DFRobot IR Thermometer 
IR_Thermometer_Sensor_MLX90614 MLX90614 = IR_Thermometer_Sensor_MLX90614();

void setup() {
Serial.begin(115200);
  delay(10);
   MLX90614.begin(); 
  // initialize Yun bridge for thinger.io
  Bridge.begin();
  thing["temperature"] >> [](pson& out){out = MLX90614.GetAmbientTemp_Celsius();};

}

void loop() {
  thing.handle();
 
  
}
