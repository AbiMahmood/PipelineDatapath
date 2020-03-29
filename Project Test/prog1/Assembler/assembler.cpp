#include <bits/stdc++.h>
#define checkBit(n,p) (bool)(n&(1<<p))
#include <bitset>
#include <iostream>
#include <sstream>
#include<conio.h>
using namespace std;




/*==========================================================================

                    A clever person solves a problem,
                        A wise person avoids it

============================================================================*/










map<string,string> getMap(string path)
{
    string word,value;
    map<string,string> m;
    ifstream file(path);
    while(file>>word>>value)
    {
        m[word] = value;
    }
    file.close();
    return m;
}







string decToBin(int num,int length)
{
    string result = "";
    for(int i=0;i<length;i++)
    {
        if(checkBit(num,i))
        {
            result = "1" + result;
        }
        else
        {
            result = "0" + result;
        }
    }
    return result;
}








string GetHexFromBin(string sBinary)
{
	string rest,tmp,chr = "";
	int len = sBinary.length()/4;
	chr = chr.substr(0,len);
	sBinary = chr+sBinary;
	for (int i=0;i<sBinary.length();i+=4)
	{
		tmp = sBinary.substr(i,4);
		if (!tmp.compare("0000"))
		{
			rest = rest + "0";
		}
		else if (!tmp.compare("0001"))
		{
			rest = rest + "1";
		}
		else if (!tmp.compare("0010"))
		{
			rest = rest + "2";
		}
		else if (!tmp.compare("0011"))
		{
			rest = rest + "3";
		}
		else if (!tmp.compare("0100"))
		{
			rest = rest + "4";
		}
		else if (!tmp.compare("0101"))
		{
			rest = rest + "5";
		}
		else if (!tmp.compare("0110"))
		{
			rest = rest + "6";
		}
		else if (!tmp.compare("0111"))
		{
			rest = rest + "7";
		}
		else if (!tmp.compare("1000"))
		{
			rest = rest + "8";
		}
		else if (!tmp.compare("1001"))
		{
			rest = rest + "9";
		}
		else if (!tmp.compare("1010"))
		{
			rest = rest + "A";
		}
		else if (!tmp.compare("1011"))
		{
			rest = rest + "B";
		}
		else if (!tmp.compare("1100"))
		{
			rest = rest + "C";
		}
		else if (!tmp.compare("1101"))
		{
			rest = rest + "D";
		}
		else if (!tmp.compare("1110"))
		{
			rest = rest + "E";
		}
		else if (!tmp.compare("1111"))
		{
			rest = rest + "F";
		}
		else
		{
			continue;
		}
	}
	return rest;
}


















