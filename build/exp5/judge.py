#!/usr/bin/env python
import os
import random
from mod_python import util
from mod_python.util import redirect
from subprocess import *

fpath=os.path.abspath(__file__)
sfpath=fpath.split('/')
PATH=''
for x in sfpath[0:-1]:
        PATH=PATH+'/'+x
PATH=PATH+'/'


Language_select_html ={"c":"""<select name="language" id="codeId">

<option value="c" selected="selected"> C (gcc 4.3.2) </option>

<option value="cpp"> C++ (g++ 4.3.2) </option>

</select>""", "cpp":"""<select name="language" id="codeId">

<option value="c"> C (gcc 4.3.2) </option>

<option value="cpp" selected="selected"> C++ (g++ 4.3.2) </option>

</select>"""};



code_select_html ={
	"Problem1":"""<select name="codeId" id="probId">

<option value="Problem1" selected="selected"> 1  </option>

<option value="Problem2"> 2  </option>

</select>""","Problem2":"""<select name="codeId" id="codeId">

<option value="Problem1"> 1  </option>

<option value="Problem2" selected="selected"> 2  </option>

</select>"""


};

def getHint(codeId,HintNo):
	if(codeId=="Problem1"):
	  	dir = PATH + "Hints1/"
	elif(codeId=="Problem2"):
	  	dir = PATH + "Hints2/"
	
	try:
		F = open(dir+"Hint_"+str(HintNo)+".html","r");
		s = F.read()
		F.close()
	except:
		if(int(HintNo)==0):
			s=""
		else:
		 	s="No more Hints"
	return s;

def Compile(exename,language,codeName):
	if (language=="cpp"):
		cmd = "g++    -s -static -o  "+exename+"  "+codeName +" -lm";
	elif (language=="c"):
		cmd = "gcc    -s -static -o  "+exename+"  "+codeName + " -lm";
	p = Popen(cmd,shell=True,stdout=PIPE,stderr=STDOUT,close_fds=True);
	p.wait();
	status = p.stdout.read();
	return status
def getInputFileNames(directory):
	cmd = "ls "+directory+"/*.in";
	p = Popen(cmd,shell=True,stdout=PIPE,stderr=STDOUT,close_fds=True);
	p.wait();
	Files = p.stdout.read();
	Files = Files.strip();
	Files = Files.split('\n');
	return Files;
def index(req):	
	FormData = util.FieldStorage(req);
	langauge= FormData['language'];
	try:
		code = FormData['code'];
	except:
		code = ""
	codeId=FormData['codeId'];
	action = FormData['type']
	Hints = FormData['hintC']
	highHint = FormData['highHint']    
