/**
 * @file MatrixScroller.cpp
 * @brief Implementation file for the MatrixScroller library
 * 
 * This file contains the implementation of the MatrixScroller class,
 * including font definitions, scrolling logic, and LED matrix rendering.
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

#include "MatrixScroller.h"

static const uint8_t FONT[][5] = {
    // Space
    {0x00,0x00,0x00,0x00,0x00},

    // A-Z
    {0x7E,0x11,0x11,0x11,0x7E}, // A
    {0x7F,0x49,0x49,0x49,0x36}, // B
    {0x3E,0x41,0x41,0x41,0x22}, // C
    {0x7F,0x41,0x41,0x22,0x1C}, // D
    {0x7F,0x49,0x49,0x49,0x41}, // E
    {0x7F,0x09,0x09,0x09,0x01}, // F
    {0x3E,0x41,0x49,0x49,0x7A}, // G
    {0x7F,0x08,0x08,0x08,0x7F}, // H
    {0x41,0x41,0x7F,0x41,0x41}, // I
    {0x20,0x40,0x41,0x3F,0x01}, // J
    {0x7F,0x08,0x14,0x22,0x41}, // K
    {0x7F,0x40,0x40,0x40,0x40}, // L
    {0x7F,0x02,0x04,0x02,0x7F}, // M
    {0x7F,0x04,0x08,0x10,0x7F}, // N
    {0x3E,0x41,0x41,0x41,0x3E}, // O
    {0x7F,0x09,0x09,0x09,0x06}, // P
    {0x3E,0x41,0x51,0x21,0x5E}, // Q
    {0x7F,0x09,0x19,0x29,0x46}, // R
    {0x46,0x49,0x49,0x49,0x31}, // S
    {0x01,0x01,0x7F,0x01,0x01}, // T
    {0x3F,0x40,0x40,0x40,0x3F}, // U
    {0x1F,0x20,0x40,0x20,0x1F}, // V
    {0x7F,0x20,0x18,0x20,0x7F}, // W
    {0x63,0x14,0x08,0x14,0x63}, // X
    {0x03,0x04,0x78,0x04,0x03}, // Y
    {0x61,0x51,0x49,0x45,0x43}, // Z

    // Numbers 0-9
    {0x3E,0x45,0x49,0x51,0x3E}, // 0
    {0x00,0x41,0x7F,0x40,0x00}, // 1
    {0x62,0x51,0x49,0x49,0x46}, // 2
    {0x22,0x41,0x49,0x49,0x36}, // 3
    {0x18,0x14,0x12,0x7F,0x10}, // 4
    {0x2F,0x49,0x49,0x49,0x31}, // 5
    {0x3E,0x49,0x49,0x49,0x32}, // 6
    {0x01,0x71,0x09,0x05,0x03}, // 7
    {0x36,0x49,0x49,0x49,0x36}, // 8
    {0x26,0x49,0x49,0x49,0x3E}, // 9
};

MatrixScroller::MatrixScroller()
    : _scrollOffset(0), _lastUpdate(0) {}

void MatrixScroller::begin() {
    _matrix.begin();
}

void MatrixScroller::setText(const String &text) {
    _text = text + "   ";
    _scrollOffset = 0;
}

void MatrixScroller::update() {
    if (millis() - _lastUpdate < SCROLL_DELAY) return;
    _lastUpdate = millis();
    renderFrame();
    _scrollOffset++;
}

uint8_t MatrixScroller::charToIndex(char c) {
    if (c == ' ') return 0;
    if (c >= 'A' && c <= 'Z') return (c - 'A') + 1;
    if (c >= 'a' && c <= 'z') return (c - 'a') + 1;
    if (c >= '0' && c <= '9') return (c - '0') + 27;
    return 0;
}

void MatrixScroller::renderFrame() {
    uint8_t frame[8][12] = {0};
    int stride = 6;

    for (int x = 0; x < 12; x++) {
        int idx = (_scrollOffset + x) / stride;
        int col = (_scrollOffset + x) % stride;

        if (idx >= _text.length() || col >= 5) continue;

        uint8_t glyph = charToIndex(_text[idx]);
        uint8_t bits = FONT[glyph][col];

        for (int y = 0; y < 8; y++) {
            if (bits & (1 << y)) {
                frame[7 - y][x] = 1; // FIXED MIRROR ISSUE
            }
        }
    }

    _matrix.renderBitmap(frame, 8, 12);
}
