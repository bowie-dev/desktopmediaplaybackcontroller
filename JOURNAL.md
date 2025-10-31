# DAY 1 - BRAINSTORMING & BASIC DESIGN 13/10 ~4 Hours
### Ideation
I began by listing basic functionality requirements and estimating sizes that would be appropriate.
The main problem(s) that I am solving are that:
 1.) To change my computers volume I have to reach over my desk to a knob on my speaker controller (which is annoying and I often have to leave my seat)
 2.) I cant skip, pause, or rewind songs without moving my mouse to tab into spotify or youtube and clicking around (which is annoying because I am lazy)
 3.) I don't have a really mysterious and cool aluminium box on my desk.
So my initial idea is a box with five momentary switches (rewind, pause/play, next, vol+, vol-) connected to some dev board which then plugs into my PC.
I determined that an appropriate size for the box would be approximately 150x100x50mm to allow for 5 buttons placed neatly in a line. 

### Component Sourcing
With a basic understanding of what I wanted out of this, I began looking for parts. Initially I was planning on 3D-printing the frame/box/casing but I figured that that would look ugly and cheap, looking at the prices of aluminium boxes from my local electronics store, I determined that I was better off just buying one. I found this for just under 20AUD:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk1OSwicHVyIjoiYmxvYl9pZCJ9fQ==--6d78d8416487a4d80cd8614e7b459f0ea5530cbc/image.png)
I am happy with the size and how it will look. I have the ability to remove material for the cable and buttons. Just a bit small in the longer dimension... (subtle foreshadowing).

Next I set out to look for buttons to control the actions.
I found these cool looking buttons for reasonably cheap:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2MCwicHVyIjoiYmxvYl9pZCJ9fQ==--179c768b83bdbbfcf419092eaaa436bdd211cd02/image.png)
The only problem... they're 22mm OD. Now pardon my maths but (115mm - 5x22mm) leaves just about 5mm which would maybe be almost fine but the case that I'm using has pretty thick inner walls. 
So I looked at different buttons and cases but there was really nothing else to work... I had to stagger the buttons. I brainstormed a few patterns of button layouts, I thought about how the functionality basically consisted of two parts, the play/pause/next/prev buttons and the volume control buttons. 

### Mock-Up/Layout Design
What better way to visually consider layouts than with the help of CAD. So I booted up SolidWorks (objectively the best cad package but whatever) and setup a sketch. I gave myself a 100x50mm area to work with which should be pretty lenient with tolerances.
I decided on this layout as it separates the two sides and maintains a very intuitive layout as to each buttons function:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2MSwicHVyIjoiYmxvYl9pZCJ9fQ==--4d26f28136911b1a366facd1bffee0c52595026a/image.png)


I then copied the dimensions from the case's data sheet into solidworks:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2MiwicHVyIjoiYmxvYl9pZCJ9fQ==--df547606b0d57513f3d6501d43e85bc40a80b2c7/image.png)(very hi-res photo... thanks manufacturer)
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2MywicHVyIjoiYmxvYl9pZCJ9fQ==--c6f9cf64b6ff3c236377d70db12d78736136f2de/image.png)(straight up just guessing most of these dimensions :sob:)
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2NCwicHVyIjoiYmxvYl9pZCJ9fQ==--f575f50e292fb9502f973e5a103e9810c729bfce/image.png)yeah cool okay
buttons
yippay what a data sheet...
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2NSwicHVyIjoiYmxvYl9pZCJ9fQ==--6cc6a27a8f6ad1fe4fc1b592eb12bfca1de68935/image.png)
now would be a good time to save what i have so far
...
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2NiwicHVyIjoiYmxvYl9pZCJ9fQ==--3b9a95d36f727bbad1ed3e65a8f8c507db9d2aa7/image.png)
close enough
After making the assembly I got to the stage where I (digitally) drill holes into the case, I was experimenting a bit more with the layout at this point I came across the (genius) conclusion that I could infact put SIX buttons into the case for a cleaner layout. I just didn't know what the 6th button would do... but it doesn't really matter yet so lets continue with that plan.
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2NywicHVyIjoiYmxvYl9pZCJ9fQ==--e76ee6c5ea8cfaaf83a714b3f0044242e9573c89/image.png)
Yeah it looks alright.
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2OCwicHVyIjoiYmxvYl9pZCJ9fQ==--c170bb37bf6b6530e06b6043d1872730414231a8/image.png)
this looks so cool
sneaky crossection to see what kinda space i have in the case:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk2OSwicHVyIjoiYmxvYl9pZCJ9fQ==--dfea6f56a157de9a8af58afdd3457a32856d0c75/image.png)
should be finee
Now I have to decide what microcontroller/devboard to use. I have used arduino in the past but I think an Uno or similar board would be to big. 
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk3MCwicHVyIjoiYmxvYl9pZCJ9fQ==--91e50ea9729c34832399bd6427ac9229fb229aaa/image.png)
This is cool, cheap, and small. It also has 11 GPIO pins. Perfect... Into the assembly it goes!
Now as for how I will hold the board still and against the wall of the case, I was thinking of 3D printing an insert that goes into the bottom of the case (maybe only 2-3mm thick), with some tabs/features sticking up to hold the board. Okay.
With the plate insert mocked up in solidworks, I realized that the prong-y bits of the buttons might hit the board, this is fine however as the insert is very changeable therefore the height and position of the board can be readily changed later in development.
Something like this:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MTk3MiwicHVyIjoiYmxvYl9pZCJ9fQ==--f36ae4df2c3dabbc166b2d6761c1562e10257879/image.png)

