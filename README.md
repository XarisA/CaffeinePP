# caffeine++

Caffeine++ is a free, open source console application written in c++ which can prevent the system from entering the power-saving mode.
Basically, it prevents the screen from turning off and your computer from going to sleep.
This application was developed as a command line alternative to linux caffeine on windows.

![caffeine++](https://user-images.githubusercontent.com/3985557/67888246-737eea00-fb55-11e9-90ca-70f2b1a249a0.PNG)

## Command Line Arguments

Caffeine++ supports command line arguments with the following options:

```cmd
arguments:
  -m,       -start-minimised       start with thw window minimized
  -t time,  -timer                 run for specific time in seconds
  -i,       -hide-console          hide cmd
                                   (you will need to kill the app for exit)
  -k,       -simulate-keypress     Simulate key process in the console
                                   (useful for specific apps)       
```

### Examples

#### Run the app for an hour

```cmd
> caffeine++.exe -t 3600
```

#### Run the app for an hour and hide the command window

```cmd
> caffeine++.exe -t 3600 -i
```

#### Run app infinitely and Simulate keypress

```cmd
> caffeine++.exe -k
```

## Command Line Arguments in Shortcut

The command line arguments can be used in the command prompt but also as parameters in the shortcut.

### Example

- create a shortcut pointing to the executable file
- open the shortcut’s Properties window
- in the shortcut tab, add your parameters to the target field



## Download

You can download the latest release from [here!](https://github.com/XarisA/CaffeinePP/releases/latest)

## Requirements

caffeine++ just like any other c++ application needs microsoft visual c++ redistributables to run.
You can download latest x86 package from [here.](https://support.microsoft.com/en-us/help/2977003/the-latest-supported-visual-c-downloads)

## License

GNU GENERAL PUBLIC LICENSE (Version 3, 29 June 2007)

Copyright (c) 2019 Harris Arvanitis

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.
