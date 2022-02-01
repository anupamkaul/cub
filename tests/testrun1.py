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
import sys
from datetime import date

def runtests():

	orig_stdout = sys.stdout
	tresult = open("testrun", "w") 
	sys.stdout = tresult # map printfs to file

	# python buffers output to files (like with printf)
	# but subprocess writes directly to files, not to Python buffer
	# so, to preserve chrono order of printfs to file I flush buffer to file for printf

	for dir, subdirs, files in os.walk('./'):

		print("\ndir: ", dir);
		print("subdirs: ", subdirs);

		testresname = "testrun" + str(date.today())
		print("test results : ", testresname)
		sys.stdout.flush()

		for file in files:

		 # if we need to log absolute paths:
		 # fileabspath = os.path.join(os.path.abspath(dir), file);
		 # print("File: ", file, "(", os.path.abspath(file), ") in ", filepath, " ", fileabspath)

			filepath = os.path.join(dir, file)

			if re.search("test_", filepath): 
				print("Running Test: ", file, "(", filepath, ")")
				sys.stdout.flush()
				result = subprocess.call(['../tiger', filepath], stdout=tresult, stderr=tresult)
				print("Finished execution!\n")
				sys.stdout.flush()

	
	tresult.close()
	sys.stdout = orig_stdout

def main():
	print("Cub test-runner on ", date.today(), "\n")
	runtests()
	print("End Run Cub test-runner on ", date.today(), "\n")

if __name__ == ' __main__':
	print ("Hello")
	main()

main()

