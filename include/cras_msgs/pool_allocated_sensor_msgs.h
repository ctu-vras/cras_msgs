#pragma once

#include <boost/pool/pool_alloc.hpp>

#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/PointCloud2.h>

#include <ros/message_forward.h>

//! Use this message type to allocate messages' buffers (vectors) from a shared pool of memory,
//! which should result in much lower cost of frequent allocations.

namespace sensor_msgs // we cannot change the namespace to cras_msgs :(
{
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(LaserScan, LaserScanPoolAllocated, boost::pool_allocator)
ROS_DECLARE_MESSAGE_WITH_ALLOCATOR(PointCloud2, PointCloud2PoolAllocated, boost::pool_allocator)
}