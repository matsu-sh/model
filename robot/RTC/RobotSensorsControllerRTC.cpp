/**
   Sample Robot motion controller for the JVRC robot model.
   This program was ported from the "SR1WalkControllerRTC.cpp" sample of
   Choreonoid.
*/

#include "RobotSensorsControllerRTC.h"
#include <cnoid/BodyMotion>
#include <cnoid/ExecutablePath>
#include <cnoid/FileUtil>
#include <iostream>

using namespace std;
using namespace cnoid;

namespace {

const char* samplepd_spec[] =
{
    "implementation_id", "RobotSensorsControllerRTC",
    "type_name",         "RobotSensorsControllerRTC",
    "description",       "Robot Controller component",
    "version",           "0.1",
    "vendor",            "AIST",
    "category",          "Generic",
    "activity_type",     "DataFlowComponent",
    "max_instance",      "10",
    "language",          "C++",
    "lang_type",         "compile",
    ""
};
}


RobotSensorsControllerRTC::RobotSensorsControllerRTC(RTC::Manager* manager)
    : RTC::DataFlowComponentBase(manager),
      m_angleIn("q", m_angle),
      m_gsensorIn("gsensor", m_gsensor),
      m_gyrometerIn("gyrometer", m_gyrometer)
{

}

RobotSensorsControllerRTC::~RobotSensorsControllerRTC()
{

}


RTC::ReturnCode_t RobotSensorsControllerRTC::onInitialize()
{
    // Set InPort buffers
    addInPort("q", m_angleIn);
    addInPort("gsensor", m_gsensorIn);
    addInPort("gyrometer", m_gyrometerIn);

    return RTC::RTC_OK;
}

RTC::ReturnCode_t RobotSensorsControllerRTC::onActivated(RTC::UniqueId ec_id)
{
    return RTC::RTC_OK;
}


RTC::ReturnCode_t RobotSensorsControllerRTC::onDeactivated(RTC::UniqueId ec_id)
{
    return RTC::RTC_OK;
}

RTC::ReturnCode_t RobotSensorsControllerRTC::onExecute(RTC::UniqueId ec_id)
{
    if(m_angleIn.isNew()){
        m_angleIn.read();
    }

    for(size_t i=0; i < m_angle.data.length(); ++i){
            cout << "m_angle.data[" << i << "] is " << m_angle.data[i] << std::endl;
    }

    if(m_gsensorIn.isNew()){
        m_gsensorIn.read();
    }

    for(size_t i=0; i < m_gsensor.data.length(); ++i){
            cout << "m_gsensorIn.data[" << i << "] is " << m_gsensor.data[i] << std::endl;
    }

    if(m_gyrometerIn.isNew()){
        m_gyrometerIn.read();
    }

    for(size_t i=0; i < m_gyrometer.data.length(); ++i){
            cout << "m_gyrometerIn.data[" << i << "] is " << m_gyrometer.data[i] << std::endl;
    }

    return RTC::RTC_OK;
}


extern "C"
{
    DLL_EXPORT void RobotSensorsControllerRTCInit(RTC::Manager* manager)
    {
        coil::Properties profile(samplepd_spec);
        manager->registerFactory(profile,
                                 RTC::Create<RobotSensorsControllerRTC>,
                                 RTC::Delete<RobotSensorsControllerRTC>);
    }
};
