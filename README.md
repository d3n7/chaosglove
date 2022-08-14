# chaos_glove
Bluetooth MIDI Glove for the ESP32 with Arduino

Features:
- Switches for turning on and off accelerometer data
- 2 buttons for switching MIDI channels
- 2 buttons for playing notes or turning on and off effects

Parts List:
- Female header sockets (1x20, 1x16, 1x5)
- 4x 2-pin pushbuttons
- 2x 3-pin switches
- 6x 10kΩ resistors
- Protoboard (at least 18x24)
- ESP32 IoT Board with Lipo Port
- https://tinkersphere.com/boards/2831-esp32-iot-board-with-lipo-port.html
- ADXL335 (triple-axis accelerometer)
- https://tinkersphere.com/sensors/1286-analog-triple-axis-accelerometer-breakout -adxl335.html
- 1x Lithium Ion Polymer Battery
- https://www.amazon.com/gp/product/B00L0W61VO/

(I recommend breadboarding it first)

For the Arduino code, you'll need the BLE_MIDI library: https://github.com/lathoub/Arduino-BLE-MIDI

I never made a schematic, but as long as you know how to wire buttons and switches you should be good. The only other wiring is for the accelerometer, which goes directly from the X and Y pins of the accelerometer to any analog pins on the ESP32.

Here's a pretty picture of it, though:

![pretty picture](glove.png)

Here's a video showing how to use the glove: https://www.youtube.com/embed/g6u06UhuX4E

I should note this glove is a slightly different version that includes a light sensor (photocell).
