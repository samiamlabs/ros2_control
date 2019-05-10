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

#ifndef HARDWARE_INTERFACE__JOINT_COMMAND_HANDLE_HPP_
#define HARDWARE_INTERFACE__JOINT_COMMAND_HANDLE_HPP_

#include <string>

#include "hardware_interface/visibility_control.h"

#include "types/hardware_interface_return_values.hpp"

namespace hardware_interface
{
/** A handle used to read the state of a single joint. */
class JointCommandHandle
{
public:
  HARDWARE_INTERFACE_PUBLIC
  JointCommandHandle();

  /**
   * The commmand handles are passive in terms of ownership.
   * That means that the handles are only allowed to read/write
   * the storage, however are not allowed to delete or reallocate
   * this memory.
   * \param name The name of the joint
   * \param cmd A pointer to the storage for this joint's command
   */
  HARDWARE_INTERFACE_PUBLIC
  JointCommandHandle(
    const std::string & name,
    double * pos,
    double * vel,
    double * eff);

  HARDWARE_INTERFACE_PUBLIC
  const std::string &
  get_name() const;

  HARDWARE_INTERFACE_PUBLIC
  double
  get_position() const;

  HARDWARE_INTERFACE_PUBLIC
  double
  get_velocity() const;

  HARDWARE_INTERFACE_PUBLIC
  double
  get_effort() const;

  HARDWARE_INTERFACE_PUBLIC
  void
  set_position(double pos);

  HARDWARE_INTERFACE_PUBLIC
  void
  set_velocity(double vel);

  HARDWARE_INTERFACE_PUBLIC
  void
  set_effort(double );

private:
  std::string name_;
  double * pos_;
  double * vel_;
  double * eff_;
};

}  // namespace hardware_interface

#endif  // HARDWARE_INTERFACE__JOINT_COMMAND_HANDLE_HPP_
