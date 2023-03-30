// SPDX-License-Identifier: BSD-3-Clause
// SPDX-FileCopyrightText: Czech Technical University in Prague

/**
 * \file
 * \brief Unit test for pool_allocated_sensor_msgs.h.
 * \author Martin Pecka
 */

#include "sensor_msgs/LaserEcho.h"
#include "sensor_msgs/MultiEchoLaserScan.h"
#include "gtest/gtest.h"

#include <vector>

#include <boost/pool/pool_alloc.hpp>

#include <geometry_msgs/Twist.h>

#include <cras_msgs/pool_allocated_sensor_msgs.h>

template<typename T>
size_t byte_size(const typename std::vector<T>& vec)
{
  return sizeof(T) * vec.size();
}

TEST(PoolAllocated, BatteryState)
{
  sensor_msgs::BatteryState msg;
  msg.header.frame_id = "test";
  msg.cell_voltage.resize(10, 1.0);

  sensor_msgs::BatteryStatePoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.cell_voltage.resize(10, 1.0);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.cell_voltage), typeid(poolMsg.cell_voltage));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.cell_voltage.size(), poolMsg.cell_voltage.size());
  EXPECT_EQ(0, memcmp(msg.cell_voltage.data(), poolMsg.cell_voltage.data(), byte_size(msg.cell_voltage)));
  EXPECT_NE(msg.cell_voltage.data(), poolMsg.cell_voltage.data());
}

TEST(PoolAllocated, CameraInfo)
{
  sensor_msgs::CameraInfo msg;
  msg.header.frame_id = "test";
  msg.D.resize(10, 1.0);

  sensor_msgs::CameraInfoPoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.D.resize(10, 1.0);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.D), typeid(poolMsg.D));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.D.size(), poolMsg.D.size());
  EXPECT_EQ(0, memcmp(msg.D.data(), poolMsg.D.data(), byte_size(msg.D)));
  EXPECT_NE(msg.D.data(), poolMsg.D.data());
}

TEST(PoolAllocated, ChannelFloat32)
{
  sensor_msgs::ChannelFloat32 msg;
  msg.name = "test";
  msg.values.resize(10, 1u);

  sensor_msgs::ChannelFloat32PoolAllocated poolMsg;
  poolMsg.name = "test";
  poolMsg.values.resize(10, 1u);

  EXPECT_NE(typeid(msg.name), typeid(poolMsg.name));
  EXPECT_NE(typeid(msg.values), typeid(poolMsg.values));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.name.c_str(), poolMsg.name.c_str());
  EXPECT_NE(msg.name.c_str(), poolMsg.name.c_str());

  // Check that the binary content is the same, but the pointers are different
  EXPECT_EQ(0, memcmp(msg.values.data(), poolMsg.values.data(), byte_size(msg.values)));
  EXPECT_NE(msg.values.data(), poolMsg.values.data());
}

TEST(PoolAllocated, CompressedImage)
{
  sensor_msgs::CompressedImage msg;
  msg.header.frame_id = "test";
  msg.data.resize(10, 1u);

  sensor_msgs::CompressedImagePoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.data.resize(10, 1u);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.data), typeid(poolMsg.data));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.data.size(), poolMsg.data.size());
  EXPECT_EQ(0, memcmp(msg.data.data(), poolMsg.data.data(), byte_size(msg.data)));
  EXPECT_NE(msg.data.data(), poolMsg.data.data());
}

TEST(PoolAllocated, Image)
{
  sensor_msgs::Image msg;
  msg.header.frame_id = "test";
  msg.data.resize(10, 1u);

  sensor_msgs::ImagePoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.data.resize(10, 1u);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.data), typeid(poolMsg.data));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.data.size(), poolMsg.data.size());
  EXPECT_EQ(0, memcmp(msg.data.data(), poolMsg.data.data(), byte_size(msg.data)));
  EXPECT_NE(msg.data.data(), poolMsg.data.data());
}

TEST(PoolAllocated, JointState)
{
  sensor_msgs::JointState msg;
  msg.header.frame_id = "test";
  msg.position.resize(10, 1.0);

  sensor_msgs::JointStatePoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.position.resize(10, 1.0);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.position), typeid(poolMsg.position));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.position.size(), poolMsg.position.size());
  EXPECT_EQ(0, memcmp(msg.position.data(), poolMsg.position.data(), byte_size(msg.position)));
  EXPECT_NE(msg.position.data(), poolMsg.position.data());
}

TEST(PoolAllocated, Joy)
{
  sensor_msgs::Joy msg;
  msg.header.frame_id = "test";
  msg.axes.resize(10, 1.0f);

  sensor_msgs::JoyPoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.axes.resize(10, 1.0f);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.axes), typeid(poolMsg.axes));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.axes.size(), poolMsg.axes.size());
  EXPECT_EQ(0, memcmp(msg.axes.data(), poolMsg.axes.data(), byte_size(msg.axes)));
  EXPECT_NE(msg.axes.data(), poolMsg.axes.data());
}

