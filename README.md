
# ARDUINO KEYBOARD

Uses 2 [Arduino micro](https://store.arduino.cc/usa/arduino-micro) s (one per hand).
The arduinos are connected through a [I2C](https://cs.wikipedia.org/wiki/I%C2%B2C) line using the Arduino [Wire library](https://www.arduino.cc/en/Reference/Wire).

The left hand works as the main board connected to the pc through a usb cable. It periodically queries the other board for its state which is sent in the form of a single packet of 27 bytes (1 byte per key).
The values **0xaa (1010 1010 binary)** and **0x55 (0101 0101 binary)** are used for pressed/released respectively.


## KEY LAYOUT

Keys are organised in 6 columns and 4 and 5 rows respectively on left and right hand (fifth row of right hand is the thumb section which has only 3 columns).
Columns are numbered 1-6 and rows are numbered A-E (left-to-right and top-to-bottom respectively).

**e.g.** the **F** key's label is **C5**.

## Very much Work In Progress
