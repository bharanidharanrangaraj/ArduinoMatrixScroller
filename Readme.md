# MatrixScroller

A scrolling text library for the **Arduino UNO R4 WiFi/Minima** LED Matrix display. Display smooth, readable scrolling text with support for ASCII characters (A-Z, 0-9), serial input, and correct LED orientation.

## Features

**Easy to Use** - Simple API with just three methods: `begin()`, `setText()`, and `update()`  
**ASCII Support** - Displays uppercase/lowercase letters (A-Z) and numbers (0-9)  
**Smooth Scrolling** - Optimized scroll speed (80ms delay) for readable text  
**Serial Input** - Update scrolling text in real-time via Serial Monitor  
**Correct Orientation** - Fixed mirroring issue for proper text display  

## Installation

### Method 1: Arduino IDE (ZIP)

1. Download this repository as a ZIP file (Code → Download ZIP)
2. In Arduino IDE: **Sketch** → **Include Library** → **Add .ZIP Library...**
3. Select the downloaded ZIP file
4. Restart Arduino IDE

### Method 2: Git Clone

Clone the repository directly into your Arduino libraries folder:

**Windows:**
```bash
cd Documents\Arduino\libraries
git clone https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller.git
```

**macOS/Linux:**
```bash
cd ~/Documents/Arduino/libraries
git clone https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller.git
```

Then restart Arduino IDE.

### Method 3: Manual Installation

1. Download this repository
2. Copy the `MatrixScroller` folder to your Arduino libraries directory:
   - **Windows**: `Documents\Arduino\libraries\`
   - **macOS**: `~/Documents/Arduino/libraries/`
   - **Linux**: `~/Arduino/libraries/`
3. Restart Arduino IDE

## Hardware Requirements

- **Arduino UNO R4 WiFi** or **Arduino UNO R4 Minima**
- The built-in 12×8 LED Matrix display

## Dependencies

- `Arduino_LED_Matrix` (included with Arduino UNO R4 board package)

## Usage

### Basic Example

```cpp
#include <MatrixScroller.h>

MatrixScroller scroller;

void setup() {
    scroller.begin();
    scroller.setText("HELLO WORLD");
}

void loop() {
    scroller.update();
}
```

### Serial Input Example

```cpp
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
```

**To use:**
1. Upload the sketch to your Arduino UNO R4
2. Open Serial Monitor (115200 baud)
3. Type your message and press Enter
4. Watch it scroll on the LED matrix!

## API Reference

### `MatrixScroller()`

Constructor - creates a new MatrixScroller instance.

```cpp
MatrixScroller scroller;
```

### `void begin()`

Initializes the LED matrix. Call this once in `setup()`.

```cpp
void setup() {
    scroller.begin();
}
```

### `void setText(const String &text)`

Sets the text to scroll. Automatically adds spacing after the text.

**Parameters:**
- `text` - String to display (supports A-Z, a-z, 0-9, and spaces)

```cpp
scroller.setText("ARDUINO R4");
```

### `void update()`

Updates the scrolling animation. Call this repeatedly in `loop()`. The scroll speed is automatically managed (80ms between frames).

```cpp
void loop() {
    scroller.update();
}
```

## Supported Characters

- **Letters**: A-Z (uppercase and lowercase)
- **Numbers**: 0-9
- **Spaces**: Supported
- **Other characters**: Displayed as spaces

## How It Works

The library uses a custom 5×7 pixel font stored in the `FONT` array. Each character is rendered column by column as the text scrolls horizontally across the 12×8 LED matrix. The scrolling speed is optimized at 80ms per frame for smooth, readable text.

## Technical Details

- **Display Resolution**: 12 columns × 8 rows
- **Font Size**: 5 columns × 7 rows per character
- **Character Spacing**: 1 pixel between characters (6 total stride)
- **Scroll Delay**: 80ms between frames
- **Orientation**: Correctly mapped to prevent mirroring

## Troubleshooting

### Text appears mirrored or upside down
This issue has been fixed in the library. The text should display correctly with the proper orientation.

### Text scrolls too fast or too slow
The scroll speed is set to 80ms (`SCROLL_DELAY` constant in `MatrixScroller.h`). You can modify this value and recompile if needed.

### Characters don't display
Make sure you're using supported characters (A-Z, a-z, 0-9, spaces). Other characters will render as spaces.

### LED Matrix doesn't initialize
Ensure you have:
- Arduino UNO R4 WiFi or Minima
- Latest Arduino UNO R4 board package installed
- `Arduino_LED_Matrix` library available

## Examples

The `examples` folder contains:

- **SerialScroll** - Interactive serial input demo

Access examples in Arduino IDE: **File** → **Examples** → **MatrixScroller**

## License

This library is open source. Feel free to use, modify, and distribute.

## Version History

- **v1.0.0** - Initial release
  - Scrolling text support for A-Z, a-z, 0-9
  - Serial input functionality
  - Fixed LED orientation/mirroring
  - Optimized scroll speed

## Contributing

Contributions are welcome! If you find bugs or have feature suggestions, please open an issue.

## Acknowledgments

Built for the Arduino UNO R4's innovative 12×8 LED Matrix display. Special thanks to the Arduino community.

---

**Enjoy scrolling!** 