TEST(PoolAllocated, JoyFeedbackArray)
{
  sensor_msgs::JoyFeedbackArray msg;
  msg.array.resize(10, sensor_msgs::JoyFeedback());

  sensor_msgs::JoyFeedbackArrayPoolAllocated poolMsg;
  poolMsg.array.resize(10, sensor_msgs::JoyFeedbackPoolAllocated());

  EXPECT_NE(typeid(msg.array), typeid(poolMsg.array));

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.array.size(), poolMsg.array.size());
  for (size_t i = 0; i < msg.array.size(); ++i)
    EXPECT_EQ(msg.array[i], poolMsg.array[i]);
  EXPECT_NE(static_cast<void*>(msg.array.data()), static_cast<void*>(poolMsg.array.data()));
}

TEST(PoolAllocated, LaserEcho)
{
  sensor_msgs::LaserEcho msg;
  msg.echoes.resize(10, 1.0f);

  sensor_msgs::LaserEchoPoolAllocated poolMsg;
  poolMsg.echoes.resize(10, 1.0f);

  EXPECT_NE(typeid(msg.echoes), typeid(poolMsg.echoes));

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.echoes.size(), poolMsg.echoes.size());
  EXPECT_EQ(0, memcmp(msg.echoes.data(), poolMsg.echoes.data(), byte_size(msg.echoes)));
  EXPECT_NE(msg.echoes.data(), poolMsg.echoes.data());
}

TEST(PoolAllocated, LaserScan)
{
  sensor_msgs::LaserScan msg;
  msg.header.frame_id = "test";
  msg.ranges.resize(10, 1.0f);

  sensor_msgs::LaserScanPoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.ranges.resize(10, 1.0f);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.ranges), typeid(poolMsg.ranges));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.ranges.size(), poolMsg.ranges.size());
  EXPECT_EQ(0, memcmp(msg.ranges.data(), poolMsg.ranges.data(), byte_size(msg.ranges)));
  EXPECT_NE(msg.ranges.data(), poolMsg.ranges.data());
}

TEST(PoolAllocated, MultiDOFJointState)
{
  sensor_msgs::MultiDOFJointState msg;
  msg.header.frame_id = "test";
  msg.twist.resize(10, geometry_msgs::Twist());

  sensor_msgs::MultiDOFJointStatePoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.twist.resize(10, geometry_msgs::Twist_<boost::pool_allocator<void>>());

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.twist), typeid(poolMsg.twist));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.twist.size(), poolMsg.twist.size());
  EXPECT_EQ(0, memcmp(msg.twist.data(), poolMsg.twist.data(), byte_size(msg.twist)));
  EXPECT_NE(static_cast<void*>(msg.twist.data()), static_cast<void*>(poolMsg.twist.data()));
}

TEST(PoolAllocated, MultiEchoLaserScan)
{
  sensor_msgs::MultiEchoLaserScan msg;
  msg.header.frame_id = "test";
  msg.ranges.resize(10, sensor_msgs::LaserEcho());

  sensor_msgs::MultiEchoLaserScanPoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.ranges.resize(10, sensor_msgs::LaserEchoPoolAllocated());

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.ranges), typeid(poolMsg.ranges));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.ranges.size(), poolMsg.ranges.size());
  EXPECT_EQ(0, memcmp(msg.ranges.data(), poolMsg.ranges.data(), byte_size(msg.ranges)));
  EXPECT_NE(static_cast<void*>(msg.ranges.data()), static_cast<void*>(poolMsg.ranges.data()));
}

TEST(PoolAllocated, PointCloud)
{
  sensor_msgs::PointCloud msg;
  msg.header.frame_id = "test";
  msg.points.resize(10, {});

  sensor_msgs::PointCloudPoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.points.resize(10, {});

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.points), typeid(poolMsg.points));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.points.size(), poolMsg.points.size());
  EXPECT_EQ(0, memcmp(msg.points.data(), poolMsg.points.data(), byte_size(msg.points)));
  EXPECT_NE(static_cast<void*>(msg.points.data()), static_cast<void*>(poolMsg.points.data()));
}

TEST(PoolAllocated, PointCloud2)
{
  sensor_msgs::PointCloud2 msg;
  msg.header.frame_id = "test";
  msg.data.resize(10, 1u);

  sensor_msgs::PointCloud2PoolAllocated poolMsg;
  poolMsg.header.frame_id = "test";
  poolMsg.data.resize(10, 1u);

  EXPECT_NE(typeid(msg.header.frame_id), typeid(poolMsg.header.frame_id));
  EXPECT_NE(typeid(msg.data), typeid(poolMsg.data));

  // Check that string contents are the same, but the pointers are different
  EXPECT_STREQ(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());
  EXPECT_NE(msg.header.frame_id.c_str(), poolMsg.header.frame_id.c_str());

  // Check that the binary content is the same, but the pointers are different
  ASSERT_EQ(msg.data.size(), poolMsg.data.size());
  EXPECT_EQ(0, memcmp(msg.data.data(), poolMsg.data.data(), byte_size(msg.data)));
  EXPECT_NE(msg.data.data(), poolMsg.data.data());
}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
