/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef _NPS_BEAM_PLUGIN_HH_
#define _NPS_BEAM_PLUGIN_HH_

#include <string>

#include "gazebo/common/Plugin.hh"
//#include "gazebo/sensors/CameraSensor.hh"
#include "gazebo/rendering/RenderTypes.hh"
#include "gazebo/util/system.hh"



namespace gazebo
{

  // define these because Gazebo doesn't have them yet, see SensorTypes.hh
  namespace sensors
  {
    class NpsBeamSensor;

    /// \def NpsBeamSensorPtr
    /// \brief Shared pointer to NpsBeamSensor
    typedef std::shared_ptr<NpsBeamSensor> NpsBeamSensorPtr;

    /// \def GpuRaySensor_V
    /// \brief Vector of GpuRaySensor shared pointers
    typedef std::vector<NpsBeamSensorPtr> NpsBeamSensor_V;

    // and for sensor noise type, maybe for now try GPU_RAY_NOISE
  }

  class GAZEBO_VISIBLE NpsBeamPlugin : public SensorPlugin
  {
    public: NpsBeamPlugin();

    public: void Load(sensors::SensorPtr _sensor, sdf::ElementPtr _sdf);

    public: virtual void OnNewLaserFrame(const float *_image,
                unsigned int _width, unsigned int _height,
                unsigned int _depth, const std::string &_format);

    protected: unsigned int width, height/*, depth*/;

    protected: sensors::NpsBeamSensorPtr parentSensor;

    private: event::ConnectionPtr newLaserFrameConnection;
  };
}
#endif
