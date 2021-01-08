# ASCII-Art

#### Step 1
Import the image and resize if necessary using OpenCV.

#### Step 2
Scan every single pixel in the image and convert them to grayscale, the reason being explained in the next step. A color pixel (RGB) has 
3 distinct channels: (120,82,8), (8,197,225), etc. Meanwhile a grayscale pixel only has 1 channel: (77,77,77), (150,150,150), etc. There are several algorithms to 
convert into grayscale but here is a good explanation -> [link](https://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/).

#### Step 3
The reason to convert to grayscale is to be able to map an individual pixel to an ASCII character by brightness/darkess. A grayscale with a lower value closer 
to 0 is darker/more black, while a grayscale with a higher value closer to 255 is brighter/more white. Likewise, the ASCII character "#" is darker than say 
"^". There are in depth ways to code this mapping procedure, but for sake of simplicity I simply eyeballed the darkness/brightness of the ASCII characters that
I used and mapped them to corresponding brightness/darkness levels of the individual pixels.

#### Step 4
A nested loop and several condtional statements allows us to print the ASCII art to the console window. I set the resolution of the photo high enough and the font
of the console window low enough where the resulting image is detailed.

<br /><br />

*Side note - another cool feature of the project is being able to continuously capture images from an external device/webcam, sort of like burst photos, and then converting them in realtime.
Obviously, it takes some time for the compiler to convert the image into ASCII art, but with a low enough resolution to convert, we could capture a new image every
1-2 seconds and convert them in realtime.


<br /><br /><br />
![screenshot](https://github.com/justinkacherian/ASCII-Art/blob/main/ex-images/zebra.jpg)
<br /><br />
![screenshot](https://github.com/justinkacherian/ASCII-Art/blob/main/ex-images/Capture.JPG)
<br /><br />
![sceenshot](https://github.com/justinkacherian/ASCII-Art/blob/main/ex-images/Capture2.JPG)
<br /><br />
![screenshot](https://github.com/justinkacherian/ASCII-Art/blob/main/ex-images/Capture4.JPG)
<br /><br />
![screenshot](https://github.com/justinkacherian/ASCII-Art/blob/main/ex-images/Capture3.JPG)
<br /><br />
