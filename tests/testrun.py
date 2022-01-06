'''
scan all files in this directory and recursively
if the name contains 'test' anywhere, its a test
run it and scan for output
for now, identify - errors in the process, or lack of production of files as fails
we don't have a criteria for pass except that output was generated. Add more pass/fail as we add more stuff
report fail or pass
'''

'''
make sure the correct Conda Init is enabled
(see my .bashr)
(i.e. /home/anupam/miniconda3py38/bin/python)
'''

import os

from datetime import date

def runtests():
	for subdirs, dirs, files in os.walk('./'):

		print("dirs: ", dirs, "\n");
		print("subdirs: ", subdirs, "\n");

		for file in files:
			print("File: ", file)



def main():
	print("Cub test-runner on ", date.today(), "\n")
	runtests()

if __name__ == ' __main__':
	print ("Hello")
	main()

main()

