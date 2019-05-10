// Copyright 2017 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "hardware_interface/joint_command_handle.hpp"

#include <stdexcept>
#include <string>

#include "hardware_interface/macros.hpp"

namespace hardware_interface
{

JointCommandHandle::JointCommandHandle()
: name_(),
  pos_(nullptr),
  vel_(nullptr),
  eff_(nullptr)
{}

JointCommandHandle::JointCommandHandle(
  const std::string & name,
  double * pos,
  double * vel,
  double * eff)
: name_(name), pos_(pos), vel_(vel), eff_(eff)
{
  THROW_ON_NULLPTR(pos)
  THROW_ON_NULLPTR(vel)
  THROW_ON_NULLPTR(eff)
}

const std::string &
JointCommandHandle::get_name() const
{
  return name_;
}

double
JointCommandHandle::get_position() const
{
  THROW_ON_NULLPTR(pos_)

  return *pos_;
}

void
JointCommandHandle::set_position(double pos)
{
  THROW_ON_NULLPTR(pos_)

  * pos_ = pos;
}

double
JointCommandHandle::get_velocity() const
{
  THROW_ON_NULLPTR(vel_)

  return *vel_;
}

void
JointCommandHandle::set_velocity(double vel)
{
  THROW_ON_NULLPTR(vel_)

  * vel_ = vel;
}

double
JointCommandHandle::get_effort() const
{
  THROW_ON_NULLPTR(eff_)

  return *eff_;
}

void
JointCommandHandle::set_effort(double eff)
{
  THROW_ON_NULLPTR(eff_)

  * eff_ = eff;
}


}  // namespace hardware_interface
