#ifndef CAR_H
#define CAR_H

#include <cstdint>
#include <cstdio>
#include <cerrno>
#include <unistd.h>
#include <thread>
#include <modbus.h>

#define WHEEL_RADIUS (64.0f) //Wheel radius in mm
#define AXLE_LENGTH (310.0f) //Axle effective length in mm
#define CAR_LENGTH (640.0f) //Axle effective length in mm
#define SEND_DELAY (8000)
#define PI (3.14159265359f)

class Car
{
private:
    std::thread *carComm_t;
    modbus_t *modbus_ctx;
    const float wheel_circumference = 2.0f * WHEEL_RADIUS * PI; //Wheel's Circumference in mm
                                                                // int16_t V = 0;  //Car Linear Velocity (mm/s)
                                                                // float W = 0.0;  //Car Angular Velocity (1000*rad/s)
    float Vl = 0.0;                                             //Left Wheel Velocity (mm/s)
    float Vr = 0.0;                                             //Right Wheel Velocity (mm/s)
    float RPML = 0;                                             // Auctal Velocity of Left Wheel (RPM)
    float RPMR = 0;                                             // Auctal Velocity of Right Wheel (RPM)
    bool setFlag = false;
    float VBat = 0.0;    

    int16_t convertToRPM(float v);
    void run();
    void getRPM();
    void carComm(void);

public:
    Car(/* args */);
    ~Car();
    void setParams(int16_t V, float W);
    void enableDrivers(void);
    void disableDrivers(void);
    void clearError(void);
    float getDriverVoltage(void);
};

#endif