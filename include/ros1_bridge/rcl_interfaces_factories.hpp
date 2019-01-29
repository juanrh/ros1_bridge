// Copyright 2018 Open Source Robotics Foundation, Inc.
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

#ifndef ROS1_BRIDGE__RCL_INTERFACES_FACTORIES_HPP_
#define ROS1_BRIDGE__RCL_INTERFACES_FACTORIES_HPP_

// include ROS 1 messages
#include <rosgraph_msgs/Log.h>

// include ROS 2 messages
#include <rcl_interfaces/msg/log.hpp>

#include "ros1_bridge/factory.hpp"

namespace ros1_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_rcl_interfaces(
  const std::string & ros1_type_name,
  const std::string & ros2_type_name);

// conversion functions for available interfaces

template<>
void
Factory<
  rosgraph_msgs::Log,
  rcl_interfaces::msg::Log
>::convert_1_to_2(
  const rosgraph_msgs::Log & ros1_msg,
  rcl_interfaces::msg::Log & ros2_msg);

template<>
void
Factory<
  rosgraph_msgs::Log,
  rcl_interfaces::msg::Log
>::convert_2_to_1(
  const rcl_interfaces::msg::Log & ros2_msg,
  rosgraph_msgs::Log & ros1_msg);

} // namespace ros1_bridge


#endif  // ROS1_BRIDGE__RCL_INTERFACES_FACTORIES_HPP_