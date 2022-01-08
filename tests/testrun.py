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
import re
import subprocess
from datetime import date

def runtests():
	for dir, subdirs, files in os.walk('./'):

		print("\ndir: ", dir);
		print("subdirs: ", subdirs);

		for file in files:

		 # if we need to log absolute paths:
		 # fileabspath = os.path.join(os.path.abspath(dir), file);
		 # print("File: ", file, "(", os.path.abspath(file), ") in ", filepath, " ", fileabspath)

			filepath = os.path.join(dir, file)

			if re.search("test", filepath): 
				print("Running Test: ", file, "(", filepath, ")")
				result = subprocess.run(['../tiger', filepath], stdout=subprocess.PIPE)
				result.stdout.decode('utf-8')
				print("Finished execution!")



def main():
	print("Cub test-runner on ", date.today(), "\n")
	runtests()

if __name__ == ' __main__':
	print ("Hello")
	main()

main()

