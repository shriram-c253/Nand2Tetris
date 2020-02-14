# include <bits/stdc++.h>

# define ssr substr
# define pb push_back

using namespace std;

int number(string s) 
{
	if (s[0] >= '0' && s[0] <= '9')
		return 1;
	else
		return 0;
}

int symbol(map <string,int> &stb, string s)
{
	if(s == "SP")
		return 1;
	for (auto i : stb)
		if (i.first == s)
			return 1;
	return 0;
}

string Binary(string s) 
{
	int x = stoi(s);
	string ans;
	while(x)
	{
		if(x % 2)
			ans = '1' + ans;
		else ans = '0' + ans;
		x /= 2;
	}
	return ans;
}


string itos(int i) 
{
	ostringstream s;
	s << i;
	return s.str();
}

void RemComments(string & s)
{
	for(int i = 0; i < s.length(); i++)
		if(s[i] == ' ')
		{
			s.erase(i, 1);
			i--;
		}
		else if(s[i] == '/' && s[i + 1] == '/')
		{
			s.erase(i);
			s.insert(i, " ");
			break;
		} 
}

string CInstruction(string s) 
{
	s = s.substr(0, s.find(" ", 0));
	string out = "111", ins39, ins1012, ins1315;
	int ss = s.find("=", 0);
	if (ss > -1 && ss < s.length())
	{
		if (s.substr(ss + 1, 3) == "D|M")
			ins39 = "1010101";
		else if (s.substr(ss + 1, 3) == "D|A")
			ins39 = "0010101";
		else if (s.substr(ss + 1, 3) == "D&A")
			ins39 = "0000000";
		else if (s.substr(ss + 1, 3) == "D&M")
			ins39 = "1000000";
		else if (s.substr(ss + 1, 3) == "A-D")
			ins39 = "0000111";
		else if (s.substr(ss + 1, 3) == "M-D")
			ins39 = "1000111";
		else if (s.substr(ss + 1, 3) == "D+1")
			ins39 = "0011111";
		else if (s.substr(ss + 1, 3) == "A+1")
			ins39 = "0110111";
		else if (s.substr(ss + 1, 3) == "M+1")
			ins39 = "1110111";
		else if (s.substr(ss + 1, 3) == "D-1")
			ins39 = "0001110";
		else if (s.substr(ss + 1, 3) == "A-1")
			ins39 = "0110010";
		else if (s.substr(ss + 1, 3) == "M-1")
			ins39 = "1110010";
		else if (s.substr(ss + 1, 3) == "D+A")
			ins39 = "0000010";
		else if (s.substr(ss + 1, 3) == "D+M")
			ins39 = "1000010";
		else if (s.substr(ss + 1, 3) == "D-A")
			ins39 = "0010011";
		else if (s.substr(ss + 1, 3) == "D-M")
			ins39 = "1010011";
		else if (s.substr(ss + 1, 2) == "-1")
			ins39 = "0111010";
		else if (s.substr(ss + 1, 2) == "!D")
			ins39 = "0001101";
		else if (s.substr(ss + 1, 2) == "!A")
			ins39 = "0110001";
		else if (s.substr(ss + 1, 2) == "!M")
			ins39 = "1110001";
		else if (s.substr(ss + 1, 2) == "-D")
			ins39 = "0001111";
		else if (s.substr(ss + 1, 2) == "-A")
			ins39 = "0110011";
		else if (s.substr(ss + 1, 2) == "-M")
			ins39 = "1110011";
		else if (s.substr(ss + 1, 1) == "0")
			ins39 = "0101010";
		else if (s.substr(ss + 1, 1) == "1")
			ins39 = "0111111";
		else if (s.substr(ss + 1, 1) == "D")
			ins39 = "0001100";
		else if (s.substr(ss + 1, 1) == "A")
			ins39 = "0110000";
		else if (s.substr(ss + 1, 1) == "M")
			ins39 = "1110000";
	}
	else
	{
		if (s.find("D|M", 0) >= 0 && s.find("D|M", 0) < s.length())
			ins39 = "1010101";
		else if (s.find("D|A", 0) >= 0 && s.find("D|A", 0) < s.length())
			ins39 = "0010101";
		else if (s.find("D&A", 0) >= 0 && s.find("D&A", 0) < s.length())
			ins39 = "0000000";
		else if (s.find("D&M", 0) >= 0 && s.find("D&M", 0) < s.length())
			ins39 = "1000000";
		else if (s.find("A-D", 0) >= 0 && s.find("A-D", 0) < s.length())
			ins39 = "0000111";
		else if (s.find("M-D", 0) >= 0 && s.find("M-D", 0) < s.length())
			ins39 = "1000111";
		else if (s.find("D+1", 0) >= 0 && s.find("D+1", 0) < s.length())
			ins39 = "0011111";
		else if (s.find("A+1", 0) >= 0 && s.find("A+1", 0) < s.length())
			ins39 = "0110111";
		else if (s.find("M+1", 0) >= 0 && s.find("M+1", 0) < s.length())
			ins39 = "1110111";
		else if (s.find("D-1", 0) >= 0 && s.find("D-1", 0) < s.length())
			ins39 = "0001110";
		else if (s.find("A-1", 0) >= 0 && s.find("A-1", 0) < s.length())
			ins39 = "0110010";
		else if (s.find("M-1", 0) >= 0 && s.find("M-1", 0) < s.length())
			ins39 = "1110010";
		else if (s.find("D+A", 0) >= 0 && s.find("D+A", 0) < s.length())
			ins39 = "0000010";
		else if (s.find("D+M", 0) >= 0 && s.find("D+M", 0) < s.length())
			ins39 = "1000010";
		else if (s.find("D-A", 0) >= 0 && s.find("D-A", 0) < s.length())
			ins39 = "0010011";
		else if (s.find("D-M", 0) >= 0 && s.find("D-M", 0) < s.length())
			ins39 = "1010011";
		else if (s.find("-1", 0) >= 0 && s.find("-1", 0) < s.length())
			ins39 = "0111010";
		else if (s.find("!D", 0) >= 0 && s.find("!D", 0) < s.length())
			ins39 = "0001101";
		else if (s.find("!A", 0) >= 0 && s.find("!A", 0) < s.length())
			ins39 = "0110001";
		else if (s.find("!M", 0) >= 0 && s.find("!M", 0) < s.length())
			ins39 = "1110001";
		else if (s.find("-D", 0) >= 0 && s.find("-D", 0) < s.length())
			ins39 = "0001111";
		else if (s.find("-A", 0) >= 0 && s.find("-A", 0) < s.length())
			ins39 = "0110011";
		else if (s.find("-M", 0) >= 0 && s.find("-M", 0) < s.length())
			ins39 = "1110011";
		else if (s.find("0", 0) >= 0 && s.find("0", 0) < s.length())
			ins39 = "0101010";
		else if (s.find("1", 0) >= 0 && s.find("1", 0) < s.length())
			ins39 = "0111111";
		else if (s.find("D", 0) >= 0 && s.find("D", 0) < s.length())
			ins39 = "0001100";
		else if (s.find("A", 0) >= 0 && s.find("A", 0) < s.length())
			ins39 = "0110000";
		else if (s.find("M", 0) >= 0 && s.find("M", 0) < s.length())
			ins39 = "1110000";
	}
	int sss = s.find(";", 0);
	if (s.substr(sss + 1, 3) == "JGT")
		ins1315 = "001";
	else if (s.substr(sss + 1, 3) == "JEQ")
		ins1315 = "010";
	else if (s.substr(sss + 1, 3) == "JGE")
		ins1315 = "011";
	else if (s.substr(sss + 1, 3) == "JLT")
		ins1315 = "100";
	else if (s.substr(sss + 1, 3) == "JNE")
		ins1315 = "101";
	else if (s.substr(sss + 1, 3) == "JLE")
		ins1315 = "110";
	else if (s.substr(sss + 1, 3) == "JMP")
		ins1315 = "111";
	else
		ins1315 = "000";
	if (ss > -1 && ss < s.length())
	{
		string d3, d2, d1;
		int fM = s.find("M", 0);
		if (fM > -1 && fM < ss)
			d3 = "1";
		else
			d3 = "0";
		int fD = s.find("D", 0);
		if (fD > -1 && fD < ss)
			d2 = "1";
		else
			d2 = "0";
		int fA = s.find("A", 0);
		if (fA > -1 && fA < ss)
			d1 = "1";
		else
			d1 = "0";
		ins1012 = d1 + d2 + d3;
	}
	else
		ins1012 = "000"; 
	out = out + ins39 + ins1012 + ins1315;
	return out;
}

