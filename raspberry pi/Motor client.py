import socket
import serial

HOST = input('enter ip address: ')
PORT = int(input('enter port: '))
dev = input('enter dev: ')
arduinoPath = f'/dev/{dev}'

ser =  serial.Serial(arduinoPath, 9600, timeout=1)
ser.flush()
with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))
    
    while True:
        data = s.recv(1024)
        arr= bytearray(20)
        arr[0]=data[0]
        arr[1]=data[1]
        ser.write(arr)
        
        print(data[0], data[1])

