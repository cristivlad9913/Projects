import requests
from bs4 import BeautifulSoup
import sqlite3
import csv
import time
import time
import datetime
from datetime import datetime
import os



url='https://www.worldometers.info/coronavirus/country/romania/'
page=requests.get(url)
soup=BeautifulSoup(page.text,'html.parser')
cases=soup.find_all('div',class_='maincounter-number')
lista=[]
for p in cases:
    lista.append(p.get_text())
a=lista[0]
b=lista[1]
c=lista[2]
a=a.replace("\n","")
b=b.replace("\n","")
c=c.replace("\n","")
a=a.replace(",","")
b=b.replace(",","")
c=c.replace(",","")

lista.clear()
lista.append(a)
lista.append(b)
lista.append(c)
lista.append(datetime.now())
with open("covid.csv","a+") as file:
    writer=csv.writer(file)
    writer.writerow(lista)

def functie(item,nume):
    connection = sqlite3.connect(nume)
    c = connection.cursor()
    sql = "CREATE TABLE IF NOT EXISTS date (id INTEGER,loc VARCHAR(30),nume VARCHAR(30),an INTEGER);"
    sql2 = "INSERT INTO date VALUES({},'{}','{}',{});".format(item[0], item[1],item[2],item[3])
    c.executescript(sql)
    c.executescript(sql2)
    connection.commit()
    connection.close()

def citire(nume):
    connection=sqlite3.connect(nume)
    c=connection.cursor()
    sql="SELECT * FROM date;"
    c.execute(sql)
    connection.commit()
    lista=[]

    for i in c.fetchall():
        lista.append(i)
    connection.close()
    return lista


lista=[(1,"Purcari","Chardonnay",2010),(2,"Samburesti","Merlot",2016),(3,"Cricova","Sauvignon",2010)]

for i in lista:
    functie(i,'baza.db')

date=citire('baza.db')
with open('date.csv',"a+") as file:
    writer=csv.writer(file)
    for i in date:
        writer.writerow(i)




path=input("path=")
lista=os.listdir(path)
lista2=[]
for i in lista:
    lista2.append(os.path.splitext(i)[1])

for i in lista2:
    if i=='':
        lista2.remove(i)

connection=sqlite3.connect("extensii.db")
c=connection.cursor()
sql = "CREATE TABLE IF NOT EXISTS extensii (id INTEGER,ext VARCHAR(30));"
c.execute(sql)
for i in range(len(lista2)):
    sql2 = "INSERT INTO extensii VALUES({},'{}');".format(i,lista2[i])
    c.execute(sql2)
connection.commit()
connection.close()
