//******************************************************************
//
// Copyright 2015 Samsung Electronics All Rights Reserved.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
#ifndef __EASYSETUP_MGR_H_
#define __EASYSETUP_MGR_H_

#include <string.h>

#include "logger.h"
#include "ocstack.h"
#include "octypes.h"
#include "common.h"

#include "provisioninghandler.h"


//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------

#ifdef __cplusplus
extern "C" {
#endif
OCStackResult InitEasySetupManager();

OCStackResult TerminateEasySetupManager();

OCStackResult RegisterProvisioningStausCallback(
        OCProvisioningStatusCB provisioningStatusCallback);

void UnRegisterProvisioningStausCallback();

OCStackResult ProvisionEnrollee(const EnrolleeNWProvInfo_t *netInfo);

OCStackResult StopEnrolleeProvisioning(OCConnectivityType connectivityType);

#ifdef __cplusplus
}
#endif

#endif
