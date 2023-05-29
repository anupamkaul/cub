'''
.tig recursive test runner
-------------------------

scan all subdirs and files in this directory recursively
if file is of type *.tig then run it and log results

for now, identify - errors in the process, or lack of production of files as fails
we don't have a criteria for pass except that output was generated.a

Add more pass/fail as we add more stuff

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
import datetime

def runtests():

	orig_stdout = sys.stdout
	tresult = open("testresults", "w") 
	sys.stdout = tresult # map printfs to file

	# python buffers output to files (like with printf)
	# but subprocess writes directly to files, not to Python buffer
	# so, to preserve chrono order of printfs to file I flush buffer to file for printf

	print("test results on ", datetime.datetime.now())
	sys.stdout.flush()

	testpath = "./testruns" 

	if not os.path.exists(testpath): 
		os.mkdir(testpath);

	for dir, subdirs, files in os.walk('./'):

		print("\ndir: ", dir);
		print("subdirs: ", subdirs, "\n\n");
		sys.stdout.flush()

		for file in files:

			filepath = os.path.join(dir, file)
			newtestpath = testpath + filepath.strip(".")

		        # if we need to log absolute paths:
			#fileabspath = os.path.join(os.path.abspath(dir), file);
			#print("File: ", file, "(", os.path.abspath(file), ") in ", filepath, " ", fileabspath)

			if re.search(".tig$", filepath): 

				print("Running Test: ", file, "(", filepath, ") \ncmd : ../tiger ", filepath, "\ndump in folder ", newtestpath, "\n")
				sys.stdout.flush()

				if not os.path.exists(newtestpath): 
					os.makedirs(newtestpath);

				
				tresult_local = open("out", "w") 
				sys.stdout = tresult_local # map printfs to file

				print("Running Test: ", file, "(", filepath, ") \ncmd : ../tiger ", filepath, "\ndump in folder ", newtestpath, "\n")
				sys.stdout.flush()

				result = subprocess.call(['../tiger', filepath], stdout=tresult_local, stderr=tresult_local)

				print("Finished execution!\n")
				sys.stdout.flush()

				tresult_local.close()
				sys.stdout = tresult

				# copy test results to test folder
				result = subprocess.call(['mv', 'ldump.txt', newtestpath])
				result = subprocess.call(['mv', 'ydump.txt', newtestpath]) 
				result = subprocess.call(['mv', 'out', newtestpath]) 

				refsrc = file.replace(".tig", ".ref")
				result = subprocess.call(['cp', filepath, newtestpath + "/" + refsrc]) 


	
	tresult.close()
	sys.stdout = orig_stdout

def main():
	print("Cub test-runner on ", datetime.date.today(), "\n")
	runtests()
	print("Results in testresults \n")

main()