Okay I'm done for the night... here's my BOM (bill of materials) so far:
 - 1x $17.95 - Aluminium Case 115x65x30mm - https://www.jaycar.com.au/sealed-diecast-aluminium-enclosure-115-x-65-x-30mm/p/HB5036                                                                         
 - 6x $6.95 Metal Momentary SPST https://www.jaycar.com.au/metal-momentary-spst/p/SP0755                                                                                                       
 - 1x $11.35 Seeed XIAO ESP32-C3 https://core-electronics.com.au/seeed-studio-xiao-esp32c3-tiny-mcu-board-with-wi-fi-and-ble-battery-charge-supported-power-efficiency-and-rich-interface.html
 - 1x $0.00 3D-Printed Plate Insert                                                                                                                                                         | AUD$71.00 |

Total cost of ~71 aud (without shipping) (opted for cheaper seeed board)
Signing off, 
bowie 

(Edit: fix MD table which apparently wasn't MD)

# DAY 2 - MOAR PARTS! 17/10 ~4 Hours
## Rotary Encoder
I thought it would be cool to have a rotary encoder in the solution. I have yet to determine whether this will replace a button or be an addition. This also removes the need for the two volume buttons so idk... I intend the final design to have 5-6 buttons and a rotary encoder. I went on the JayCar website and just scrolled through the list of components, I saw some cool things like LED bar graphs and thought that I could use that to display volume when it is being changed but that required like 11 pins just for itself so that wasn't gonna work out. Eventually I found an encoder that I thought was acceptable. The only problem is the shaft had a 6mm diameter and for whatever reason no-one stocks 6mm knobs; only stocking 1/4" knobs. After about an hour of furious google searching I came across an acceptable knob, on the way also finding rubber feet that I want to include in the final design.
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE3OSwicHVyIjoiYmxvYl9pZCJ9fQ==--8fd2169dfe02691d100e442c11a166ed2423c7f9/image.png)(ignore 1 star review; i read it and its just a skill issue)
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4MCwicHVyIjoiYmxvYl9pZCJ9fQ==--4d7b6ecaf7f0e41b0335c6eda403a1c0b8179c64/image.png)
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4OSwicHVyIjoiYmxvYl9pZCJ9fQ==--bc7d5ad580065b7c6e41f7d5b712c9957dbd4e8e/image.png)I already have enough wire so this should be fine. I also realised that for the final design to get accurate and clean readings from the inputs, I would need...
## Capacitors and Pulldown Resistors
So I need 6 pulldown resistors and 2 capacitors (as per rotary encoder docs).
An appropriate resistance is anything between 1k and 100k (according to google). Here are 8x 10k ohm resistors for 85 au cents:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4MiwicHVyIjoiYmxvYl9pZCJ9fQ==--c99d8ff8c6fa138040b01ba8a57b6ac10f03234e/image.png)
now for the capacitors, the docs recommend 100-200nF capacitors in this setup:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4MywicHVyIjoiYmxvYl9pZCJ9fQ==--963e0d3a0def614ec9c69b4406c98315fdf5554a/image.png)These are cheap and a polyester capacitor is appropriate for this application:
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4NCwicHVyIjoiYmxvYl9pZCJ9fQ==--ce50e9a309f6e23ae06876cc4f3acde5719620d0/image.png)yeah and the extra (1 or 2) resistor(s) can act as pullup for rotary encoder. sick.
## Updated CAD Model
I slightly repositioned the buttons to give me some more space for the dial
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE4OCwicHVyIjoiYmxvYl9pZCJ9fQ==--91dc479cfaaa59c67024873edca357e0c3745f1b/image.png)

