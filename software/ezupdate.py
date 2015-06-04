# #
# The MIT License (MIT)
# 
# Copyright (c) 2015 Pablo Bacho
# 
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
# 
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
# 
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
# #

import serial
import urllib2
import os
import sys
from subprocess import call

def download_file( url ):
    filename = url.split('/')[-1]
    u = urllib2.urlopen(url)
    f = open(filename, 'wb')
    meta = u.info()
    file_size = int(meta.getheaders("Content-Length")[0])
    print "Downloading: %s Bytes: %s" % (filename, file_size)

    file_size_dl = 0
    block_sz = 8192
    while True:
        buffer = u.read(block_sz)
        if not buffer:
            break

        file_size_dl += len(buffer)
        f.write(buffer)
        status = r"%10d  [%3.2f%%]" % (file_size_dl, file_size_dl * 100. / file_size)
        status = status + chr(8)*(len(status)+1)
        print status,
    
    f.close()
    return filename


def flash_cyacd( tool, cyacd ):
    print 'Ready to flash. Disconnect your EzTemp, short-circuit pins EN and 3.3V with a jumper, and reconnect the EzTemp.'
    try:
        input("Press enter to continue.")
    except SyntaxError:
        pass

    print 'Flash process started'
        
    ret = call(['./' + tool, '-p', cyacd])

    if ret == 0:
        print 'Success! Your EzTemp is up-to-date :)'
    else:
        print 'Oops! There was an error updating your EzTemp :('
    
    return ret



# Get hardware version
ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ser.write("v")
s = ser.read(4)
hardware = ord(s[1])
ser.close()
print 'Hardware version ' + str(hardware)

# Download required files
print 'Downloading files'
bootloaderhosttool = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/software/bootloaderhosttool")
os.chmod(bootloaderhosttool, 0755)

if hardware == 0:
    cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4245PVI-482/app_latest.cyacd")
elif hardware == 1:
    cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4245PVI-482/app_latest.cyacd")
elif hardware == 2:
    cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4124PVI-432/app_latest.cyacd")
else:
    print 'Error: hardware version unknown'
    sys.exit()
    
# Flashing
ret = flash_cyacd(bootloaderhosttool, cyacd)

# Error. Download the binary for the other hardware version in case the field was corrupted.
if ret != 0:
    print 'Trying to recover...'
    if hardware == 0:
        cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4124PVI-432/app_latest.cyacd")
    elif hardware == 1:
        cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4124PVI-432/app_latest.cyacd")
    elif hardware == 2:
        cyacd = download_file("https://github.com/fabricadigital/EzTemp-for-Raspberry-Pi/raw/master/firmware/binaries/CY8C4245PVI-482/app_latest.cyacd")
    else:
        print 'Error: This error shouldn\'t happen. Disconnect your EzTemp and leave the EN and 3.3V pins unconnected. Then reconnect and start again.'
        sys.exit()
    ret = flash_cyacd(bootloaderhosttool, cyacd)
    
ser = serial.Serial('/dev/ttyAMA0', 9600, timeout=1)
ser.write("v")
s = ser.read(4)
print 'Hardware version: ' + str(ord(s[1]))
print 'Firmware version: ' + str(ord(s[2]))
ser.close()