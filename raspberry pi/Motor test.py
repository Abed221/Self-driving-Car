import serial
import time
if __name__ == '__main__':
    ser = serial.Serial('/dev/ttyACM1', 9600, timeout=1)
    ser.flush()
    while True:
        arr = bytearray(20)
        arr[0]=100
        arr[1]=100
        ser.write(arr)
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(5)
        arr[0]=255
        arr[1]=255
        ser.write(arr)
        line = ser.readline().decode('utf-8').rstrip()
        print(line)
        time.sleep(5)
