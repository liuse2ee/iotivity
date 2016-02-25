/* ****************************************************************
 *
 * Copyright 2016 Samsung Electronics All Rights Reserved.
 *
 *
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************/

#include "camanagerleinterface.h"
#include "cautilinterface.h"

#include "cacommon.h"
#include "logger.h"

#define TAG "OIC_CA_UTIL_INF"

CAResult_t CARegisterNetworkMonitorHandler(CAAdapterStateChangedCB adapterStateCB,
                                           CAConnectionStateChangedCB connStateCB)
{
    OIC_LOG(DEBUG, TAG, "CARegisterNetworkMonitorHandler");

#ifdef LE_ADAPTER
    CASetLENetworkMonitorCallbacks(adapterStateCB, connStateCB);
    return CA_STATUS_OK;
#else
    return CA_NOT_SUPPORTED;
#endif

}

CAResult_t CASetAutoConnectionDeviceInfo(const char *address)
{
    OIC_LOG(DEBUG, TAG, "CASetAutoConnectionDeviceInfo");

#ifdef LE_ADAPTER
    return CASetLEClientAutoConnectionDeviceInfo(address);
#else
    return CA_NOT_SUPPORTED;
#endif
}

CAResult_t CAUnsetAutoConnectionDeviceInfo(const char *address)
{
    OIC_LOG(DEBUG, TAG, "CAUnsetAutoConnectionDeviceInfo");

#ifdef LE_ADAPTER
    return CAUnsetLEClientAutoConnectionDeviceInfo(address);
#else
    return CA_NOT_SUPPORTED;
#endif
}
