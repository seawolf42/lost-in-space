# lost-in-space

## deviations

This implementation deviates from the course as taught in several ways. Notably:

1. supporting software installed using `homebrew`
1. development entirely inside of Visual Studio Code

## installation

Instead of manually installing Arduino IDE and the CH340 drivers, I elected to install both using `homebrew`. This ensures all my computers have suporting software installed and configured the same way.

**Note:** Even development happens in VS Code, the Arduino IDE is still required for library and resource support.

### CH340 driver

```sh
% brew tap mengbo/ch340g-ch34g-ch34x-mac-os-x-driver https://github.com/mengbo/ch340g-ch34g-ch34x-mac-os-x-driver
==> Tapping mengbo/ch340g-ch34g-ch34x-mac-os-x-driver
Cloning into '/usr/local/Homebrew/Library/Taps/mengbo/homebrew-ch340g-ch34g-ch34x-mac-os-x-driver'...
... snipped
% brew install wch-ch34x-usb-serial-driver
==> Caveats
This driver was sourced from the OEM website. Discussion:
... snipped
```

You will need to reboot after this step. Then when you plug in your Arduino you should see it appear under `ls dev`:

Board plugged in:

```sh
% ls /dev/cu.usb*
/dev/cu.usbserial-121120
```

Typing the same command when the board is not plugged in returns no results. This complete string (`/dev/cu.usbserial-121120` in my case) will likely change every time you unplug and re-plug your Arduino. Use the command above to retrieve it, though in Arduino IDE you can just look for the port that matches this filename pattern.

### Arduino IDE

```sh
% brew install --cask arduino
```

**Note:** This has been officially discontinued in homebrew; you may need to install this manually instead. As of late 2022 it still works this way.

### Visual Studio Code

I haven't yet tested running VS Code from `homebrew`, so instead I still install this one the old fashioned way:

[Download Visual Studio Code](https://code.visualstudio.com/)

## setup

### IDE

Open VS Code and configure Arduino ([detailed instructions](https://maker.pro/arduino/tutorial/how-to-use-visual-studio-code-for-arduino)):

1. install the `vscode-arduino` extension
1. open an arduino `.ino` file to complete the installation
1. click "select board type" along the bottom margin and select "Arduino Uno (Arduino AVR Boards)"
1. click "select serial port" along the bottom margin and select the port that matches the `/dev/tty.usbserial-XXXXXX` name format

Now you should be able to use the "verify" and "upload" functions in VS Code to talk to the board.
