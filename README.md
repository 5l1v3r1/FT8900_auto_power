# FT8900_auto_power
Ignition Control for Yaesu FT8900 Mobile Radio

I am using this device in my radio more than 2 years.

You need to find 5v(which is allways active) and ground lines(look around mcu) and On-Off line tap (look around control cable).
Route a single trigger wire along power cables and attach it to ignition line of your car. Don't forget to use voltage dividers and filter capacitors for this line to get it below 5v.

When you turn on ignition, your radio will turn on and when you turn off the ignition, your radio will turn off.
If you want to disable(enable) this feature, turn on ignition while holding power button of your radio.
You can still control your radio using your power button.

Do not screw your radio, if you did, do not blame me.
