# cras_msgs

Common ROS messages used by [Center for Robotics and Autonomous Systems (CRAS)](https://robotics.fel.cvut.cz/cras/) at [Faculty of Electrical Engineering](https://fel.cvut.cz/) of [Czech Technical University in Prague](https://www.cvut.cz).

Parts of this package were used by [team CTU-CRAS-Norlab in DARPA Subterranean Challenge](https://robotics.fel.cvut.cz/cras/darpa-subt/).

## Message Types

### Heartbeat

Heartbeat messages can be sent by sensor drivers to allow easy diagnostics of publishing rate without the need to
subscribe their possibly very large sensor messages.

The following naming convention should be used. If the sensor topic is `TOPIC`, the corresponding heartbeat messages
should be published to `TOPIC/heartbeat`. If this convention is followed, diagnostic tools can automatically assign
the heartbeats to the correct base topics.

## C++ Helper - Pool-Allocated Sensor Messages

Header `pool_allocated_sensor_msgs.h` contains several defines of alternative message types to `sensor_msgs` types,
which use a shared pool allocator for the dynamic-sized data they contain (strings and vectors). If you allocate a lot
of messages of small to medium size, this could help decrease the load created by frequent memory allocations. However,
for large messages (like 3D lidar pointclouds), the effect is questionable.

### How to Use It

Just include the header and use e.g. `sensor_msgs::ImagePoolAllocated` where you would normally type
`sensor_msgs::Image`. That's it.

### Warning

Publishers and subscribers using the pool-allocated type are incompatible with those using the default allocator.
Therefore, if there is a mismatch of allocators between the publisher and subscriber, a serialization and
deserialization step is performed to "convert" the message to the different allocator. This can be very costly and would
usually hinder all the benefits gained by using the memory pool. It is therefore needed to have a very good idea about
who the subscribers will be and how will they subscribe.