/*
 * Copyright 2019 Open Source Robotics Foundation
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

#include <thread>

#include <gazebo/common/Time.hh>
#include <gazebo/gazebo_client.hh>
#include <gazebo/msgs/msgs.hh>
#include <gazebo/transport/transport.hh>
#include <ros/ros.h>

// Run all the tests that were declared with TEST()
int main(int argc, char **argv){
  ros::init(argc, argv, "shutdown_gz");
  ros::NodeHandle nh;

  gazebo::client::setup(0, nullptr);
  gazebo::transport::NodePtr node(new gazebo::transport::Node());
  node->Init();

  auto pub = node->Advertise<gazebo::msgs::ServerControl>("/gazebo/server/control");
  pub->WaitForConnection();

  // Send a message to stop the server
  gazebo::msgs::ServerControl msg;
  msg.set_stop(true);
  pub->Publish(msg);
  gazebo::client::shutdown();
  return 0;
}
