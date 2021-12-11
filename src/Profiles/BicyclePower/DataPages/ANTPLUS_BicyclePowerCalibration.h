#ifndef ANTPLUS_BICYCLEPOWERCALIBRATION_h
#define ANTPLUS_BICYCLEPOWERCALIBRATION_h

#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>

template<class T>
class BicyclePowerBaseCalibration : virtual public CoreDataPage<T> {
public:
    BicyclePowerBaseCalibration();
    uint8_t getCalibrationID();
    uint8_t getAutoZeroStatus();
    uint8_t getCalibrationData();
};

class BicyclePowerCalibration :
    public BicyclePowerBaseMainDataPage,
    public BicyclePowerBaseCalibration<BroadcastData> {
public:
    explicit BicyclePowerCalibration(AntRxDataResponse& dp);
};

class BicyclePowerCalibrationMsg :
    public BicyclePowerBaseMainDataPageMsg,
    public BicyclePowerBaseCalibration<BroadcastDataMsg> {
public:
    explicit BicyclePowerCalibrationMsg();
    void setCalibrationID(uint8_t calibrationID);
    void setAutoZeroStatus(uint8_t autoZeroStatus);
    void setCalibrationData(uint16_t calibrationData);
};

#endif // ANTPLUS_BICYCLEPOWERCALIBRATION_h
