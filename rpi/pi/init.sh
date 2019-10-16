#setting UART baudrate at startup
sudo stty -F /dev/ttyS0 raw 115200

#start reading temperatures
./t_read/t_read.sh

#
echo "Done"
