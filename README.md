#Watermeter - S0 - Sensor

Sensor to create impulses from a watermeter.

The HOA1405-002 reflective sensor is mounted to a watermeter, pointing to a rotating disk under water, which has alternating black and reflective areas. The signal from the photo transistor is then read via an analog input of an Atmega328P (maybe a bit oversized). Via Arduino sketch the signal is analyzed and the Atmega328P creates an impulse (5ms) for each black-reflective transition via a digital output.

I'm currently using this sensor together with this [Arduino S0 sensor](https://github.com/mtiews/arduino-s0-sensor), which feeds the data to our Smarthome.py installation. In my Smarthome installation im counting the impulses (for our watermeter 30imp/liter) and display our water consumption in a Web UI and a MagicMirror.

Sensor is based on:
* a HOA1405-002 Honeywell reflective sensor
* a watermeter mount for the sensor
* an Atmega328P based circuit to read the sensor signals and generate the impulses
* an Arduino sketch and
* and simple case for the PCB.

![Circuit](circuit/watermeter.png "Circuit" "width:60%;")
![Watermeter](assets/watermeter.jpg "Watermeter" "width:50%")
![Watermeter](assets/watermeter_with_sensor_1.jpg "Watermeter" "width:50%")
![PCB](assets/pcb.jpg "PCB" "width:50%")