#	HighestHint = FormData['hintGenerate']
	#save the code in a file 
	codeName = PATH + "currentCode."+langauge;
	F = open(codeName,"w");
	F.write(code);
	F.close();
	#Compile the code now and keep the executable in a a variable exename
	exename = PATH+"current.out";
	
	compileErrors = Compile(exename,langauge,codeName);
	JudgeData_html="";
	if(action=="Compile" and compileErrors!=""):
			#return compilation error
			result = "Compile Error"
	elif(action=="Compile" and compileErrors==""):
			result = "Compilation successful"

	elif(action=="Run" and compileErrors==""):	
		#code compiled successfully
		#now have to execute current.out
		TEST_DIRECTORY = PATH +codeId  #directory where final-build cases are there
		InputTestFiles 	= getInputFileNames(TEST_DIRECTORY);
		JudgeData_html="""<table border="1" cellpadding="15" id="tableInpOut" >"""
		JudgeData_html+="""<tr>
		<td> Input Data </td> 
		<td> Expected Output </td>
		<td> Code Output </td>
		<td> Result </td>
		<td> Remarks </td>
		</tr>"""

		for i in InputTestFiles:
			Input =  i #Input File where the final-build cases are there
			JudgeData_html+="<tr>";	
			F=open(Input,"r");
			JudgeData_html+="<td>"+F.read()+"</td>"
			F.close();
			ExpectedOutput = i[:-3]+".out" #Expected Output
			F = open(ExpectedOutput,"r");
			EO = F.read();
			JudgeData_html+="<td>"+EO+"</td>";
			F.close();
			
			memoryLimit = 32 * 1024;#32 MB
			timeLimit = 1 #1sec
			Output = TEST_DIRECTORY+"/temp.out";
			cmd = PATH+"sandbox -a2 -f -m %d -t %d -i %s -o %s %s" % (memoryLimit,timeLimit,Input,Output,exename)


			p = Popen(cmd,shell=True,stdout=PIPE,stderr=STDOUT,close_fds=True);
			p.wait();
			F = open(Output,"r");
			O = F.read();
			JudgeData_html+="<td>"+O+"</td>";
			F.close();
		
			status = p.stdout.read().strip().split('\n')[0]
			if status.split(' ')[0] == "OK":
				if EO==O:
					result = "Accepted!!";
					JudgeData_html+="<td> Passed </td>"
				else:
					result = "Wrong Answer"
					JudgeData_html+="<td> Failed </td>"
					JudgeData_html+="<td> Check your algo </td>"
					JudgeData_html+="</tr>";	
					break;
			else:
				JudgeData_html+="<td> Failed </td>"
				if status.split(' ')[0]=="Caught":
					result = "Segmentation Fault"
				elif(status=="Time limit exceeded"):
					result = "Time Limit Exceeded";
				else:
					result = "Run Time Error";
				JudgeData_html+="<td> "+result+" </td>"
				JudgeData_html+="</tr>";	
				break;
			JudgeData_html+="</tr>";	
		JudgeData_html+="</table>"
	elif(action=="Run" and compileErrors!=""):
		result = "Compile Error"

	CompileError="<br><br>"
	Results_Tests_Cases=""
	if(result!="Accepted!!"):
		if(result=="Compile Error"):
			result = """<center> <p style="color:red">"""+result+""" </p> </center>"""
			compileErrors = compileErrors.split('\n');
			for i in compileErrors:
				x = i.find(":");
				CompileError+=i[x-1:]+"<br/>"
		else:
			if(action=="Compile"):
				result = """<center> <p style="color:green">"""+result+""" </p> </center>"""
			if(action=="Run"):
				Results_Tests_Cases=JudgeData_html;
				result = """<center> <p style="color:red">"""+result+""" </p> </center>"""
			
	else:
		result = """<center> <p style="color:green">"""+result+""" </p></center>"""
		Results_Tests_Cases=JudgeData_html;

	F = open(PATH+"content1.html","r");
	returnValue = F.read();
	F.close();
	returnValue+=result;

	F = open(PATH+"content1_1.html","r");
	returnValue +=F.read();
	F.close();
	returnValue+=code;

	F = open(PATH+"content1_2.html","r");
	returnValue+=F.read();
	F.close();
	returnValue+=Language_select_html[langauge];
	F = open(PATH+"content1_3.html","r");
	returnValue+=F.read();
	F.close();
	returnValue+=code_select_html[codeId]
	
	F=open(PATH+"content2.html","r");
	returnValue+=F.read();
	F.close();
	returnValue+=CompileError+Results_Tests_Cases;

	F=open(PATH+"content2_1.html","r");
	returnValue+=F.read();
	F.close();
	returnValue+=getHint(codeId,Hints);

	F=open(PATH+"content3.html","r");
	returnValue+=F.read();
	F.close();
	returnValue+=str(highHint);

	F=open(PATH+"content3_1.html","r");
	returnValue+=F.read();
	F.close();

	random.seed(None);
	i=0;len_string=9;randomstring="";
	while(i<len_string):
		randomstring+=str(random.randint(0,9));
		i+=1;
	submissionName="submission" + randomstring+".html";

	F = open(PATH+submissionName,"w");
	F.write(returnValue);
	F.close();
	redirect(req,submissionName);
