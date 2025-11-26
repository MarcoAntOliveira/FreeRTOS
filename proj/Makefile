# Makefile para rodar Flask, Ngrok e PlatformIO no mesmo terminal

FLASK_APP = src/app.py
FLASK_PORT = 5000
NGROK_CMD = ngrok
PIO_CMD = pio
VENV = amb/bin/activate
SHELL := /bin/bash



pio:
	@pio device monitor -b 115200
	
build:
	@pio run -t upload
	@pio device monitor -p /dev/ttyUSB0 -b 115200


ngrok:
	ngrok http --scheme=http  --scheme=https 5000 --host-header=localhost:5000

	
server:
	@python3 app.py