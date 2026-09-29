#pragma once

#include "typedef.h"

#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @brief Create an DexCap Suit instance of V4
 * @param hSuit Output argument, a pointer to address of DexCap Suit instance handle.
 * @param adapterType Input. Indicate the adapter type of this DexCap Suit you want
 * to use. Allowed values can be WIREDUSB(USB-Serial cable), WLAN80211(via hot point),
 * WLAN_TCP(TCP/UDP via WLAN). All devices connect to this DexCap Suit instance, must
 * be using the same AdapterType, otherwise the connection request will be refused.
 */
DEX_RETURN dexcap_create_suit_instance(DEXCAP_SUIT_HANDLE * hSuit, ADAPTER_TYPE adapterType);

/**
 * @brief Connect a DexCap device to a suit instance, with given device_path.
 * @param hSuit Input. The handle of DexCap Suit instance. It must be created by
 * a call of dexcap_create_suit_instance() first.
 * @param devicePath Input. Represent the DexCap device you want to connect, normally
 * it's a DexCap Glove, or a DexCap ExoSkeleton arms. Given value of this argument must
 * be enumeration path of serial port of this device, or its bluetooth name. It must be
 * matched with the given value of adapter_type when the DexCap Suit instance is created.
 * @param deviceType Output/Input. Once connection of device_path is established, this
 * argument will be evaluated as UpBody/LGLove/RGlove this function, otherwise it will
 * be set as UnDef. However, for IMU, this argument must be explicitly set to "InetMU",
 * otherwise this function will connect it as a common device, and try to retrieve its
 * device type, which will cause a failure.
 */
DEX_RETURN dexcap_connect(DEXCAP_SUIT_HANDLE hSuit, const char * devicePath,
    DEXCAP_DEVICE_TYPE * deviceType);

DEX_RETURN dexcap_disconnect(DEXCAP_SUIT_HANDLE hSuit);
BOOL dexcap_is_device_connected(DEXCAP_SUIT_HANDLE hSuit);

DEX_RETURN dexcap_start_sampling(DEXCAP_SUIT_HANDLE hSuit);
BOOL dexcap_is_sampling_started(DEXCAP_SUIT_HANDLE hSuit);
DEX_RETURN dexcap_stop_sampling(DEXCAP_SUIT_HANDLE hSuit);

DEX_RETURN dexcap_get_status_data(DEXCAP_SUIT_HANDLE hSuit, SuitStatusData *jointData);
DEX_RETURN dexcap_get_main_battery_state(DEXCAP_SUIT_HANDLE hSuit, MainBatteryStatus *batteryState);
DEX_RETURN dexcap_get_system_status(DEXCAP_SUIT_HANDLE hSuit, SystemStatus *sysStatus);

DEX_RETURN register_status_data_callback(DEXCAP_SUIT_HANDLE hSuit, DexCapSuitDataProc callback);

DEX_RETURN dexcap_get_diagnostics(DEXCAP_SUIT_HANDLE hSuit,
    ErrorCode *errCode,
    char *errMsg,
    size_t errMsgLen,
    size_t *actualErrMsgLen);

#ifdef __cplusplus
}
#endif