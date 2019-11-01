Seeed QTouch
-------------------------------------------------------------

<img src=https://statics3.seeedstudio.com/images/product/Grove-Q%20Touch%20Sensor.jpg width=400><img src=https://statics3.seeedstudio.com/product/Grove-Q%20Touch%20Sensor_02.jpg width=400>

[Grove-Q Touch Sensor](https://www.seeedstudio.com/s/Grove-Q-Touch-Sensor-p-1854.html)

LED Bar, common in volume display, is a common sensor component to display analog value. You can use a row of discrete LED lights to make division of this effect, you can also use our element mentioned here.

For more information, please refer to [wiki][1]

# Usage

1. To judge certain key if touched

		unsigned char isTouch(int key)		// key- 0~6, if touched return 1
2. Get touch state

   bits 0 to 6 indicate which keys are in detection, if any. Touched keys report as 1, untouched or disabled keys report as 0.

		unsigned char getState();

3. Get Touch Num

		int touchNum();

	if no touched, return -1. or will return the touched key number.

4. Set group for a key

	   setGroup(uint8_t key, uint8_t group);

	This is used to assign keys to group of which only one can be pressed at a time.
	Valid group numbers: 0~3, group 255 disables the key.

5. Query if the touch sensor IC is present

     int chipPresent();

	Returns 1 if the chip ID matches, 0 if not or no reply.
	
----
This software is written by Loovee for seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>



[1]:http://wiki.seeedstudio.com/Grove-Q_Touch_Sensor/



[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_LED_Bar)](https://github.com/igrigorik/ga-beacon)
