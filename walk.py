import os
import json

z = os.walk('C:\\DISK D')
print(str(type(z)))
print(z)

#for i in z:
	#print(i)
	#for j in i:
		#print(type(j))
		#if type(j) is not str:
			#print(j)
			#a = len(j)
			#if j[a - 4:a] == 'json':
				#print(j)

file2 = open('C:\\DISK D\\anime\\respone.txt', 'w')

def kek(data, way):

	#print(data)
	#print(str(type(data)))
	#file2.write(str(data) + ' ' + str(type(data)) + '\n')

	#if type(data) is str: way += data

	if type(data) is str:
		a = len(data)
		if data[a - 5:a] == '.json':
			file2.write(data + ' $$$ ' + way + '\n')

	if type(data) is list or type(data) is tuple:
		for i in data: 
			if type(i) == str: way += i
			else: 
				if len(i) > 0: way += i[]

			kek(i, way)

for i in z: kek(i, '')