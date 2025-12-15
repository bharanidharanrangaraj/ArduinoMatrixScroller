/**
 * @file MatrixScroller.h
 * @brief Header file for the MatrixScroller library
 * 
 * This library provides scrolling text functionality for the Arduino UNO R4's
 * built-in 12x8 LED matrix display. Supports ASCII characters (A-Z, 0-9),
 * smooth scrolling animation, and serial input for dynamic text updates.
 * 
 * @author Bharani Dharan Rangaraj
 * @version 1.0.0
 * @date 2025-12-15
 * 
 * @copyright Copyright (c) 2025 Bharani Dharan Rangaraj
 * @license MIT License
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef MATRIX_SCROLLER_H
#define MATRIX_SCROLLER_H

#include <Arduino.h>
#include <Arduino_LED_Matrix.h>

class MatrixScroller {
public:
    MatrixScroller();

    void begin();
    void setText(const String &text);
    void update();

private:
    ArduinoLEDMatrix _matrix;
    String _text;
    int _scrollOffset;
    unsigned long _lastUpdate;
    static const uint16_t SCROLL_DELAY = 80;

    void renderFrame();
    uint8_t charToIndex(char c);
};

#endif
