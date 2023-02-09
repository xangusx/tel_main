# TEL_main
---
## first half
* race

There have three main nodes, main.cpp、reset.cpp.

reset.cpp control the launching of main.cpp.

* ekf_odom

When run the main.cpp, also need to run the ekf_odom/wheel_odom.cpp.

Originally planned to use ekf to fusion the imu and encoder data, but not completely.

## second half
* remote_controll

secondhalf.launch that use rosserial_python package to connect STM.

secondhalf_cpp.launch that use rosserial_server package to connect STM.
