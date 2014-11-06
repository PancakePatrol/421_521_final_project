on = 1
from os import system
system('clear')
attempt = 1
import time
setpass = raw_input("Please enter password: ")
while on:

	putpass = raw_input("Tell me the password again: ")

	if setpass == putpass:
		print "Good job!"
		attempt = 1
		time.sleep(2)
		print "Opening door... Have a nice day!"
		time.sleep(2)
		print "Closing door..."
		time.sleep(5)
		print "System ready!"
	elif attempt <= 3:
		attempt = attempt + 1
		time.sleep(1)
		left = 4 - attempt
		print ("Wrong! %d attempt(s) left!") % left
	else:
		print("Too many attempts...")
		system('say Alert! Alert! Possible intuder alert!')
		print("Locking out...")
		print("15 Seconds...")
		time.sleep(5)
		print("10 Seconds...")
		time.sleep(5)
		print("5 Seconds...")
		time.sleep(2)
		print("3 Seconds...")
		time.sleep(2)
		print("Reverting...")
		attempt = 1
		time.sleep(1)
