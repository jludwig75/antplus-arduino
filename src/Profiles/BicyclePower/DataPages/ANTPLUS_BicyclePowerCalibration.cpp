#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerCalibration.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerDefines.h>
#include <ANTPLUS_PrivateDefines.h>

#define CALIBRATIONID_BYTE 1
#define AUTOZEROSTATUS_BYTE 2
#define CALIBRATIONDATA_LSB_BYTE 6
#define CALIBRATIONDATA_MSB_BYTE 7

template<class T>
BicyclePowerBaseCalibration<T>::BicyclePowerBaseCalibration() :
    CoreDataPage<T>() {}

template<class T>
uint8_t BicyclePowerBaseCalibration<T>::getCalibrationID() {
    return this->get8BitValue(CALIBRATIONID_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseCalibration<T>::getAutoZeroStatus() {
    return this->get8BitValue(AUTOZEROSTATUS_BYTE);
}

template<class T>
uint8_t BicyclePowerBaseCalibration<T>::getCalibrationData() {
    return this->get16BitValue(CALIBRATIONDATA_LSB_BYTE, CALIBRATIONDATA_MSB_BYTE);
}

template class BicyclePowerBaseCalibration<BroadcastData>;
template class BicyclePowerBaseCalibration<BroadcastDataMsg>;

BicyclePowerCalibration::BicyclePowerCalibration(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerBaseCalibration() {}

BicyclePowerCalibrationMsg::BicyclePowerCalibrationMsg() :
    BicyclePowerBaseMainDataPageMsg(BICYCLEPOWER_GENERALCALIBRATION_NUMBER),
    BicyclePowerBaseCalibration<BroadcastDataMsg>() {
    set8BitValue(0xFF, 2);
    set8BitValue(0xFF, 3);
    set8BitValue(0xFF, 4);
    set8BitValue(0xFF, 5);
}

void BicyclePowerCalibrationMsg::setCalibrationID(uint8_t calibrationID) {
    set8BitValue(calibrationID, CALIBRATIONID_BYTE);
}

void BicyclePowerCalibrationMsg::setAutoZeroStatus(uint8_t autoZeroStatus) {
    set8BitValue(autoZeroStatus, AUTOZEROSTATUS_BYTE);
}

void BicyclePowerCalibrationMsg::setCalibrationData(uint16_t calibrationData) {
    set16BitValue(calibrationData, CALIBRATIONDATA_LSB_BYTE, CALIBRATIONDATA_MSB_BYTE);
}
