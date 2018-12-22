import json
import requests
import goslate
import time

par_for_get = {
	
	"access_token" : "6fbbd88d478dd359406e779131fb79d2f018a971908f331a9f38c3cd22de40ae92110020d93e256be51fe",
	"count" : "1",
	"user_id" : 129642993,
	"v" : "5.80"

}

def kek(data, deep):

	#for i in data:
		#print(str(data[0] + ' :key; val: ' + str(data) + '\n' + '\n'))
		#print(data)

	#file2.write(str(type(data)) + '\n')
	#if type(data) is str:
		#file2.write("str: " + data + '\n');


	#if type(data) is list:
	#	file2.write('array: ' + data + '\n')

	#file2.write(str(data) + '\n')
	#file2.write('now: ' + str(data) + ' type::: ' + str(type(data)) + '\n\n')


	if deep < 3:
		if type(data) is dict: 
			for key, value in data.items():

				file2.write(str(key) + '$$$' + str(value) + '\n')
			
				kek(value, deep + 1)
				kek(key, deep + 1)

		if type(data) is list:
			for i in data:
				kek(i, deep + 1)

		if type(data) is tuple:
			for i in data:
				kek(i, deep + 1)



#z = requests.get("https://api.vk.com/method/messages.getHistory",params = par_for_get)
#data = json.loads(z.text)


#file = open('C:\\DISK D\\anime\\my_json.json')
#z1 = file.read()
#file.close()

#with open('C:\\DISK D\\anime\\my_json.json') as json_data:
with open('C:\\DISK D\\selenium-server-standalone-3.141.59\\org\\openqa\\selenium\\firefox\\webdriver_prefs.json') as json_data:
	z = json.load(json_data)

file2 = open('C:\\DISK D\\anime\\respone.txt', 'w')

print(str(type(z)))

file2.write(str(z))

#print(z)
kek(z, 0)


