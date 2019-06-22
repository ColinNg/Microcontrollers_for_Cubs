# Microcontrollers for Cubs

# Setup Instructions

1. Download [Arduino](https://www.arduino.cc/en/Main/Software). 
2.	Start the Arduino program. 
3. The first time you run Arduino you will need to do this:
	1.	Go to Preferences. 
	
    	![](https://digistump.com/wiki/_media/digispark/tutorials/preferences.gif)
    
    2.	Under "Additional Board Manager URLs" enter:
	
		`http://digistump.com/package_digistump_index.json`

	    and click OK. 
	    
    	![](https://digistump.com/wiki/_media/digispark/tutorials/entry.jpg)

	3.	Go to **Tools** > **Board** > **Boards Manager...**
	4.	In the search field type **Digispark**. 
	5. Click the **Install** button in the first result. 
	6. Click **Close**. 
	7.	Now choose **Tools** > **Board** > **Digispark (Default - 16.5mhz)**, the first choice under the _Digistump AVR Boards_ section. 


# Upload a Program to Your Microcontroller


## Rainbow RGB LED

1.	Choose **File** > **New** to start a new Sketch. 
2.	Select all the code in the sketch and delete it. 
3. Copy all the lines from `Rainbow_RGB_LED.ino` and paste them into your sketch. 
4.	Choose the menu **Sketch** > **Upload**
5.	The first time you do this, it will ask to save the Sketch. Name it `Rainbow_RGB_LED`. 
6. In the bottom of the Sketch window it will say:

	```
	Running Digispark Uploader...
	Plug in device now... (will timeout in 60 seconds)
	```
7.	Plug the Digispark into your computer. 
8. Once it has finished uploading it will say:

	```
	...writing: 80% complete
	running: 100% complete
	>> Micronucleus done. Thank you!
	```
9.	You can now run your Digispark from any USB power source (battery bank, phone charger, or the computer's USB port).

### Connecting the LED

On the Digispark, connect these wires:

#### Dark Cable
| Digispark | Wire 	|	LED Pin		|
|---------|---------|----------------|
| P0		| White	| Right (tan resistor) |
| GND		| Black	| Middle Right (blank) |
| P1		| Gray		| Middle Left (blue resistor) |
| P4		| Purple	| Left (blue resistor) |

#### Light Cable
| Digispark | Wire 	|	LED Pin		|
|---------|---------|----------------|
| P0		| Red		| Right (tan resistor) |
| GND		| Brown	| Middle Right (blank) |
| P1		| Orange	| Middle Left (blue resistor) |
| P4		| Yellow	| Left (blue resistor) |

### More Info

The code is from this [AdaFruit tutorial](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch), but we used these pin nunbers instead: redPin = 0, greenPin = 1, bluePin = 4. 

We also changed some of the amount of red, green, and blue for each color, because the our RGB LED is slightly different than the one from AdaFruit. 

You can mix the amounts of Red/Green/Blue to make any color you want. For an idea of where the colors are, see this [RGB Color Wheel & Color Map](http://www.procato.com/color%2Bwheel/). For example, you can get yellow by mixing Red and Green. 


## Tone / Melody

1.	Make a new sketch and replace the code with the code from `ToneMelody.ino`. 
2. Choose New Tab, name it `pitches.h`, and copy the code from `pitches.h` to this tab. 

	![Create a New Tab for dot h files using the downward pointing triangle](images/Create%20a%20New%20Tab%20for%20dot%20h%20files%20using%20the%20downward%20pointing%20triangle.png)

3. Click Upload. 

### Connecting the Speaker

Connect the speaker to P0 and GND (it doesn't matter which speaker wire goes to which pin). 

### More Info

[Original Tutorial at the official Arduino site](https://www.arduino.cc/en/Tutorial/ToneMelody), and we changed Pin 8 (which we don't have) to Pin 0. You can use any pin marked `PWM` which are 0, 1, 2, and 4. Don't forget to plug the speaker wire to the new Pin, and to GND. 


# More Info

The Microcontroller you are using is a clone of the Digispark. More information on it can be found [here](https://digistump.com/wiki/digispark/tutorials/connecting). 