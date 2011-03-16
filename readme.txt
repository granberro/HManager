HManager
========
Based on PSLIGHT, Tiny3D, PS3Soundlib and OpenPS3FTP, it’s the first open code manager made with Homebrew tools.

It’s thought for the psgroove-hermesv4 base and concretely for CFW 3.41 (it’s compatible with the old dongle, but in that case there will be some inactive features). This program must only be used for the legitimate use of backup, and the author declines third parts misuse of the program and only recognizes the uses that the Spanish Legislation in the private area allows.

Features
===============

-Like Open Manager does, it allows loading games from internal and external HDD, Bluray and also games copy, test and delete

-Includes the psgroove-hermesv4D payload with the signed self

-It’s shown in a 4x3 icons screen graphical interface.

-It allows screen adjustment, games directory and background color change.

-It reduces the buttons use and the possibility of making a mistake by pressing the wrong one (especially designed for children)

-Includes FTP support (OpenPS3FTP), the possibility of blocking the syscalls (through internal key : it’s recommended to compile the program changing "hmanager_key" for another one) and the possibility of launching PS3LoadX directly.

-Possibility of replacing new games EBOOT.BIN with an external one

-The games settings are saved in a separated directory

Changes in 1.1 version:

- Possibility of adding an imported music.mod file ("/dev_hdd0/game/HMANAGER4/music.mod")

- Added new route for games search in "/dev_hdd0/GAMES"

- 'Favourites' feature added: possibility to add 12 games and sort them as you like on home screen

- FTP upgraded to most recent version

- Various fixes (small bugs, banners added for hidden menus...)

Changes in 1.2 version:

- BDEMU added to launch games from /dev_usb00x/PS3_GAME with black screen like Modern Warfare. Allow to launch games from /app_home/
  without any Bluray disc inserted. (it needs the option "BD Emu (for USB)" in "On")

Changes in 1.3 version:

- Added Auto patch PARAM.SFO (it renames the original file as _PARAM.SFO)

Changes in 1.4 version:

- Added support to run games with bigfiles from external USB devices (caching the big file from the internal HDD). See details in the section
"About Cached Games"

- Added "Fix File Permissions" function

Changes in 1.5 version:

- Added support to run games with VARIOUS bigfiles from external USB devices (caching the big file from the internal HDD). See details in the section
"About Cached Games"

- Added support to map dev_hdd0/game to /dev_usb00x/GAMEI (remmeber you it is not supported in all games)

- Minor changes when list games, etc

Controls
=========

At games screen:

    LEFT/RIGHT/UP/DOWN -> move to select game. When limits reached, it changes screen

    CROSS    -> load game options and go to the XMB

    TRIANGLE -> exit to XMB

    SELECT   -> go to game configuration options

    START    -> go to HMANAGER global settings

Favourites:

    L2 + TRIANGLE -> Move favourites
    
    CROSS         -> Favourites swap / Replace (Moving favourites)

    TRIANGLE      -> Cancel (Moving favourites)

In configuration options and everywhere:

    UP/DOWN    -> Move between selections

    LEFT/RIGHT -> Select (in Config.Game)

    CROSS      -> Select

    CIRCLE     -> Return

At any time:

    L2 + R2 + START -> Screen adjust


"Options" screen
-----------------

Config. Game -> Go to Config .Game screen

Copy Game    -> Copy games from BR/HDD

Delete Game  -> Erases games from HDD

Test Game    -> Makes a test reporting if the game has big or splitted files

Copy EBOOT.BIN from USB -> Copies an external EBOOT.BIN from "/dev_usb/ps3game" to "/dev_hdd0/game/HMANAGER4/self" directory. The expected name is
                           "ID".BIN (e.g. in GT5 the name would be BCES-00569.BIN). This feature requires payload v4D and the activation of the 
                           "extern EBOOT.BIN" feature. Thus, it’s possible to launch the original bluray in 3.41 with modified self

Return       -> Returns

Config. Game screen
---------------------

Fix Permissions  -> Switches between "Default" (console’s original, needed in some games), "Ps Jailbreak" and "v4 Perms (F1)", which is the 
                   Payload V4 default mode

Select XMB       -> Switches between "Debug" (XMB with jailbreak) and "Retail" (requires disk to launch game, but allows other things)

Online Updates   -> By default is "on" (does nothing)... switching to "off" in payload v4D modifies "on the fly" the application’s version, 
                   avoiding upgrades.

Extern EBOOT.BIN -> Switches between "on" (requires a previously copied with it’s ID EBOOT.BIN) and "off"

BD Emu (for USB) -> Switches between "on" to enable BD emulation from USB device (it copy the folder PS3_GAME to /dev_usb00x/PS3_GAME) and "off"

Save Config      -> Saves the configuration in "/dev_hdd0/game/HMANAGER4/config"

Return           -> Returns

Global Options screen
-----------------------

Video Adjust -> Screen adjust

Change Game Directory   -> To change games directory (autodetects between "/dev_hdd0/GAMEZ " and "/dev_hdd0/game/xxxx/GAMEZ")

Change Background Color -> Changes background color

Load PS3LoadX -> Option to load the developing utility PS3LoadX. If permissions were set to "default" it can be useful as well
                as convenient to first launch HMANAGER to ensure the latest payload version

Initialize FTP Server -> Once started, shows IP and port. From a FTP client , access as anonymous

Return -> Returns

Tools
-----

Delete Cache Tool       -> To enter in menu to allow to delete bigfiles cached entries

Press To Enable Syscall Security -> When enabled, it doesn’t allow other programs to use 6,7,8 and 36 syscalls used by payload
Press To Disable Syscall Security   Remember to modify "hmanager_key" and compile the program if you want maximum security


About Cached Games
------------------

You can launch games with splitted bigfiles from external hard drive (FAT32) the same way as the Open Manager (extension .6660xx).

These games must be placed in folder "GAMEZ" typing before the game name the character "_ ", used in Open Manager to mark a game as non executable ("Marked as non executable"). You can add this mark using the function "Test Game" in a game that contains splitted files. For example: /dev_usb000/GAMEZ/_BCES-00000

When you press CROSS to run the game, the message "Marked as non executable. Trying to install in HDD0 cache" will be displayed in case you do not have a cache entry, showing then "Want to copy from USB00X to HDD0 CACHE?"

If you answer YES it starts to do a free space test of the HDD0 (if there is not enough space it will show the "Delete Cache Tool" for you to choose entries to delete, displaying the required and the available space on your hard disk. Remember to leave enough space for the PS3 system).
When it is done, it proceeds to install the bigfile in the cache. Only one bigfile per game is supported.

Later, you can delete the cached BigFiles pressing START -> "Tools " -> "Delete Cache Tool" if you want.

The advantage of launching a game from external hard drive is that the size of its bigfile, usually takes much less space than the complete game (and also requires less time to install the game).


Notes about compilation
-----------------------

Requires the latest PSL1GHT, Tiny3D and PS3Soundlib from my git: https://github.com/hermesEOL

Obviously, it’s possible to adapt the program to other payloads/firmware versions and the source code is at your disposal to do so.

Due to recent problems with github.com and other development sites, I prefer to publish the source code and binaries in an 
"old way": in ZIP/RAR format and I invite other developers to publish their changes in the same way.


translated by VETTE and Hermes
