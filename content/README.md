# OpenPLC Arduino Uno Slave
### Youtube Reference
#### Learn PLC Programming Without a PLC Using OpenPLC and Arduino Uno (Slave Device)
<p align="center">
  <a href="https://www.youtube.com/watch?v=iFOY72zAw7g" target="_blank">
    <img src="https://img.youtube.com/vi/iFOY72zAw7g/0.jpg" alt="YouTube Video Thumbnail" width="480" />
  </a>
</p>
Click the image above to watch the video


##### 1. Download and Upload Arduino Runtime
You can download from this github.
Original page:
```
https://openplcproject.github.io/runtime/arduino/
```

##### 2. Run Ubuntu, and Arduino Port Setting
Open Power Shell as Administrator
1. Install usbipd di Windows
```
winget install usbipd
```
Restart Windows
2. Get USB List
```
usbipd list
```
Example Output:
```
PS C:\WINDOWS\system32> usbipd list
Connected:
BUSID  VID:PID    DEVICE                                                        STATE
2-10   8087:0026  Intel(R) Wireless Bluetooth(R)                                Not shared
3-4    0b95:1790  ASIX USB to Gigabit Ethernet Family Adapter                   Not shared
4-3    1a86:7523  USB-SERIAL CH340 (COM10)                                      Not shared
4-5    2109:8888  USB Billboard Device                                          Not shared
5-3    05e3:0751  USB Mass Storage Device                                       Not shared

```
3. Bind USB device to usbipd (Once per device)
```
usbipd bind --busid 4-3
```

4. Attach USB ke WSL (Ubuntu)
Before run this command, make sure ubuntu already running
```
usbipd attach --wsl --busid 4-3
```
Output:
```
usbipd: info: Using WSL distribution 'Ubuntu-22.04' to attach; the device will be available in all WSL 2 distributions.
usbipd: info: Loading vhci_hcd module.
usbipd: info: Detected networking mode 'nat'.
usbipd: info: Using IP address 172.27.192.1 to reach the host.
```

5. Check on Ubuntu
```
ls /dev/tty*
```
Example port:
```
/dev/ttyUSB0 (USB-Serial)
/dev/ttyACM0 (Arduino)
```

If you want to detach port:
```
usbipd detach --busid 4-3
```


##### 3. Add Salve Device on OpenPLC Runtime

##### 4. Compile Ladder to OpenPLC Runtime
