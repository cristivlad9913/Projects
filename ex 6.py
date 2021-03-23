import random
import string
import sqlite3
a=input("first:")
b=input("second:")
c=input("third:")
id=int(input("id="))
lista_util=[]
lista=list(string.printable)
n=random.randint(8,15)
def verificare(string):
    litera_mare=0
    cifra=0
    litera_mica=0
    char=0
    for i in string:
        if i.isalpha():
            if i.isupper():
                litera_mare=1
            if i.isupper()==False:
                litera_mica=1
        if i.isdigit():
            cifra=1
        if i.isdigit()==False and i.isalpha()==False:
            char+=1
    if char>=2 and litera_mare==1 and litera_mica==1 and cifra==1 and len(string)>=8:
        return 1
    return 0
lista_util.append(a)
lista_util.append(b)
lista_util.append(c)
k=n-3
string=""
ok=0
lista.remove(" ")
lista.remove("`")
lista.remove("\n")
lista.remove(",")
lista.remove(".")
lista.remove("\x0b")
lista.remove("\x0c")
lista.remove("\t")
lista.remove("\r")
while ok==0:
    aux=random.sample(lista,random.randint(6,15))
    aux+=lista_util
    random.shuffle(aux)
    for i in aux:
        string+=i
    if verificare(string)==0:
        string=""
        aux.clear()
    if verificare(string)==1:
        ok=1

connection=sqlite3.connect("date.db")
c=connection.cursor()
sql="CREATE TABLE IF NOT EXISTS parole (id INTEGER,pass VARCHAR(30));"
sql2="INSERT INTO parole VALUES({},'{}');".format(id,string)
c.executescript(sql)
c.executescript(sql2)
connection.commit()
connection.close()