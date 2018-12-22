import json
import requests
import goslate
import time
import os

def kek(all_way):

	if os.path.isdir(all_way):
		now = os.listdir(all_way)
		for i in now:
			#kek(all_way + '\\\\' + i)
			kek(all_way + '/' + i)
	else:
		a = len(all_way)
		if str(all_way[a - 5:a]) == '.json':
			file3.write(all_way + '\n')
	


#path = 'C:\\\\DISK D\\\\Kill_me'
path = '/home/user/Work/control'

#path_for_write = 'C:\\DISK D\\anime\\response1.txt'
path_for_write = '/home/user/Work/respone1.txt'
file3 = open(path_for_write, 'w')

kek(path)


#start_global_find('C:\\DISK D\\1239\\steam\\clientui\\localization\\shared_arabic.json')