int main()
{
    cout << "ABDULLAH MAHMOOD\n133-0639-042\n" <<endl;
    int val;
    string ins,op,r1,r2,r3,cmnt;
    map<string,string> R_TYPE,I_TYPE,J_TYPE,RegisterValue;   //Obtaining static values from storage
    R_TYPE = getMap("File/R_TYPE.txt");
    I_TYPE = getMap("File/I_TYPE.txt");
    J_TYPE = getMap("File/J_TYPE.txt");
    RegisterValue = getMap("File/RegisterValue.txt");
    ifstream inputFile("File/input.txt");   //ifstream inputFile("File/.txt");
    ofstream outputFile("File/output.txt"); //ofstream outputFile("File/.txt");
    ofstream outputFile2("File/output2.txt"); //ofstream outputFile("File/.txt");
    outputFile2 << "v2.0 raw" << endl;
    outputFile  << "v2.0 raw" << endl;










    while(getline(inputFile,ins))
    {
        stringstream ss;
        cout << ins << endl;
        //Checking if instruction is empty or not
        if(ins.size()==0)
        {
            cout << "Invalid: Instruction is empty\n" << endl;
            continue;
        }
        ss << ins;
        ss >> op;
        ss >> r1;

        if(op!="go")
        {
            if(r1[0]!='$')
            {
                cout << "Invalid: '$' sign is missing before rd\n" << endl;
                outputFile << "Invalid: '$' sign is missing before rd\n" << endl;
                continue;
            }
            else if(r1[r1.size()-1]!=',')
            {
                cout << "Invalid: ',' is missing after rd\n" << endl;
                outputFile << "Invalid: ',' is missing after rd\n" << endl;
                continue;
            }
            r1.erase(r1.end()-1);
        }

        //If operation code is R Type then the program will go in here
        if(R_TYPE.find(op)!=R_TYPE.end())
        {
            val = 0;
            if(op=="go")
            {
                r2 = r3 = "$zero";
                goto print;
            }

            ss >> r2;
            if(r2[0]!='$')
                {
                    cout << "Invalid: '$' sign is missing before rs\n" << endl;
                    outputFile << "Invalid: '$' sign is missing before rs\n" << endl;
                    continue;
                }
                else if(r2[r2.size()-1]!=',')
                {
                    cout << "Invalid: ',' is missing after rs\n" << endl;
                    outputFile << "Invalid: ',' is missing after rs\n" << endl;
                    continue;
                }
                r2.erase(r2.end()-1);

            ss >> r3;
            if(r3[0]!='$')
            {
                cout << "Invalid: '$' sign is missing before rt\n" << endl;
                outputFile << "Invalid: '$' sign is missing before rt\n" << endl;
                continue;
            }

            //Checking instruction validities
            print:
            if(r1=="$zero")
            {
                cout << "Invalid: $zero can not be used\n" << endl;
                outputFile << "Invalid: $zero can not be used\n" << endl;
            }

            else if(RegisterValue.find(r1)==RegisterValue.end())
            {
                cout << "Invalid: rd not found\n" << endl;
                outputFile << "Invalid: rd not found\n" << endl;
            }
            else if(RegisterValue.find(r2)==RegisterValue.end())
            {
                cout << "Invalid: rs not found\n" << endl;
                outputFile << "Invalid: rs not found\n" << endl;
            }
            else if(RegisterValue.find(r3)==RegisterValue.end())
            {
                cout << "Invalid: rt not found\n" << endl;
                outputFile << "Invalid: rt not found\n" << endl;
            }
            else if(val<0)
            {
                cout << "Invalid: value can not be neg\n" << endl;
                outputFile << "Invalid: value can not be neg\n" << endl;
            }
            else if(val>15)
            {
                cout << "Invalid: value is too large\n" << endl;
                outputFile << "Invalid: value is too large\n" << endl;
            }
            else if(ss>>cmnt&&(cmnt[0]!='/'||cmnt[1]!='/'))
            {
            	cout << "Invalid: comment structure not maintained\n" << endl;
            	outputFile << "Invalid: comment structure not maintained\n" << endl;
            }

            //Printing machine code if instruction is valid
            else
            {
               cout << R_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << RegisterValue[r3] << " "  << endl;
               cout << GetHexFromBin(R_TYPE[op]) << " " << GetHexFromBin(RegisterValue[r1]) << " " << GetHexFromBin(RegisterValue[r2]) << " " << GetHexFromBin(RegisterValue[r3]) << " "  << "\n" << endl;
               outputFile << R_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2] << " " << RegisterValue[r3] << endl;
               outputFile << GetHexFromBin(R_TYPE[op]) << " " << GetHexFromBin(RegisterValue[r1]) << " " << GetHexFromBin(RegisterValue[r2]) << " " << GetHexFromBin(RegisterValue[r3]) << "\n" << endl;
               outputFile2 << GetHexFromBin(R_TYPE[op]) << GetHexFromBin(RegisterValue[r1]) << GetHexFromBin(RegisterValue[r2]) << GetHexFromBin(RegisterValue[r3]) << endl;
            }
        }

         //If operation code is I Type then the program will go in here
        else if(I_TYPE.find(op)!=I_TYPE.end())
        {
        	val = -1;
        	if(op=="lw"||op=="sw")
        	{
        		ss >> val >> r2;
        		if(r2[0]!='(')
                {
                    cout << "Invalid: '(' is missing before rs\n" << endl;
                    outputFile << "Invalid: '(' is missing before rs\n" << endl;
                    continue;
                }
                else if(r2[r2.size()-1]!=')')
                {
                    cout << "Invalid: ')' is missing after rs\n" << endl;
                    outputFile << "Invalid: ')' is missing after rs\n" << endl;
                    continue;
                }
                else if(r2[1]!='$')
                {
                    cout << "Invalid: '$' sign is missing before rs\n" << endl;
                    outputFile << "Invalid: '$' sign is missing before rs\n" << endl;
                    continue;
                }
        		r2.erase(r2.begin());
        		r2.erase(r2.end()-1);

        		if(r1=="$zero")
                {
                    r1 = "";
                    cout << "Invalid: $zero cannot be used\n" << endl;
                    outputFile << "Invalid: $zero cannot be used\n" << endl;
                    continue;
                }
               /* else if(r2=="$zero")
                {
                    r2 = "";
                    cout << "Invalid: $zero cannot be used\n" << endl;
                    outputFile << "Invalid: $zero cannot be used\n" << endl;
                    continue;
                }*/
        	}

        	else
        	{

        		ss >> r2 >> val;
        		if(r2[0]!='$')
                {
                    cout << "Invalid: '$' sign is missing before rs\n" << endl;
                    outputFile << "Invalid: '$' sign is missing before rs\n" << endl;
                    continue;
                }

                else if(r2[r2.size()-1]!=',')
                {
                    cout << "Invalid: ',' is missing after rs\n" << endl;
                    outputFile << "Invalid: ',' is missing after rs\n" << endl;
                    continue;
                }

        		r2.erase(r2.end()-1);

        		if(op=="addi"||op=="andi"||op=="ori"||op=="xori"||op=="nand")
        		{

        		    if(r1=="$zero")
                    {
                        r1 = "";
                        cout << "Invalid: $zero can not be used\n" << endl;
                        outputFile << "Invalid: $zero can not be used\n" << endl;
                        continue;
                    }
                 }
            }
        	//Checking instruction validities
            if(RegisterValue.find(r1)==RegisterValue.end())
            {
                cout << "Invalid: rd not found\n" << endl;
                outputFile << "Invalid: rd not found\n" << endl;
            }
            else if(RegisterValue.find(r2)==RegisterValue.end())
            {
                cout << "Invalid: rs not found\n" << endl;
                outputFile << "Invalid: rs not found\n" << endl;
            }

            /*else if(op!="addi"&&op!="andi"&&op!="ori"&&op!="xori"&&val<0)
            {
                cout << "Invalid: value can not be neg\n" << endl;
                outputFile << "Invalid: value can not be neg\n" << endl;
            }*/
            else if(val>7) //2^4 = 16 //4 is imm bit
            {
                cout << "Invalid: value is too large [+7 to -8]\n" << endl;
                outputFile << "Invalid: value is too large\n" << endl;
            }
            else if(val<-8) //2^4 = 16 //4 is imm bit
            {
                cout << "Invalid: value is too small [+7 to -8]\n" << endl;
                outputFile << "Invalid: value is too small\n" << endl;
            }
            else if(ss>>cmnt&&(cmnt[0]!='/'||cmnt[1]!='/'))
            {
            	cout << "Invalid: comment structure not maintained\n" << endl;
            	outputFile << "Invalid: comment structure not maintained\n" << endl;
            }

            //Printing machine code if instruction is valid
            else
            {
            	cout << I_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2]<< " " << decToBin(val,4) << endl;
            	cout << GetHexFromBin(I_TYPE[op]) << " " << GetHexFromBin(RegisterValue[r1]) << " " << GetHexFromBin(RegisterValue[r2])<< " " << GetHexFromBin(decToBin(val,4)) << "\n" << endl;
                outputFile << I_TYPE[op] << " " << RegisterValue[r1] << " " << RegisterValue[r2]<< " " << decToBin(val,4) <<  endl;
            	outputFile << GetHexFromBin(I_TYPE[op]) << " " << GetHexFromBin(RegisterValue[r1]) << " " << GetHexFromBin(RegisterValue[r2]) << " " << GetHexFromBin(decToBin(val,4)) << "\n"  << endl;
            	outputFile2 << GetHexFromBin(I_TYPE[op]) << GetHexFromBin(RegisterValue[r1]) << GetHexFromBin(RegisterValue[r2]) << GetHexFromBin(decToBin(val,4))  << endl;

            }
        }
        else
        {
        	cout << "Invalid: Op code not found\n" << endl;
        	outputFile << "Invalid: Op code not found\n" << endl;
        }
    }
    inputFile.close();
}
