import machine
import utime

led_red=machine.Pin(14, machine.Pin.OUT)
led_yellow=machine.Pin(13, machine.Pin.OUT)
led_green=machine.Pin(12, machine.Pin.OUT)

while True:

    led_red.value(1)
    utime.sleep(5)
    led_yellow.value(1)
    utime.sleep(2)
    led_red.value(0)
    led_yellow.value(0)
    led_green.value(1)
    utime.sleep(5)
    led_green.value(0)
    led_yellow.value(1)
    utime.sleep(5)
    led_yellow.value(0)