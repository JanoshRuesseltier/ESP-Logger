# ESP-Logger
A library for sending log messages over the serial connection of Arduino based microcontrollers.

## Examples
You can find more examples [here](https://github.com/JanoshRuesseltier/ESP-Logger/tree/main/examples/logging_example)

```Cpp
Serial.begin(9600);
Logger logger = Logger(&Serial, "[global]", INFO);
int error = 404;
logger.error("Error") << error << endl;
logger.info() << "This is a test information" <<endl;
```

## License

This library is free software; you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation; either version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License along with this library; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
