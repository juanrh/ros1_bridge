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

#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include <stdio.h> // FIXME 

// include rcl interfaces
#include "ros1_bridge/rcl_interfaces_factories.hpp"
#include "ros1_bridge/convert_builtin_interfaces.hpp"

namespace ros1_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_rcl_interfaces(
  const std::string & ros1_type_name,
  const std::string & ros2_type_name)
{
  if (
    (ros1_type_name == "rosgraph_msgs/Log" || ros1_type_name == "") &&
    ros2_type_name == "rcl_interfaces/Log")
  {
    return std::make_shared<
      Factory<
        rosgraph_msgs::Log,
        rcl_interfaces::msg::Log
      >
    >("rosgraph_msgs/Log", ros2_type_name);
  }
  return std::shared_ptr<FactoryInterface>();
}

template<>
void
Factory<
  rosgraph_msgs::Log,
  rcl_interfaces::msg::Log
>::convert_1_to_2(
  const rosgraph_msgs::Log & ros1_msg,
  rcl_interfaces::msg::Log & ros2_msg)
{
  ros1_bridge::convert_1_to_2(ros1_msg.header.stamp, ros2_msg.stamp);
  // ros2_msg.level = ros1_msg.level; // FIXME this doesn't work 
  ros2_msg.level = rcl_interfaces::msg::Log::INFO;
  ros2_msg.name = ros1_msg.name;
  ros2_msg.msg = ros1_msg.msg;
  ros2_msg.file = ros1_msg.file;
  ros2_msg.function = ros1_msg.function;
  ros2_msg.line = ros1_msg.line;

  std::cout << "Converted to rcl_interfaces::msg::Log with "
    << "stamp=[(" << ros2_msg.stamp.sec << ", " << ros2_msg.stamp.nanosec << ")"
    << "], level=[" << ros2_msg.level 
    << "], name=[" << ros2_msg.name << "]"
    << "], msg=[" << ros2_msg.msg << "]"
    << "], file=[" << ros2_msg.file << "]"
    << "], function=[" << ros2_msg.function << "]"
    << "], line=[" << ros2_msg.line << "]"
    << std::endl;
}

template<>
void
Factory<
  rosgraph_msgs::Log,
  rcl_interfaces::msg::Log
>::convert_2_to_1(
  const rcl_interfaces::msg::Log & ros2_msg,
  rosgraph_msgs::Log & ros1_msg)
{
  ros1_bridge::convert_2_to_1(ros2_msg.stamp, ros1_msg.header.stamp);
  ros1_msg.level = ros2_msg.level;
  ros1_msg.name = ros2_msg.name.c_str();
  ros1_msg.msg = ros2_msg.msg;
  ros1_msg.file = ros2_msg.file;
  ros1_msg.function = ros2_msg.function;
  ros1_msg.line = ros2_msg.line;

    std::cout << "Converted to rosgraph_msgs::Log with "
    << "header.seq=[" << ros1_msg.header.seq 
    << "], header.stamp=[(" << ros1_msg.header.stamp.sec << ", " << ros1_msg.header.stamp.nsec << ")"
    << "], header.frame_id=[" << ros1_msg.header.frame_id 
    << "], level=[" << ros1_msg.level 
    << "], name=[" << ros1_msg.name << "]"
    << "], msg=[" << ros1_msg.msg << "]"
    << "], file=[" << ros1_msg.file << "]"
    << "], function=[" << ros1_msg.function << "]"
    << "], line=[" << ros1_msg.line << "]"
    << "], topics.size=[" << ros1_msg.topics.size() << "]"
    << std::endl;
}

}  // namespace ros1_bridge
