/*
* If not stated otherwise in this file or this component's LICENSE file the
* following copyright and licenses apply:
*
* Copyright 2022 Sky UK
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
* http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

#include <string>
#include "ControlSettingsTV.h"

namespace WPEFramework {
namespace Plugin {

    ControlSettingsTV::ControlSettingsTV(): AbstractPlugin(3)
    {
        LOGINFO("Entry\n");
        instance = this;
        registerMethod("getBacklight", &ControlSettingsTV::getBacklight, this, {1});
        registerMethod("setBacklight", &ControlSettingsTV::setBacklight, this, {1});	
        LOGINFO("Exit\n");
    }
    
    ControlSettingsTV :: ~ControlSettingsTV()
    {
        LOGINFO();    
    }

    void ControlSettingsTV::Initialize()
    {
       LOGINFO("Entry\n");
       //Space for Device specific Init Sequence
       LOGINFO("Exit\n");
    }

    void ControlSettingsTV::Deinitialize()
    {
       LOGINFO("Entry\n");
       LOGINFO("Exit\n");
    }

    //Event
    void ControlSettingsTV::dsHdmiEventHandler(const char *owner, IARM_EventId_t eventId, void *data, size_t len)
    {
        LOGINFO("Entry %s\n",__FUNCTION__);
        LOGINFO("Exit %s\n",__FUNCTION__);
    }

    uint32_t ControlSettingsTV::getBacklight(const JsonObject& parameters, JsonObject& response)
    {

        LOGINFO("Entry %s\n",__FUNCTION__);
        PLUGIN_Lock(Lock);
        tvError_t ret = tvERROR_NONE;

        if(ret != tvERROR_NONE) {
            returnResponse(false, getErrorString(ret).c_str());
        }
        else {
            LOGINFO("Exit : %s\n",__FUNCTION__);
            returnResponse(true, "success");
        }
    }

    uint32_t ControlSettingsTV::setBacklight(const JsonObject& parameters, JsonObject& response)
    {

        LOGINFO("Entry\n");
        PLUGIN_Lock(Lock);
        tvError_t ret = tvERROR_NONE;

        if(ret != tvERROR_NONE) {
            returnResponse(false, getErrorString(ret).c_str());
        }
        else {
            LOGINFO("Exit : %s\n",__FUNCTION__);
            returnResponse(true, "success");
        }
    }
}//namespace Plugin
}//namespace WPEFramework