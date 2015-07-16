# NeoPixelController
## Python to Arduino controller for Neopixel LED rings.
===
## Things to do:
### 1. Use Comando
Using [comando](https://github.com/braingram/comando) would make this library more reliable and allow for us modify the library further.
### 2. Make Multi Ring Support
Make all of the python commands take an initial argument of ring_index that specifies which ring it is controlling.
Then on the Arduino side make an array of Ring Objects (specified by their controlling pins) and take the first argument from commands to be the index of the ring.
(see the work that was done on [ADComando](https://github.com/Lathomas42/AutoDriverComando)
### 3. Add Test cases / Update Examples
This will be necessary after the previous two steps are complete.