# chaos_glove
Bluetooth MIDI Glove for the ESP32 with Arduino

Parts List:
- Female header sockets (1x20, 1x16, 1x5)
- 4x 2-pin pushbuttons
- 2x 3-pin switches
- 9x 10kΩ resistors
- Protoboard (18x24)
- ESP32 IoT Board with Lipo Port
- https://tinkersphere.com/boards/2831-esp32-iot-board-with-lipo-port.html
- ADXL335 (triple-axis accelerometer)
- https://tinkersphere.com/sensors/1286-analog-triple-axis-accelerometer-breakout -adxl335.html
- 1x Lithium Ion Polymer Battery
- https://www.amazon.com/gp/product/B00L0W61VO/

For the Arduino code, you'll need the BLE_MIDI library: https://github.com/lathoub/Arduino-BLE-MIDI

I never made a schematic, but as long as you know how to wire buttons and switches you should be good. The only other wiring is for the accelerometer, which goes directly from the X and Y pins of the accelerometer to any analog pins on the ESP32.

Here's a pretty picture of it, though:

![pretty picture](/images/glove.png)
