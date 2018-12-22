import json
import requests
import goslate
import time
import os

def dfs(data, deep):

	#print('START PARS!!!!!!!!!!!!!!!!!!!!!!!!!!')

	if deep < 3:
		if type(data) is dict: 
			for key, value in data.items():

				global file2
				file2.write(str(key) + '$$$' + str(value) + '\n')
			
				dfs(value, deep + 1)
				dfs(key, deep + 1)

		if type(data) is list:
			for i in data:
				dfs(i, deep + 1)

		if type(data) is tuple:
			for i in data:
				dfs(i, deep + 1)


def start_global_find(way):
	print('IN global FIND WAY: ' + way)
	with open(way, encoding="utf8") as json_data:
		z = json.load(json_data)
	#print(z)


	a = len(way)

	new_way = way[0:a - 4]
	global file2
	file2 = open(new_way + 'txt', 'w', encoding='utf8')

	#file2.write(str(z))
	dfs(z, 0)
	file2.close()
	print('success write! path:' + way)


#for i in z:
	#print(i + ' type=' + str(type(i)))
123123asds

def kek(all_way):

	#print(all)

	if os.path.isdir(all_way):
		now = os.listdir(all_way)
		for i in now:
			#print(now)
			#print(all_way + ' + $$ + ' + i)
			kek(all_way + '\\\\' + i)
	else:
		a = len(all_way)
		if str(all_way[a - 5:a]) == '.json':
			#file2.write(all_way + '\n')
			#print('start in: ' + all_way)
			start_global_find(all_way)


path = 'C:\\\\DISK D'
kek(path)


#start_global_find('C:\\DISK D\\1239\\steam\\clientui\\localization\\shared_arabic.json')

