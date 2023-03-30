#pragma once

// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: Czech Technical University in Prague

/**
 * \file
 * \brief Use this message type to allocate messages' buffers (vectors) from a shared pool of memory. That should
 * result in lower cost of frequent allocations. However, the effect should always be checked in practice - in many
 * applications, the pool-allocated messages can actually degrade performance.
 * 
 * \note Please note that these messages are incompatible with the normally defined messages and the subscribers have to
 * directly subscribe this alternative type. If they subscribe using the type with the default allocator, a
 * serialization and deserialization step is performed to "convert" the messages - even when the publisher and
 * subscriber are in the same node(let). See https://gist.github.com/peci1/be78ffea761e38cdbeeca4e2c961c702 .
 * 
 * \note To keep the dependencies of this package sane, it is the responsibility of the downstream packages to find and
 * include Boost and sensor_msgs when using this header.
 * 
 * \author Martin Pecka
 */

#include <boost/pool/pool_alloc.hpp>

#include <sensor_msgs/BatteryState.h>
#include <sensor_msgs/CameraInfo.h>
#include <sensor_msgs/ChannelFloat32.h>
#include <sensor_msgs/CompressedImage.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/JointState.h>
#include <sensor_msgs/Joy.h>
#include <sensor_msgs/JoyFeedback.h>
#include <sensor_msgs/JoyFeedbackArray.h>
#include <sensor_msgs/LaserEcho.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/MultiDOFJointState.h>
#include <sensor_msgs/MultiEchoLaserScan.h>
#include <sensor_msgs/PointCloud.h>
#include <sensor_msgs/PointCloud2.h>

#include <ros/message_forward.h>

namespace sensor_msgs  // we cannot change the namespace to cras_msgs :(
{
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(BatteryState, BatteryStatePoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(CameraInfo, CameraInfoPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(ChannelFloat32, ChannelFloat32PoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(CompressedImage, CompressedImagePoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(Image, ImagePoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(JointState, JointStatePoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(Joy, JoyPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(JoyFeedback, JoyFeedbackPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(JoyFeedbackArray, JoyFeedbackArrayPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(LaserEcho, LaserEchoPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(LaserScan, LaserScanPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(MultiDOFJointState, MultiDOFJointStatePoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(MultiEchoLaserScan, MultiEchoLaserScanPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(PointCloud, PointCloudPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(PointCloud2, PointCloud2PoolAllocated, boost::pool_allocator)
}