### Updated BOM:
 - 1x $17.95 - Aluminium Case 115x65x30mm
 - 6x $6.95  - Metal Momentary SPST 
 - 1x $11.35 - Seeed XIAO ESP32-C3 
 - 1x $0.00  - 3D-Printed Plate Insert
 - 1x $9.95  - Rotary Encoder w/ Pushbutton
 - 2x $0.30  - 100nF Capacitor
 - 1x $2.15  - Rubber Feet 4pk.
 - 1x $6.75  - Aluminium Knob 20mm
Total: AUD $90.45

Quick little TODO:
 - Change 3D Printed Insert to add holder for rotary encoder PCB
 - Add Feet to CAD Model
 - Begin prototyping software backend and put some research into how to use board as HID.
![image.png](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6MjE5MCwicHVyIjoiYmxvYl9pZCJ9fQ==--4c6f95b1e4a954c5cd8bd14ce66ab7b222a147a6/image.png)
Software will need:
 - accept 6+1 button inputs and discrete rotary signals
 - appropriate debouncing for buttons
 - hid recognition??? ability to control windows media playback???
https://www.jaycar.com.au/sealed-diecast-aluminium-enclosure-115-x-65-x-30mm/p/HB5036
https://www.jaycar.com.au/metal-momentary-spst/p/SP0755
https://core-electronics.com.au/seeed-studio-xiao-esp32c3-tiny-mcu-board-with-wi-fi-and-ble-battery-charge-supported-power-efficiency-and-rich-interface.html
https://www.jaycar.com.au/rotary-encoder-switch-with-pushbutton/p/SR1230
https://www.jaycar.com.au/100nf-100vdc-polyester-capacitor/p/RG5125
https://core-electronics.com.au/little-rubber-bumper-feet-pack-of-4.html

# Finalizing Design + Software 31/10 ~3 Hours
### Finalizing Model
I added the final touches to the model to finish the design, it all looks good.
![image](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6NjkyNSwicHVyIjoiYmxvYl9pZCJ9fQ==--06176ee1be977b503511abface35d2b1360d2647/image.png)
See added the little feature to hold the rotary encoder, this prevents rotation and strain on the PCB when it is used. I also added rubber feet to the model, this doesn't really help with much, it just gives me a rough idea of the scale and location of the feet and the look of the final design.
Here's a schematic:
![image](/user-attachments/blobs/proxy/eyJfcmFpbHMiOnsiZGF0YSI6NjkyNywicHVyIjoiYmxvYl9pZCJ9fQ==--fb25e3f8f3c5021b900c7b10d296608ea50796b8/image.png)
I also mocked up some pseudocode and a rough program that I can fine tune once I have the hardware.
This project is now ready to ship! Huzzah!

FINAL BOM:
 - Capacitors, 0.90AUD*3=2.70AUD,https://www.jaycar.com.au/100nf-100vdc-polyester-capacitor/p/RG5125
 - Rotary Encoder, 9.95AUD,https://www.jaycar.com.au/rotary-encoder-switch-with-pushbutton/p/SR1230
 - Resistors, 0.85AUD,https://www.jaycar.com.au/10k-ohm-0-5-watt-metal-film-resistors-pack-of-8/p/RR0596
 - Momentary Switch, 6*6.96AUD,https://www.jaycar.com.au/metal-momentary-spst/p/SP0755
 - Aluminium Case, 17.95AUD,https://www.jaycar.com.au/sealed-diecast-aluminium-enclosure-115-x-65-x-30mm/p/HB5036
 - Rubber Feet, 2.15AUD,https://core-electronics.com.au/little-rubber-bumper-feet-pack-of-4.html
 - Microcontroller, 11.20AUD,https://core-electronics.com.au/seeed-studio-xiao-esp32c3-tiny-mcu-board-with-wi-fi-and-ble-battery-charge-supported-power-efficiency-and-rich-interface.html
 - 3D printed insert, 0AUD
 - total shipping, \~24AUD

**TOTAL = 111 AUD \~ 73 USD**
