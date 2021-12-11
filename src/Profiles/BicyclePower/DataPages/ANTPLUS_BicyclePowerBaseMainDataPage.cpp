#include <Profiles/BicyclePower/DataPages/ANTPLUS_BicyclePowerBaseMainDataPage.h>
#include <Profiles/BicyclePower/ANTPLUS_BicyclePowerPrivateDefines.h>
#include <ANTPLUS_PrivateDefines.h>

// TODO make second base class for callibration messages
#define UPDATEEVENTCOUNT_BYTE 1

BicyclePowerBaseMainDataPage::BicyclePowerBaseMainDataPage(AntRxDataResponse& dp) :
    BaseDataPage<BroadcastData>(dp) {}

uint8_t BicyclePowerBaseMainDataPage::getDataPageNumber() {
    return getData(ANTPLUS_DEFAULT_DATAPAGE_BYTE);
}

uint8_t BicyclePowerBaseMainDataPage::getUpdateEventCount() {
    return getData(UPDATEEVENTCOUNT_BYTE);
}

BicyclePowerBaseMainDataPageMsg::BicyclePowerBaseMainDataPageMsg(uint8_t dataPageNumber) :
    BaseDataPageMsg<BroadcastDataMsg>() {
    setDataBuffer(_buffer);
    set8BitValue(dataPageNumber, ANTPLUS_DEFAULT_DATAPAGE_BYTE);
};


template<class T>
BicyclePowerCalibration<T>::BicyclePowerCalibration() :
    CoreDataPage<T>() {}

template class BicyclePowerCalibration<BroadcastData>;
template class BicyclePowerCalibration<BroadcastDataMsg>;

BicyclePowerCalibrationDataPage::BicyclePowerCalibrationDataPage(AntRxDataResponse& dp) :
    BicyclePowerBaseMainDataPage(dp),
    BicyclePowerCalibration() {}

BicyclePowerCalibrationDataPageMsg::BicyclePowerCalibrationDataPageMsg() :
    BicyclePowerBaseMainDataPageMsg(BICYCLEPOWER_GENERALCALIBRATION_NUMBER),
    BicyclePowerCalibration<BroadcastDataMsg>() {
    this->set8BitValue(0xFF, 2);
    this->set8BitValue(0xFF, 3);
    this->set8BitValue(0xFF, 4);
    this->set8BitValue(0xFF, 5);
}

void BicyclePowerCalibrationDataPageMsg::setCalibrationID(uint8_t calibrationID) {
    set8BitValue(calibrationID, 1);
}

void BicyclePowerCalibrationDataPageMsg::setAutoZeroStatus(uint8_t autoZeroStatus) {
    set8BitValue(autoZeroStatus, 2);
}

void BicyclePowerCalibrationDataPageMsg::setCalibrationData(uint16_t calibrationData) {
    set16BitValue(calibrationData, 6, 7);
}