int main(int argc, char *argv[])
{
	ifstream f1(argv[argc - 1]);
	string ff = argv[argc - 1];
	int ddl = ff.find(".", 0);
	string off = ff.substr(0, ddl) + ".hack";
	ofstream f2(off.c_str());
	map <string, int> stb;
	stb["R0"] = 0;
	stb["R1"] = 1;
	stb["R2"] = 2;
	stb["R3"] = 3;
	stb["R4"] = 4;
	stb["R5"] = 5;
	stb["R6"] = 6;
	stb["R7"] = 7;
	stb["R8"] = 8;
	stb["R9"] = 9;
	stb["R10"] = 10;
	stb["R11"] = 11;
	stb["R12"] = 12;
	stb["R13"] = 13;
	stb["R14"] = 14;
	stb["R15"] = 15;
	stb["SCREEN"] = 16384;
	stb["KBD"] = 24576;
	stb["SP"] = 0;
	stb["LCL"] = 1;
	stb["ARG"] = 2;
	stb["THIS"] = 3;
	stb["THAT"] = 4;
	int ssz = 22, PC = 0, rl = 16;
	string s;
	while (getline(f1, s))
	{ 
		RemComments(s);
		if ((s.substr(0, 1) == "(") && !(symbol(stb, s.substr(1, s.find(")", 0) - 1))))
		{
			stb[s.substr(1, s.find(")", 0) - 1)] = PC;
			ssz++;
		}
		if (s.substr(0, 1) != "/" && s.substr(0, 1) != "(" && s.substr(0, 1) != "")
			PC++;
	}
	f1.open(argv[argc - 1]);
	while (getline(f1, s))
		RemComments(s);
		if (s.substr(0, 1) == "@")
			if (!(number(s.substr(1, 1))) && !(symbol(stb, s.substr(1, s.find(" ", 0) - 1))))
			{
				stb[s.substr(1, s.length() - 1)] = rl;
				rl++;
				ssz++;
			}
	f1.close();
	string os;
	s.clear();
	f1.open(argv[argc - 1]); 
	while (getline(f1, s))
	{
		RemComments(s);
		if (s.substr(0, 1) == "/" || s.substr(0, 1) == "" || s.substr(0, 1) == "(" || s.length() == 1) 
			continue;
		else if (s.substr(0, 1) == "@") 
		{
			if (number(s.substr(1, 1)))
			{
				os = Binary(s.substr(1, s.length() - 1));
				f2 << os << endl;
			}
			else 
			{
				os = Binary(itos(stb[s.substr(1, s.length() - 1)]));
				f2 << os << endl;
			}
		}
		else
		{
			os = CInstruction(s);
			f2 << os << endl;
		}
	}
	f1.close();
	f2.close();
	f1.open(off.c_str());
	string sstemp;
	int line = 1;
	while (getline(f1, sstemp))
	{
		if (sstemp.length() != 16)
			cout << "Error in line " << line << endl;
		line++;
	}
	f1.close();
	return 0;
}
