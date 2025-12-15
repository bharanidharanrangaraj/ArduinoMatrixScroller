/**
 * @file Scroll.ino
 * @brief Basic example demonstrating simple scrolling text
 * 
 * This example shows the simplest way to use the MatrixScroller library
 * to display static scrolling text on the Arduino UNO R4's LED matrix.
 * Perfect for getting started with the library.
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
 * 2. Watch "Hello World" scroll across the LED matrix
 * 3. Modify the text in setText() to display your own message
 */

#include <MatrixScroller.h>

MatrixScroller scroller;

void setup() {
  scroller.begin();

  // Static text to scroll
  scroller.setText("Hello World ");
  
  // Optional: adjust speed (milliseconds per column)
  scroller.setSpeed(80);
}

void loop() {
  // Library handles timing internally
  scroller.update();
}
