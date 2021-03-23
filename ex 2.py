import openpyxl
from openpyxl import Workbook

book=Workbook()
book=openpyxl.load_workbook('afaceri.xlsx')
sheet=book.active
lista=[[2002,230000],[2011,280000],[2012,310000],[2013,320000],[2014,350000],[2015,310000],[2016,380000],[2017,400000]]
for i in lista:
    sheet.append(i)

sheet['d1']=sum(i[1] for i in lista)
sheet['d1'].font=openpyxl.styles.Font(size=12,bold=True,italic=True)
book.save('afaceri.xlsx')