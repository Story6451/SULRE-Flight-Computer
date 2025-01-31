#include <Arduino.h>
#include <Wire.h>
#include <DataLogging.h>
#include <DataReading.h>
#include <DataTransmitting.h>
#include <kalman.h>
#include <vector>
#include <cstdint>

DataLogging dataLogger;
DataReading dataReader;
DataTransmitting dataTransmitter;

EKF ekf;

void setup() 
{
  Serial.begin(9600);
  //Wire.begin();
  //dataLogger.Begin();
  //dataReader.Begin();
  dataTransmitter.Begin();
  //ekf.initkalman();
}

void loop() 
{
  std::vector<String> dataNameToSend;
  std::vector<double> dataToSend;
  
  //Accelerometer
  dataReader.ReadAccelerometer();
  dataReader.ReadMagnetometer();
  float aX = dataReader.ReturnAccelerometerX();
  float aY = dataReader.ReturnAccelerometerY();
  float aZ = dataReader.ReturnAccelerometerZ();
  float mX = dataReader.ReturnMagnetometerX();
  float mY = dataReader.ReturnMagnetometerY();
  float mZ = dataReader.ReturnMagnetometerZ();
  dataToSend.push_back(aX);
  dataToSend.push_back(aY);
  dataToSend.push_back(aZ);
  dataToSend.push_back(mX);
  dataToSend.push_back(mY);
  dataToSend.push_back(mZ);
  dataNameToSend.push_back("accelXValue");// = {"accelXValue", "accelYValue", "accelZValue"};
  dataNameToSend.push_back("accelYValue");
  dataNameToSend.push_back("accelZValue");
  dataNameToSend.push_back("magnetometerXValue");
  dataNameToSend.push_back("magnetometerYValue");
  dataNameToSend.push_back("magnetometerZValue");
  //Serial.println(aX);
  dataTransmitter.Transmit(dataNameToSend, dataToSend);
  // Serial.print("Accel X: ");
  // Serial.println(dataReader.ReturnAccelerometerX());

  // Serial.print("Accel Y: ");
  // Serial.println(dataReader.ReturnAccelerometerY());

  // Serial.print("Accel Z: ");
  // Serial.println(dataReader.ReturnAccelerometerZ());
  //dataTransmitter.Transmit(dataNameToSend, dataToSend);
  // Serial.print("Magnetic Field Strength X: ");
  // Serial.println(dataReader.ReturnMagnetometerX());

  // Serial.print("Magnetic Field Strength Y: ");
  // Serial.println(dataReader.ReturnMagnetometerY());

  // Serial.print("Magnetic Field Strength Z: ");
  // Serial.println(dataReader.ReturnMagnetometerZ());

  // //Baro
  // dataReader.ReadBarometer();

  // Serial.print("Baro Altitude: ");
  // Serial.println(dataReader.ReturnAltitude());

  // Serial.print("Pressure: ");
  // Serial.println(dataReader.ReturnPressure());

  // Serial.print("Temperature: ");
  // Serial.println(dataReader.ReturnTemperature());

  // float accel = -dataReader.ReturnAccelerometerX();
  // ekf.predict(accel);

  // ekf.updateBaro(dataReader.ReturnAltitude());

  // Serial.print("Kalman Position: ");
  // Serial.println(ekf.getKalmanPosition());

  // Serial.println();
  
  //Serial.println("test");
  //delay(100);
  /*
  dataReader.ReadGPSStream();
  dataReader.GPSStreamToData();

  Serial.print("Latitude: "); Serial.print(dataReader.ReturnLatitude()); Serial.print(" ");
  Serial.print("Longitude: "); Serial.print(dataReader.ReturnLongitude()); Serial.print(" ");
  Serial.print("Altitude: "); Serial.print(dataReader.ReturnAltitude()); Serial.print(" ");
  Serial.print("Velocity: "); Serial.print(dataReader.ReturnGPSVelocity()); Serial.print(" ");
  Serial.print("Number of Satellites: "); Serial.print(dataReader.ReturnSatellitesConnected()); Serial.println(" ");

  */
  Serial.println(dataTransmitter.ReadLoRa());
}
