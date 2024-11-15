# Debugprobe rp2040-zero

It's port of debugprobe for cheap ~2$ board with extra support of on-board rgb led.

### Done:
- Fix problem with not working firmware after upload and reset. PICO_XOSC_STARTUP_DELAY_MULTIPLIER is solution.
- Change ports for easy access
- Add built-in led support

### Pinout:
```
GP8     TX
GP9     RX
GP10    SWCLK
GP11    SWDIO
GP12    GND
GP13    GND
GP14    3V3
```

![probe_image](img/img1.jpg)

![probe_image](img/img2.jpg)

### Led legend:
- Dimm red: power on, bright red: usb comm.
- Green: Flashing/Debugging
- Blue: RX Serial

### How to make it
If you wanna compile it, follow the guidelines in chapter 'Hacking' below and compile with "cmake -DDEBUG_ON_ZERO=ON ..".
Binary uf2 is for download in relese tab. Connecting pins GP13/GP14 to gnd/3v3 is optional if you want use board as power supply.

### Links
- [Information about the RP2040-Zero board with pinouts](https://www.waveshare.com/wiki/RP2040-Zero)
- [3D model of case](https://www.thingiverse.com/thing:6832908)

# Debugprobe

Firmware source for the Raspberry Pi Debug Probe SWD/UART accessory. Can also be run on a Raspberry Pi Pico.

[Raspberry Pi Debug Probe product page](https://www.raspberrypi.com/products/debug-probe/)

[Raspberry Pi Pico product page](https://www.raspberrypi.com/products/raspberry-pi-pico/)


# Documentation

Debug Probe documentation can be found in the [Pico Getting Started Guide](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf). See "Appendix A: Using the Debug Probe".

# Hacking

For the purpose of making changes or studying of the code, you may want to compile the code yourself.

First, clone the repository:
```
git clone https://github.com/raspberrypi/debugprobe
cd debugprobe
```
Initialize and update the submodules:
```
 git submodule update --init
```
Then create and switch to the build directory:
```
 mkdir build
 cd build
```
If your environment doesn't contain `PICO_SDK_PATH`, then either add it to your environment variables with `export PICO_SDK_PATH=/path/to/sdk` or add `PICO_SDK_PATH=/path/to/sdk` to the arguments to CMake below.

Run cmake and build the code:
```
 cmake ..
 make
```
Done! You should now have a `debugprobe.uf2` that you can upload to your Debug Probe via the UF2 bootloader.

If you want to create the version that runs on the Pico, then you need to invoke `cmake` in the sequence above with the `DEBUG_ON_PICO=ON` option:
```
cmake -DDEBUG_ON_PICO=ON ..
```

This will build with the configuration for the Pico and call the output program `debugprobe_on_pico.uf2`, as opposed to `debugprobe.uf2` for the accessory hardware.

Note that if you first ran through the whole sequence to compile for the Debug Probe, then you don't need to start back at the top. You can just go back to the `cmake` step and start from there.

# Building for the Pico 2

If using an existing debugprobe clone:
- You must completely regenerate your build directory, or use a different one.
- You must also sync and update submodules as rp2350 needs a downstream FreeRTOS port for now.
- `PICO_SDK_PATH` must point to a version 2.0.0 or greater install.


```
git submodule sync
git submodule update --init
mkdir build-pico2
cd build-pico2
cmake -DDEBUG_ON_PICO=1 -DPICO_BOARD=pico2 -DPICO_PLATFORM=rp2350 ../
```

# TODO
- AutoBaud selection, as PIO is a capable frequency counter
- Possibly include RTT support
