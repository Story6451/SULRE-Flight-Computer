#include <Arduino.h>
#include <LPS.h>

class DataReading
{
private:
    /* data */
    LPS ps;
    const int ITER_NO = 1000;
    int altIter;
    float pressure = 0.0; 
    float altitude = 0.0; 
    float temperature = 0.0;
    float altitudeOffset = 0.0;
    float MagnetometerXValue = 0.0;
    float MagnetometerYValue = 0.0;
    float MagnetometerZValue = 0.0;
    float AccelXValue = 0.0;
    float AccelYValue = 0.0;
    float AccelZValue = 0.0;
    float MagnetometerPitch = 0.0;
    float MagnetometerRoll = 0.0;
    float MagnetometerXCalculated = 0.0;
    float MagnetometerYCalculated = 0.0;
    float UncalibratedHeading = 0.0;
public:
    DataReading(/* args */); 
    void AltitudeCalibration();
    void PrintAltitude();
    void ReadAccelerometer();
    void ReadMagnetometer();
    void CalculateHeading();
};

