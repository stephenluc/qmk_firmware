# Neo80 Cu (tri-mode, ANSI hotswap)

VIA layout for the Qwertykeys Neo80 Cu. Unlike the other boards in this folder,
this one isn't a compiled `keymap.c` — the Neo80 Cu runs Qwertykeys' factory
**VIA-enabled firmware**, so the layout lives in `neo80_cu.layout.json` and is
applied through VIA, not flashed.

- **Firmware:** Qwertykeys `V0101` (`Neo80_Cu-80KEY-_-_-CSC923-V0101`). App-mode USB ID `0x36B0:0x30C2`.
- **MCU / bootloader:** WB32FQ95 main + CH582F wireless; LUFA mass-storage bootloader.

## Loading the layout in VIA
[usevia.app](https://usevia.app) → **Save + Load** → **Load Saved Layout** →
pick `neo80_cu.layout.json`. (VIA runs locally in-browser; nothing is uploaded.)

If VIA doesn't recognize the board, enable **Show Design tab** in settings and load the
`neo80_cu_ansi` JSON definition from the Qwertykeys firmware page first.
New to VIA? See [How to use VIA](https://www.keychron.com/blogs/archived/how-to-use-via-to-program-your-keyboard).

## Layers
- **0 — Base:** standard ANSI. Caps→LCtrl, bottom-left→`MO(2)`, RCtl→RAlt (Mac format), Fn→`MO(1)`.
- **1 — Media/Fn** (hold right Fn): F-row stays numbers; `QWER`=media, `ASD`=volume, `ZX`=brightness,
  LAlt=Meh, LWin=Hyper, real Caps Lock, plus Mac shortcuts (Mission Control, screenshots).
- **2 — Wireless/RGB** (hold bottom-left): `` ` `` `1` `2` `3` `4` = USB/BLE1-3/2.4G; `Q`–`[` = logo RGB; battery/sleep.
- **3 — Personal** (hold both toggles): `R`=`RESET` (bootloader), `E`=clear EEPROM, `O`=WHOAMI macro.

## Flashing firmware on macOS
The Neo80 Cu uses a **WB32 + LUFA mass-storage bootloader**. On macOS you must flash from the
**Terminal** — the Finder and QMK Toolbox GUI write metadata that corrupts the mass-storage write
(QMK Toolbox fails with `IO Error: "FLASH.BIN" couldn't be removed`).

1. Download the `.bin` from the [Qwertykeys firmware page](https://www.qwertykeys.com/pages/fw)
   (Neo80 Cu tri-mode ANSI section).
2. Make sure the board is in **wired/USB mode** (hold bottom-left `MO(2)` + `` ` `` to select USB;
   if you're already typing over USB you're in wired mode).
3. **Enter the bootloader** — either press the `RESET` key (Layer 3: hold both toggles → `R`),
   or unplug, hold `Esc`, and plug the USB-C back in while holding `Esc` ~5s.
4. The keyboard stops typing and mounts as a USB drive named **`NO NAME`** (`/Volumes/NO NAME`).
5. Stop Spotlight from touching the drive, then copy the firmware over `FLASH.BIN`:
   ```sh
   mdutil -i off "/Volumes/NO NAME"
   cp ~/Downloads/Neo80_Cu-80KEY-_-_-CSC923-V0101-20250808_New.bin "/Volumes/NO NAME/FLASH.BIN"
   ```
6. The bootloader writes it and **auto-reboots into the new firmware**. A macOS
   "Disk Not Ejected Properly" warning is expected — ignore it.
7. Verify it's back: `system_profiler SPUSBDataType | grep -iA3 neo80` (should show app mode again).
8. Flashing wipes the keymap — **re-load `neo80_cu.layout.json` in VIA afterward.**

> Apple Silicon note: QMK Toolbox's flasher binaries are Intel-only, so the Terminal `cp` method
> above is the reliable path on M-series Macs anyway.

## Resources
- [Qwertykeys firmware page](https://www.qwertykeys.com/pages/fw) — Neo80 Cu `.bin` firmware + `neo80_cu_ansi` VIA JSON definition
- [Neo80 build guide](https://qwertykeys.notion.site/Neo80-Build-Guide-a89eb0eca0a0490bbb1fe27a2ef51fb4)
- [How to use VIA](https://www.keychron.com/blogs/archived/how-to-use-via-to-program-your-keyboard)
