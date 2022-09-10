# lost-in-space

## deviations

This implementation deviates from the course as taught in several ways. Notably:

1. Supporting software installed using `homebrew`

### installation

Instead of manually installing Arduino IDE and the CH340 drivers, I elected to install both using `homebrew`. This ensures all my computers have suporting software installed and configured the same way.

#### CH340 driver

```sh
% brew tap mengbo/ch340g-ch34g-ch34x-mac-os-x-driver https://github.com/mengbo/ch340g-ch34g-ch34x-mac-os-x-driver
==> Tapping mengbo/ch340g-ch34g-ch34x-mac-os-x-driver
Cloning into '/usr/local/Homebrew/Library/Taps/mengbo/homebrew-ch340g-ch34g-ch34x-mac-os-x-driver'...
... snipped
% brew install --cask wch-ch34x-usb-serial-driver
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

#### Arduino IDE

```sh
% brew install --cask arduino
```
