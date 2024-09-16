from mod_python import util
import os
fpath=os.path.abspath(__file__)
sfpath=fpath.split('/')
PATH=''
for x in sfpath[0:-1]:
        PATH=PATH+'/'+x
PATH=PATH+'/'

def index(req,qNo,hintNo,sid):
        if(qNo=="1"):
                dir = PATH + "Hints1/"
        elif(qNo=="2"):
                dir = PATH + "Hints2/"
        try:
                F = open(dir+"Hint_"+hintNo+".html","r");

                s =  F.read()
                
                F.close()
        except:
                s = 'Failed to load' ;
	return s;
