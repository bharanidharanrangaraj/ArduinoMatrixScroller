# Changelog

All notable changes to the MatrixScroller library will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2025-12-15

### Initial Release

First stable release of the MatrixScroller library for Arduino UNO R4.

### Added
- Core scrolling text functionality for Arduino UNO R4 LED Matrix (12×8)
- Support for ASCII characters:
  - Uppercase letters (A-Z)
  - Lowercase letters (a-z) 
  - Numbers (0-9)
  - Spaces
- Custom 5×7 pixel font with proper character rendering
- Smooth scrolling animation with optimized 80ms delay
- Serial input support for real-time text updates
- Fixed LED orientation to prevent text mirroring
- Simple API with three main methods:
  - `begin()` - Initialize the LED matrix
  - `setText(String)` - Set text to scroll
  - `update()` - Update scrolling animation
- Two example sketches:
  - **Scroll.ino** - Basic static text scrolling
  - **SerialScroll.ino** - Interactive serial input demo
- Complete documentation:
  - Comprehensive README with installation and usage instructions
  - Header documentation in all source files
  - MIT License
- Arduino Library Manager compatibility:
  - Proper `library.properties` configuration
  - Target architecture: `renesas_uno` (Arduino UNO R4)
  - Dependency: `Arduino_LED_Matrix`

### Technical Specifications
- Display Resolution: 12 columns × 8 rows
- Font Size: 5 columns × 7 rows per character
- Character Spacing: 1 pixel (6 pixel total stride)
- Scroll Delay: 80ms per frame
- Serial Baud Rate: 115200 (in examples)

### Platform Support
- Arduino UNO R4 WiFi
- Arduino UNO R4 Minima

---

## Future Releases

Future versions may include:
- Additional special characters and symbols
- Variable scroll speed control
- Multiple text animations (bounce, fade, etc.)
- Custom font support
- Brightness control
- Text alignment options (left, center, right)

---

**Note**: This is the initial public release. Please report any issues on the [GitHub repository](https://github.com/bharanidharanrangaraj/ArduinoMatrixScroller/issues).
