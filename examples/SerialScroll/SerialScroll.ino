/**
 * @file SerialScroll.ino
 * @brief Example sketch demonstrating serial input scrolling text
 * 
 * This example shows how to use the MatrixScroller library to display
 * scrolling text on the Arduino UNO R4's LED matrix with real-time
 * serial input capability. Users can send text via Serial Monitor
 * and see it scroll across the display.
 * 
 * @author Bharani Dharan Rangaraj
 * @version 1.0.0
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025 Bharani Dharan Rangaraj
 * @license MIT License
 * 
 * Hardware Requirements:
 * - Arduino UNO R4 WiFi or Arduino UNO R4 Minima
 * - Built-in 12x8 LED Matrix
 * 
 * Usage:
 * 1. Upload this sketch to your Arduino UNO R4
 * 2. Open Serial Monitor at 115200 baud
 * 3. Type your message and press Enter
 * 4. Watch it scroll on the LED matrix!
 */

#include <MatrixScroller.h>

MatrixScroller scroller;

void setup() {
    Serial.begin(115200);
    scroller.begin();
    scroller.setText("HELLO UNO R4");
}

void loop() {
    scroller.update();

    if (Serial.available()) {
        String text = Serial.readStringUntil('\n');
        text.trim();
        if (text.length() > 0) {
            scroller.setText(text);
        }
    }
}
