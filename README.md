# gazebo_beam
A Gazebo beam Sonar plugin (not a ROS component)

    git clone git@github.com:Field-Robotics-Lab/gazebo_beam.git

# References

* Based on `gazebo-9.0.0/plugins/GpuRayPlugin.cc`
* Gazebo tutorials: http://gazebosim.org/tutorials
* Example contact sensor: http://gazebosim.org/tutorials?tut=contact_sensor
* ROS sensor_msgs/LaserScan: http://docs.ros.org/melodic/api/sensor_msgs/html/msg/LaserScan.html includes angle range, ranges[] and intensities[].
* ROS sensor_msgs: http://docs.ros.org/melodic/api/sensor_msgs/html/index-msg.html

# Build
Build `libnps_beam.so` using cmake:

    cd gits/gazebo_beam
    mkdir build
    cd build
    cmake ..
    make

Set library path so Gazebo can find it by putting this line in `.bashrc`:

    # Gazebo plugin
    export LD_LIBRARY_PATH=~/gits/gazebo_beam/build:$LD_LIBRARY_PATH

