# caffeine++

Caffeine++ is a free, open-source console application written in C++ that can prevent the system from entering the power-saving mode.
Basically, it prevents the screen from turning off and your computer from going to sleep.
This application was developed as a command-line alternative to Linux caffeine on Windows.

![caffeine++](https://github.com/XarisA/CaffeinePP/assets/3985557/8a838dab-e4cf-4b2b-a619-3d622bbe722b)

## Command Line Arguments

Caffeine++ supports command-line arguments with the following options:

```text
arguments:
  -m,       -start-minimised       start with the window minimized
  -t time,  -timer                 runs for a specific time in seconds
  -i,       -hide-console          hide cmd
  -k,       -simulate-keypress     Simulate key process in the console
```

- Hide console can be used if you want to "start the program as a service" by placing a shortcut in the startup folder in Windows.
- Simulate keypress is an option used simply as graphic animation and nothing more

### Examples

#### Run the app for an hour

```cmd
> caffeine++.exe -t 3600
```

#### Run the app for an hour and hide the command window

```cmd
> caffeine++.exe -t 3600 -i
```

#### Run the app infinitely and Simulate keypress

```cmd
> caffeine++.exe -k
```

## Command Line Arguments in Shortcut

The command line arguments can be used in the command prompt but also as parameters in the shortcut.

### Examples

- create a shortcut pointing to the executable file
- open the shortcut’s Properties window
- in the shortcut tab, add your parameters to the target field

![248456477-12e0f4c6-00a7-46a4-adbd-931ca2d35897](https://github.com/XarisA/CaffeinePP/assets/3985557/10a212d4-8969-474b-b386-22069c7baa3e)

![248456472-9a19b8ce-350b-434d-a977-d644e0821b4d](https://github.com/XarisA/CaffeinePP/assets/3985557/190c5d7d-533c-49d6-861c-fa8249c96bec)

## Download

You can download the latest release from [here!](https://github.com/XarisA/CaffeinePP/releases/latest)

## Requirements

caffeine++ just like any other C++ application needs microsoft visual c++ redistributables to run.
You can download latest x86 package from [here.](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

## License

GNU GENERAL PUBLIC LICENSE (Version 3, 29 June 2007)

Copyright (c) 2019 Harris Arvanitis

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
