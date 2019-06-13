#ifndef ANTPLUS_MUSCLEOXYGENPROFILEPRIVATEDEFINES_h
#define ANTPLUS_MUSCLEOXYGENPROFILEPRIVATEDEFINES_h

/* Channel Config */
#define ANTPLUS_MUSCLEOXYGEN_CHANNELTYPE CHANNEL_TYPE_BIDIRECTIONAL_RECEIVE 
#define ANTPLUS_MUSCLEOXYGEN_DEVICETYPE 31
#define ANTPLUS_MUSCLEOXYGEN_CHANNELPERIOD 8192
// Master channel
#define ANTPLUS_MUSCLEOXYGEN_MASTER_CHANNELTYPE 0x10 
#define ANTPLUS_MUSCLEOXYGEN_MASTER_TRANSMISSIONTYPE 5
#define ANTPLUS_MUSCLEOXYGEN_MASTER_DEVICENUMBER 5

// 30 / 2.5 = 12
#define ANTPLUS_MUSCLEOXYGEN_SEARCHTIMEOUT 12

/* Pages */
#define ANTPLUS_MUSCLEOXYGEN_DATAPAGE_MUSCLEOXYGENDATA 1

// Base page */
#define ANTPLUS_MUSCLEOXYGEN_DATAPAGEBASE_DATAPAGE_BYTE 0x00


#endif // ANTPLUS_MUSCLEOXYGENPROFILEPRIVATEDEFINES_h
