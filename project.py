on = 1
from os import system
system('clear')
attempt = 1
import time
setpass = [0,0,0,0]
setpass[0] = raw_input("Please enter character 1 ")
setpass[1] = raw_input("Please enter character 2 ")
setpass[2] = raw_input("Please enter character 3 ")
setpass[3] = raw_input("Please enter character 4 ")
asterisk = '*'
putpass = [0,0,0,0]
while on:

	startpass = raw_input("Input asterisk to begin passcode: ")

	if startpass == asterisk:
		system('clear')
		putpass[0] = raw_input("Input character 1: ")
		if putpass[0] != asterisk:
			system('clear')
			putpass[1] = raw_input("Input character 2: ")
			if putpass[1] != asterisk:
				system('clear')
				putpass[2] = raw_input("Input character 3: ")
				if putpass[2] != asterisk:
					system('clear')
					putpass[3] = raw_input("Input character 4: ")
					if putpass[3] != asterisk:
						system('clear')
						print (putpass)

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

