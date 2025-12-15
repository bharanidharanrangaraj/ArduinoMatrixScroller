# MatrixScroller v1.0.0 Release Notes

## Initial Release

We're excited to announce the first stable release of **MatrixScroller** - a scrolling text library for the Arduino UNO R4's built-in LED Matrix!

## What's New

### Core Features
- **Smooth Scrolling Text** - Display scrolling messages on the Arduino UNO R4's 12×8 LED matrix
- **ASCII Character Support** - Full support for:
  - Letters: A-Z (uppercase and lowercase)
  - Numbers: 0-9
  - Spaces
- **Real-time Serial Input** - Update scrolling text dynamically via Serial Monitor
- **Fixed Orientation** - Correct LED mapping prevents text mirroring
- **Optimized Performance** - Smooth 80ms scroll delay for readable text

### Simple API
Just three methods to get started:
```cpp
scroller.begin();           // Initialize
scroller.setText("Hello");  // Set text
scroller.update();         // Update (call in loop)
```

### Examples Included
1. **Scroll.ino** - Basic static text scrolling
2. **SerialScroll.ino** - Interactive serial input demo

### Documentation
- Comprehensive README with installation guides
- Full header documentation with MIT License
- Multiple installation methods (ZIP, Git Clone, Manual)
- API reference and usage examples
- Troubleshooting guide

## Technical Details

| Specification | Value |
|--------------|-------|
| Display Resolution | 12×8 pixels |
| Font Size | 5×7 pixels per character |
| Scroll Speed | 80ms per frame |
| Supported Boards | Arduino UNO R4 WiFi/Minima |
| Dependencies | Arduino_LED_Matrix |
| License | MIT |

## Getting Started

### Installation

**Method 1: Git Clone**
```bash
cd ~/Documents/Arduino/libraries
git clone https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller.git
```

**Method 2: ZIP Download**
Download and install via: Sketch → Include Library → Add .ZIP Library

### Quick Example
```cpp
#include <MatrixScroller.h>

MatrixScroller scroller;

void setup() {
  scroller.begin();
  scroller.setText("ARDUINO R4");
}

void loop() {
  scroller.update();
}
```

## Platform Support
- Arduino UNO R4 WiFi
- Arduino UNO R4 Minima

## Future Plans
- Additional special characters and symbols
- Variable scroll speed control (`setSpeed()`)
- Multiple animation effects
- Custom font support
- Brightness control
- Text alignment options

## License
MIT License - Free to use, modify, and distribute

## Contributing
Contributions are welcome! Please visit the [GitHub repository](https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller) to report issues or submit pull requests.

**Enjoy scrolling!** 

For full documentation, visit: https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller
