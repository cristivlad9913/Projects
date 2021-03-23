import requests
from bs4 import BeautifulSoup
import openpyxl
from openpyxl import Workbook
import datetime
import csv



def scriere(nume_fisier,date,err):
    if str(date)==date:
        err+=1
        return 0
    book=Workbook()
    book=openpyxl.load_workbook(nume_fisier)
    sheet=book.active
    sheet.append(date)
    book.save(nume_fisier)


def functie(soup):

        for i in soup.find_all('h1', class_='page-title'):
            titlu = i.get_text().replace("  ", "")
        supa = soup.find_all('div', class_="d-inline-flex w-100 mrg-btm-xs")
        for i in supa:
            pret_nou = i.find('p', class_="product-new-price").get_text().replace(" ", "")
            pret_nou=face1(pret_nou)
            pret_nou=int(pret_nou)/100
            break
        titlu=titlu.replace("\n","")
        supa = soup.find_all('div', class_='col-xs-4 col-sm-3 col-md-2 col-lg-2 text-center')
        for i in supa:
            review=i.find('p', class_='review-rating-data').get_text()
            review2=i.find('p', class_='small semibold font-size-sm text-muted').get_text()
            break

        return (titlu,pret_nou,review,review2,datetime.datetime.now())

def face1(string):
    string=string.replace(" ","")
    string=string.replace(" ","")
    string=string.replace("Lei","")
    string=string.replace("\n","")
    string2 = ""
    for i in string:
        if i>='0' and i<='9' or i==".":
            string2+=i
        if i=="%":
            break

    string=""
    for i in string2:
        if i!='.':
            string+=i

    return int(string)



url=['https://www.emag.ro/laptop-apple-macbook-air-13-cu-procesor-intelr-dual-coretm-i5-1-80ghz-13-3-8gb-128gb-ssd-intelr-hd-graphics-6000-rom-kb-silver-mqd32ro-a-as/pd/DRTGYSBBM/?ref=smart-history-ml_1_2&provider=rec&recid=rec_51_002c70c14851480bde54265ec47daa03f91d8d5361792fac7253aa190298dcf3_1597654639&scenario_ID=51',
     'https://www.emag.ro/laptop-apple-macbook-pro-13-touch-bar-procesor-intelr-coretm-i5-1-4ghz-8gb-128gb-ssd-intel-iris-plus-graphics-645-space-grey-int-kb-muhn2ze-a/pd/DN79K5BBM/?ref=graph_profiled_similar_default_1_3&provider=rec&recid=rec_49_a4462ae047eb26301ba9bf9f143d8ae185c5af20c7df20a15fa6712810ea2597_1597655272&scenario_ID=49',
     'https://www.emag.ro/frigider-cu-doua-usi-arctic-306-l-clasa-a-h-175-4-alb-ad6310/pd/DM5LVKBBM/?ref=graph_profiled_similar_default_1_5&provider=rec&recid=rec_49_1942a769d4b0c332cd12936bc05ec9b151ab9b5cec2fb9f89e7ac574d8e4fb6d_1597660823&scenario_ID=49',
     'https://www.emag.ro/televizor-led-diamant-80-cm-hd-32hl4300h-a/pd/DNKN41BBM/?ref=hp_prod-widget_flash_deals_1_1&provider=site']
err=0
lista=[]
for i in url:
    pag=requests.get(i)
    if pag.status_code==200:
        print("Site-ul a putut fi accesat cu succes!\n")
    elif pag.status_code >400:
        print("A aparut o problema\n")
    soup = BeautifulSoup(pag.text, 'html.parser')
    scriere('rezultate.xlsx',functie(soup),err)
    lista.append(functie(soup))

if err>0:
    print("Nu s-a putut face scraping-ul pe unul dintre site-uri")
else:
    print("Scraping-ul si extragerea informatiilor in xlsx a reusit")

print("doriti salvarea informatiilor si intr-un csv?")
answer=input("yes/no:").lower()
if answer=='no':
    print("ok,o zi buna!")
else:
    nume=input("numele fisierului.extensia=")
    with open(nume,'a+') as file:
        writer=csv.writer(file)
        for i in lista:
            if i!= str(i):
                writer.writerow(i)
    print("datele au fost salvate intr-un csv")
