#include <bits/stdc++.h>

using namespace std;

#define pb push_back
# define of3 f4 << s1 << " " << s2 << " " << s3 << " " << endl
# define if3 f2 >> s1 >> s2 >> s3
# define f first
# define s second
# define mp make_pair
# define d2(s) dp2.push_back(s)
# define st string

string s1, s2, s3;
string fi1, fi2, fi3, fi4, fi5;
fstream f1, f2, f3, f4, f5;
int tlabelnum;
int ind = 0;
string currentClassname, currentsrname, currentsrtype;
int idl = 0;
vector <string> dp0, dp1, tk, dp2, ty, d02, dt;
int t;
map <string, pair<string, pair<string, int>>> cst, srt;
int sc, fc, tc, lc, ac, tsc;

void d0(string s) 
{
  d02.push_back(s);
  dt.push_back(s);
}

bool chop(string);
void out(string);
void proc();
inline void id3();
void tokeniser();
string tr(string, int, int);
void chsolve(string);
void analyser();
void compileClass();
void compileSubroutineDec();
void compileClassVarDec();
void compileParameterList();
void compileStatements();
void compileSubroutineBody();
void compileVarDec();
void compileReturnStatement();
void compileIfStatement();
void compileWhileStatement();
void compileDoStatement();
void compileLetStatement();
void compileExpression();
int compileExpressionList();
void compileTerm();
void codegen();
void codeClass();
void codeSubroutineDec();
void codeClassVarDec();
void codeParameterList();
void codeStatements();
void codeSubroutineBody();
void codeVarDec();
void codeReturnStatement();
void codeIfStatement();
void codeWhileStatement();
void codeDoStatement();
void codeLetStatement();
void codeExpression();
int codeExpressionList();
void codeTerm();

void tokeniser()
{
  vector <string> s;
  for (int i = 0; i < dp0.size(); i++)
    s.pb(dp0[i]);
  f2.open(fi2, ios::out);
  f5.open(fi5, ios::out);
  bool llf = false;
  for (int i = 0; i < s.size(); i++)
  {
    string t = s[i];
    string tmp;
    bool isnum = true;
    bool instring = false;
    for (int j = 0; j < t.size(); j++)
    {
      if (j < t.size() - 1 && t[j] == '/' && t[j + 1] == '*')
        llf = true;
      else if (j < t.size() - 1 && t[j] == '/' && t[j + 1] == '/')
        break;
      else if (j > 0 && t[j] == '/' && t[j - 1] == '*')
      {
        llf = false;
        continue;
      }
      if (llf)
        continue;
      else if (t[j] == '	')
        continue;
      if (instring && t[j] == '"')
      {
        f2 << "<stringConstant> " << tmp << " </stringConstant>\n";
        dp1.pb("<stringConstant> " + tmp + " </stringConstant>");
        tk.pb(tmp);
        ty.pb("stringConstant");
        tmp.clear();
        instring = false;
      }
      else if (instring)
        tmp += t[j];
      else if (t[j] == '"')
        instring = true;
      else if (t[j] == '{' || t[j] == '}' || t[j] == '(' || t[j] == ')' || t[j] == '[' || t[j] == ']' || t[j] == '.')
      {
        if (!tmp.empty())
          chsolve(tmp);
        f2 << "<Symbol> " << t[j] << " </Symbol>\n";
        string temp;
        temp += t[j];
        dp1.pb("<Symbol> " + temp + " </Symbol>");
        tk.pb(temp);
        tmp.clear();
        ty.pb("Symbol");
      }
      else if (t[j] == ',' || t[j] == ';' || t[j] == '+' || t[j] == '-' || t[j] == '*' || t[j] == '/' || t[j] == '&')
      {
        if (!tmp.empty())
          chsolve(tmp);
        f2 << "<Symbol> " << t[j] << " </Symbol>\n";
        string temp;
        temp += t[j];
        dp1.pb("<Symbol> " + temp + " </Symbol>");
        tk.pb(temp);
        tmp.clear();
        ty.pb("Symbol");
      }
      else if (t[j] == '|' || t[j] == '<' || t[j] == '>' || t[j] == '=' || t[j] == '~')
      {
        if (!tmp.empty())
          chsolve(tmp);
        f2 << "<Symbol> " << t[j] << " </Symbol>\n";
        string temp;
        temp += t[j];
        dp1.pb("<Symbol> " + temp + " </Symbol>");
        tk.pb(temp);
        tmp.clear();
        ty.pb("Symbol");
      }
      else if (t[j] != ' ')
      {
        tmp += t[j];
        if (!(t[j] > 47 && t[j] < 58))
          isnum = false;
      }
      else if (t[j] == ' ' && tmp.empty() == false)
      {
        chsolve(tmp);
        tmp.clear();
      }
    }
  }
  f2.close();
  f5.close();
}

void analyser()
{
  int t = tk.size();
  f2.open(fi2, ios:: in);
  f3.open(fi3, ios::out);
  f5.open(fi5, ios::out);
  compileClass();
  f2.close();
  f3.close();
  f5.close();
}

inline void id3()
{
  for (int i = 0; i < idl; i++)
    f3 << " ";
}

string tr(string s, int l, int r)
{
  string ans;
  for (int i = l; i < s.size() - r; i++)
    ans += s[i];
  return ans;
}

void proc()
{
  out(dp1[ind]);
  d2(dp1[ind]);
  d02.push_back(tk[ind]);
  dt.push_back(ty[ind]);
}

void out(string s)
{
  id3();
  f3 << s << endl;
}

void chsolve(string tmp)
{
  bool isnum = true;
  for (int j = 0; j < tmp.size(); j++)
    if (!(tmp[j] > 47 && tmp[j] < 58))
      isnum = false;
  if (isnum)
  {
    tk.pb(tmp);
    f2 << "<integerConstant> " << tmp << " </integerConstant>\n";
    dp1.pb("<integerConstant> " + tmp + " </integerConstant>");
    ty.pb("integerConstant");
  }
  else if (tmp == "class" || tmp == "constructor" || tmp == "function")
  {
    tk.pb(tmp);
    f2 << "<Keyword> " << tmp << " </Keyword>\n";
    dp1.pb("<Keyword> " + tmp + " </Keyword>");
    ty.pb("Keyword");
  }
  else if (tmp == "method" || tmp == "field" || tmp == "static" || tmp == "var")
  {
    tk.pb(tmp);
    f2 << "<Keyword> " << tmp << " </Keyword>\n";
    dp1.pb("<Keyword> " + tmp + " </Keyword>");
    ty.pb("Keyword");
  }
  else if (tmp == "int" || tmp == "char" || tmp == "void" || tmp == "true" || tmp == "boolean")
  {
    tk.pb(tmp);
    f2 << "<Keyword> " << tmp << " </Keyword>\n";
    dp1.pb("<Keyword> " + tmp + " </Keyword>");
    ty.pb("Keyword");
  }
  else if (tmp == "false" || tmp == "null" || tmp == "this" || tmp == "let" || tmp == "do")
  {
    tk.pb(tmp);
    f2 << "<Keyword> " << tmp << " </Keyword>\n";
    dp1.pb("<Keyword> " + tmp + " </Keyword>");
    ty.pb("Keyword");
  }
  else if (tmp == "if" || tmp == "else" || tmp == "while" || tmp == "return")
  {
    tk.pb(tmp);
    f2 << "<Keyword> " << tmp << " </Keyword>\n";
    dp1.pb("<Keyword> " + tmp + " </Keyword>");
    ty.pb("Keyword");
  }
  else
  {
    tk.pb(tmp);
    f2 << "<Identifier> " << tmp << " </Identifier>\n";
    dp1.pb("<Identifier> " + tmp + " </Identifier>");
    ty.pb("Identifier");
  }
  tmp.clear();
}

void compileClass()
{
  f3 << "<Class>" << endl;
  dp2.pb("<Class>");
  d02.pb("<Class>");
  dt.pb("<Class>");
  idl += 2;
  if (tk[ind] == "class")
    proc();
  else
  {
    f5 << "Syntax error: expected keyword class" << endl;
    exit(0);
  }
  ind++;
  if (ty[ind] == "Identifier")
  {
    proc();
    currentClassname = tk[ind];
  }
  else
  {
    f5 << "Syntax error: expected identifier" << endl;
    exit(0);
  }
  ind++;
  if (tk[ind] == "{")
    proc();
  else
  {
    f5 << "Syntax error: { expected" << endl;
    exit(0);
  }
  ind++;
  while ((tk[ind] == "static" || tk[ind] == "field"))
    compileClassVarDec();
  while (tk[ind] == "constructor" || tk[ind] == "method" || tk[ind] == "function")
    compileSubroutineDec();
  if (tk[ind] == "}")
    proc();
  else
  {
    f5 << "Syntax error: } expected" << endl;
    exit(0);
  }
  ind++;
  idl -= 2;
  out("</Class>");
  d2("</Class>");
  d0("</Class>");
}

void compileClassVarDec()
{
  out("<ClassVarDec>");
  d2("<ClassVarDec>");
  d0("<ClassVarDec>");
  idl += 2;
  proc();
  ind++;
  if (tk[ind] == "int" || tk[ind] == "char" || tk[ind] == "boolean" || ty[ind] == "Identifier")
    proc();
  else
  {
    f5 << "Syntax error: keyword expected" << endl;
    exit(0);
  }
  ind++;
  if (ty[ind] != "Identifier")
  {
    f5 << "Syntax error: identifier expected" << endl;
    exit(0);
  }
  else
    proc();
  ind++;
  while (tk[ind] == ",")
  {
    proc();
    ind++;
    if (ty[ind] != "Identifier")
    {
      f5 << "Syntax error: identifier expected" << endl;
      exit(0);
    }
    proc();
    ind++;
  }
  if (tk[ind] != ";")
  {
    f5 << "Syntax error: ; expected" << endl;
    exit(0);
  }
  else
  {
    proc();
    ind++;
  }
  idl -= 2;
  out("</ClassVarDec>");
  d2("</ClassVarDec>");
  d0("</ClassVarDec>");
}

void compileSubroutineDec()
{
  out("<SubroutineDec>");
  d2("<SubroutineDec>");
  d0("<SubroutineDec>");
  idl += 2;
  proc();
  st fkind = tk[ind], frt;
  ind++;
  if (tk[ind] == "void" || tk[ind] == "int" || tk[ind] == "char" || tk[ind] == "boolean" || ty[ind] == "Identifier")
  {
    proc();
    frt = tk[ind];
  }
  else
  {
    f5 << "Syntax error: function name expected" << endl;
    exit(0);
  }
  ind++;
  if (ty[ind] != "Identifier")
  {
    f5 << "Syntax error: identifier expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] != "(") 
  {
    f5 << "Syntax error: ( expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  compileParameterList();
  if (tk[ind] != ")") 
  {
    f5 << "Syntax error: ) expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  compileSubroutineBody();
  idl -= 2;
  out("</SubroutineDec>");
  d2("</SubroutineDec>");
  d0("</SubroutineDec>");
}

void compileParameterList() 
{
  out("<ParameterList>");
  d2("<ParameterList>");
  d0("<ParameterList>");
  idl += 2;
  while (tk[ind] != ")") 
  {
    st vtype;
    if (tk[ind] == "int" || tk[ind] == "char" || tk[ind] == "boolean" || tk[ind] == currentClassname) {
      proc();
      vtype = tk[ind];
    } 
    else 
    {
      f5 << "Syntax error: keyword expected" << endl;
      exit(0);
    }
    ind++;
    if (ty[ind] != "Identifier") 
    {
      f5 << "Syntax error: identifier expected" << endl;
      exit(0);
    } 
    else
      proc();
    ind++;
    if (tk[ind] == ",") 
    {
      proc();
      ind++;
    } 
    else if (tk[ind] == ")")
      break;
    else 
    {
      f5 << "Syntax Error: , expected" << endl;
      exit(0);
    }
  }
  idl -= 2;
  out("</ParameterList>");
  d2("</ParameterList>");
  d0("</ParameterList>");
}

void compileSubroutineBody() 
{
  out("<SubroutineBody>");
  d2("<SubroutineBody>");
  d0("<SubroutineBody>");
  idl += 2;
  if (tk[ind] != "{") 
  {
    f5 << "Syntax error: { expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  while (tk[ind] == "var")
    compileVarDec();
  compileStatements();
  if (tk[ind] != "}") 
  {
    f5 << "Syntax error: } expected" << endl;
    exit(0);
  } else proc();
  ind++;
  idl -= 2;
  out("</SubroutineBody>");
  d2("</SubroutineBody>");
  d0("</SubroutineBody>");
}

void compileVarDec() 
{
  out("<VarDec>");
  d2("<VarDec>");
  d0("<VarDec>");
  idl += 2;
  proc();
  st vtype;
  ind++;
  if (tk[ind] == "int" || tk[ind] == "char" || tk[ind] == "boolean" || ty[ind] == "Identifier") 
  {
    proc();
    vtype = tk[ind];
  } 
  else 
  {
    f5 << "Syntax error: keyword expected" << endl;
    exit(0);
  }
  ind++;
  if (ty[ind] != "Identifier") 
  {
    f5 << "Syntax error: identifier expected" << endl;
    exit(0);
  } 
  else
    proc();
  ind++;
  while (tk[ind] == ",") 
  {
    proc();
    ind++;
    if (ty[ind] != "Identifier") 
    {
      f5 << "Syntax error: identifier expected" << endl;
      exit(0);
    }
    proc();
    ind++;
  }
  if (tk[ind] != ";") 
  {
    f5 << "Syntax error: ; expected" << endl;
    exit(0);
  } 
  else 
  {
    proc();
    ind++;
  }
  idl -= 2;
  out("</VarDec>");
  d2("</VarDec>");
  d0("</VarDec>");
}

void compileStatements() 
{
  out("<Statements>");
  d2("<Statements>");
  d0("<Statements>");
  idl += 2;
  while (tk[ind] != "}") 
  {
    if (tk[ind] == "if")
      compileIfStatement();
    else if (tk[ind] == "let")
      compileLetStatement();
    else if (tk[ind] == "do")
      compileDoStatement();
    else if (tk[ind] == "while")
      compileWhileStatement();
    else if (tk[ind] == "return")
      compileReturnStatement();
  }
  idl -= 2;
  out("</Statements>");
  d2("</Statements>");
  d0("</Statements>");
}

void compileIfStatement() 
{
  out("<IfStatement>");
  d2("<IfStatement>");
  d0("<IfStatement>");
  idl += 2;
  proc();
  ind++;
  if (tk[ind] != "(")
  {
    f5 << "Syntax error: ( expected " << endl;
    exit(0);
  }
  else proc();
  ind++;
  if (tk[ind] == ")") 
  {
    f5 << "Syntax error: expression expected" << endl;
    exit(0);
  }
  compileExpression();
  if (tk[ind] != ")") 
  {
    f5 << "Syntax error: ) expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] != "{") 
  {
    f5 << "Syntax error: { expected " << endl;
    exit(0);
  } 
  else proc();
  ind++;
  compileStatements();
  if (tk[ind] != "}") 
  {
    f5 << "Syntax error: } expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] == "else") 
  {
    proc();
    ind++;
    if (tk[ind] != "{") 
    {
      f5 << "Syntax error: { expected " << endl;
      exit(0);
    } 
    else proc();
    ind++;
    compileStatements();
    if (tk[ind] != "}") 
    {
      f5 << "Syntax error: } expected" << endl;
      exit(0);
    } 
    else proc();
    ind++;
  }
  idl -= 2;
  out("</IfStatement>");
  d2("</IfStatement>");
  d0("</IfStatement>");
}

void compileWhileStatement() 
{
  out("<WhileStatement>");
  d2("<WhileStatement>");
  d0("<WhileStatement>");
  idl += 2;
  proc();
  ind++;
  if (tk[ind] != "(") 
  {
    f5 << "Syntax error: ( expected " << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] == ")") 
  {
    f5 << "Syntax error: expression expected" << endl;
    exit(0);
  }
  compileExpression();
  if (tk[ind] != ")") 
  {
    f5 << "Syntax error: ) expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] != "{") 
  {
    f5 << "Syntax error: { expected " << endl;
    exit(0);
  } 
  else proc();
  ind++;
  compileStatements();
  if (tk[ind] != "}")
  {
    f5 << "Syntax error: } expected" << endl;
    exit(0);
  }
  else proc();
  ind++;
  idl -= 2;
  out("</WhileStatement>");
  d2("</WhileStatement>");
  d0("</WhileStatement>");
}

void compileDoStatement()
{
  out("<DoStatement>");
  d2("<DoStatement>");
  d0("<DoStatement>");
  idl += 2;
  proc();
  ind++;
  if (ty[ind] != "Identifier")
  {
    f5 << "Syntax error: Identifier expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] == ".")
  {
    proc();
    ind++;
    if (ty[ind] != "Identifier")
    {
      f5 << "Syntax error: Identifier expected" << endl;
      exit(0);
    }
    else proc();
    ind++;
  }
  if (tk[ind] != "(")
  {
    f5 << "Syntax error: ( expected" << endl;
    exit(0);
  }
  else proc();
  ind++;
  compileExpressionList();
  if (tk[ind] != ")") 
  {
    f5 << "Syntax error: ) expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] != ";") 
  {
    f5 << "Syntax error: ; expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  idl -= 2;
  out("</DoStatement>");
  d2("</DoStatement>");
  d0("</DoStatement>");
}

void compileLetStatement() 
{
  out("<LetStatement>");
  d2("<LetStatement>");
  d0("<LetStatement>");
  idl += 2;
  proc();
  ind++;
  if (ty[ind] != "Identifier") 
  {
    f5 << "Syntax error: identifier expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  if (tk[ind] == "[") 
  {
    proc();
    ind++;
    compileExpression();
    if (tk[ind] != "]") 
    {
      f5 << "Syntax error: ] expected" << endl;
      exit(0);
    } 
    else proc();
    ind++;
  }
  if (tk[ind] != "=") 
  {
    f5 << "Syntax error: = expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  compileExpression();
  if (tk[ind] != ";") 
  {
    f5 << "Syntax error: ; expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  idl -= 2;
  out("</LetStatement>");
  d2("</LetStatement>");
  d0("</LetStatement>");
}

void compileReturnStatement()
{
  out("<ReturnStatement>");
  d2("<ReturnStatement>");
  d0("<ReturnStatement>");
  idl += 2;
  proc();
  ind++;
  if (tk[ind] != ";")
    compileExpression();
  if (tk[ind] != ";") 
  {
    f5 << "Syntax error: ; expected" << endl;
    exit(0);
  } 
  else proc();
  ind++;
  idl -= 2;
  out("</ReturnStatement>");
  d2("</ReturnStatement>");
  d0("</ReturnStatement>");
}

int compileExpressionList() 
{
  int nP = 0;
  out("<ExpressionList>");
  d2("<ExpressionList>");
  d0("<ExpressionList>");
  idl += 2;
  if (tk[ind] != ")") 
  {
    compileExpression();
    nP++;
  }
  while (tk[ind] == ",") 
  {
    proc();
    ind++;
    compileExpression();
    nP++;
  }
  idl -= 2;
  out("</ExpressionList>");
  d2("</ExpressionList>");
  d0("</ExpressionList>");
  return nP;
}

void compileExpression() 
{
  out("<Expression>");
  d2("<Expression>");
  d0("<Expression>");
  idl += 2;
  if (!(tk[ind] == ";" || tk[ind] == "," || tk[ind] == ")")) 
  {
    compileTerm();
    while (chop(tk[ind])) 
    {
      proc();
      ind++;
      compileTerm();
    }
  }
  idl -= 2;
  out("</Expression>");
  d2("</Expression>");
  d0("</Expression>");
}

bool chop(string s)
{
  if (s == "+" || s == "-" || s == "=" || s == ">" || s == "<" || s == "&" || s == "|" || s == "*" || s == "/")
    return true;
  else return false;
}

void compileTerm() 
{
  out("<Term>");
  d2("<Term>");
  d0("<Term>");
  idl += 2;
  if (ty[ind] == "integerConstant")
    proc(), ind++;
  else if (ty[ind] == "stringConstant") 
  {
    proc();
    ind++;
  } 
  else if (tk[ind] == "true" || tk[ind] == "false" || tk[ind] == "null" || tk[ind] == "this")
    proc(), ind++;
  else if (ty[ind] == "Identifier") 
  {
    proc();
    ind++;
    if (tk[ind] == "[") 
    {
      proc();
      ind++;
      compileExpression();
      if (tk[ind] != "]") 
      {
        f5 << "Syntax error: ] expected" << endl;
        exit(0);
      }
      else proc();
      ind++;
    } 
    else if (tk[ind] == ".") 
    {
      proc();
      ind++;
      if (ty[ind] != "Identifier") 
      {
        f5 << "Syntax error: Identifier expected" << endl;
        exit(0);
      } 
      else proc();
      ind++;
    }
    if (tk[ind] == "(") 
    {
      proc();
      ind++;
      compileExpressionList();
      if (tk[ind] != ")") 
      {
        f5 << "Syntax error: ) expected" << endl;
        exit(0);
      } 
      else proc();
      ind++;
    }
  } 
  else if (tk[ind] == "(") 
  {
    proc();
    ind++;
    compileExpression();
    if (tk[ind] != ")") 
    {
      f5 << "Syntax error: ) expected" << endl;
      exit(0);
    } 
    else proc();
    ind++;
  } 
  else if (tk[ind] == "-" || tk[ind] == "~") 
  {
    proc();
    ind++;
    compileTerm();
  } 
  else 
  {
    f5 << "Syntax error: term expected" << endl;
    exit(0);
  }
  idl -= 2;
  out("</Term>");
  d2("</Term>");
  d0("</Term>");
}

void codegen() 
{
  f4.open(fi4, ios::out);
  f5.open(fi5, ios::out);
  ind = 0;
  if (d02[ind] == "<Class>") 
  {
    ind++;
    codeClass();
  }
  f4.close();
  f5.close();
}

void codeClass() 
{
  cst.clear();
  tc = 0;
  sc = 0;
  fc = 0;
  while (d02[ind] != "<ClassVarDec>" && d02[ind] != "<SubroutineDec>")
    ind++;
  while (d02[ind] == "<ClassVarDec>")
    codeClassVarDec();
  while (d02[ind] == "<SubroutineDec>")
    codeSubroutineDec();
}

void codeSubroutineDec() 
{
  srt.clear();
  tsc = 0;
  ac = 0;
  lc = 0;
  ind++;
  currentsrtype = d02[ind++];
  ind++;
  currentsrname = d02[ind++];
  if (currentsrtype == "method") 
  {
    srt["this"] = mp("argument", mp(currentClassname, 0));
    tsc++;
    ac++;
  }
  ind++;
  if (d02[ind] == "<ParameterList>") 
  {
    ind++;
    codeParameterList();
  }
  ind++;
  if (d02[ind] == "<SubroutineBody>") 
  {
    ind++;
    codeSubroutineBody();
  }
  if (d02[ind] == "</SubroutineDec>")
    ind++;
}

void codeClassVarDec() 
{
  ind++;
  string s1 = d02[ind++], s2 = d02[ind++], s3 = d02[ind++];
  if (s1 == "static")
    cst[s3] = mp(s1, mp(s2, sc++)), tc++;
  else cst[s3] = mp(s1, mp(s2, fc++)), tc++;
  while (d02[ind] == ",") 
  {
    ind++;
    string s4 = d02[ind++];
    if (s1 == "static")
      cst[s4] = mp(s1, mp(s2, sc++)), tc++;
    else cst[s4] = mp(s1, mp(s2, fc++)), tc++;
  }
  ind++;
  ind++;
}

void codeParameterList() 
{
  while (d02[ind] != "</ParameterList>") 
  {
    string ptype = d02[ind++];
    string pname = d02[ind++];
    if (d02[ind] == ",")
      ind++;
    srt[pname] = mp("argument", mp(ptype, ac++));
    tsc++;
  }
  ind++;
}

void codeStatements() 
{
  while (d02[ind] != "</Statements>") 
  {
    if (d02[ind] == "<DoStatement>") 
    {
      ind++;
      codeDoStatement();
    } 
    else if (d02[ind] == "<LetStatement>") 
    {
      ind++;
      codeLetStatement();
    } 
    else if (d02[ind] == "<WhileStatement>") 
    {
      ind++;
      codeWhileStatement();
    } 
    else if (d02[ind] == "<IfStatement>")
    {
      ind++;
      codeIfStatement();
    }
    else if (d02[ind] == "<ReturnStatement>")
    {
      ind++;
      codeReturnStatement();
    }
  }
  ind++;
}

void codeSubroutineBody() 
{
  ind++;
  while (d02[ind] == "<VarDec>") 
  {
    ind++;
    codeVarDec();
  }
  f4 << "function " << currentClassname << "." << currentsrname << " " << lc << endl;
  if (currentsrtype == "constructor") 
  {
    f4 << "push constant " << fc << endl;
    f4 << "call Memory.alloc 1" << endl;
    f4 << "pop pointer 0" << endl;
  } 
  else if (currentsrtype == "method")
    f4 << "push argument 0\npop pointer 0" << endl;
  while (d02[ind] == "<Statements>")
  {
    ind++;
    codeStatements();
  }
  ind++;
  if (d02[ind] == "</SubroutineBody>")
    ind++;
}

void codeVarDec() 
{
  ind++;
  do 
  {
    string vtype = d02[ind++];
    string vname = d02[ind++];
    srt[vname] = mp("local", mp(vtype, lc++));
    tsc++;
  } while (d02[ind] == ",");
  ind++;
  if (d02[ind] == "</VarDec>")
    ind++;
}

void codeReturnStatement() 
{
  ind++;
  if (d02[ind] == ";") 
  {
    f4 << "push constant 0\nreturn\n";
  } 
  else 
  {
    ind++;
    codeExpression();
    f4 << "return" << endl;
  }
  ind++;
  if (d02[ind] == "</ReturnStatement>")
    ind++;
}

void codeIfStatement() 
{
  int labelnum = tlabelnum;
  tlabelnum += 2;
  ind++;
  ind++;
  ind++;
  codeExpression();
  ind++;
  ind++;
  f4 << "not\nif-goto " << currentClassname << "." << labelnum << endl;
  ind++;
  codeStatements();
  ind++;
  f4 << "goto " << currentClassname << "." << labelnum + 1 << endl;
  f4 << "label " << currentClassname << "." << labelnum << endl;
  if (d02[ind] == "else") 
  {
    ind++;
    ind++;
    ind++;
    codeStatements();
    ind++;
    ind++;
  }
  f4 << "label " << currentClassname << "." << labelnum + 1 << endl;
  if (d02[ind] == "</IfStatement>")
    ind++;
}

void codeWhileStatement() 
{
  int labelnum = tlabelnum;
  tlabelnum += 2;
  ind++;
  ind++;
  f4 << "label " << currentClassname << "." << labelnum << endl;
  ind++;
  codeExpression();
  ind++;
  f4 << "not" << endl;
  f4 << "if-goto " << currentClassname << "." << labelnum + 1 << endl;
  ind++;
  ind++;
  codeStatements();
  f4 << "goto " << currentClassname << "." << labelnum << endl;
  f4 << "label " << currentClassname << "." << labelnum + 1 << endl;
  ind++;
  if (d02[ind] == "</WhileStatement>")
    ind++;
}

void codeDoStatement() 
{
  ind++;
  string id1 = d02[ind++];
  if (d02[ind] == ".") 
  {
    ind++;
    string id2 = d02[ind++];
    ind++;
    string type, kind;
    int index;
    bool checker = !cst[id1].f.empty() || !srt[id1].f.empty();
    if (checker) 
    {
      if (!srt[id1].f.empty()) 
      {
        type = srt[id1].s.f;
        kind = srt[id1].f;
        index = srt[id1].s.s;
      } 
      else 
      {
        type = cst[id1].s.f;
        kind = cst[id1].f;
        index = cst[id1].s.s;
        if (kind == "field")
          kind = "this";
      }
      f4 << "push " << kind << " " << index << endl;
    }
    ind++;
    int np = codeExpressionList();
    ind++;
    ind++;
    if (checker) 
    {
      f4 << "call " << type << "." << id2 << " " << np + 1 << endl;
      f4 << "pop temp 0" << endl;
    } 
    else 
    {
      f4 << "call " << id1 << "." << id2 << " " << np << endl;
      f4 << "pop temp 0" << endl;
    }
  } 
  else 
  {
    f4 << "push pointer 0" << endl;
    ind++;
    ind++;
    int np = codeExpressionList();
    ind++;
    ind++;
    f4 << "call " << currentClassname << "." << id1 << " " << np + 1 << endl;
    f4 << "pop temp 0" << endl;
  }
  if (d02[ind] == "</DoStatement>")
    ind++;
}

void codeLetStatement() 
{
  ind++;
  string sname = d02[ind++];
  string type;
  int index;
  if (srt[sname].f.empty() && cst[sname].f.empty()) 
  {
    f5 << "Declaration error: " << sname << " undeclared" << endl;
    exit(0);
  } 
  else if (!srt[sname].f.empty()) 
  {
    type = srt[sname].f;
    index = srt[sname].s.s;
  } 
  else 
  {
    type = cst[sname].f;
    index = cst[sname].s.s;
    if (type == "field")
      type = "this";
  }
  if (d02[ind] == "[") 
  {
    ind++;
    ind++;
    codeExpression();
    ind++;
    f4 << "push " << type << " " << index << endl;
    f4 << "add" << endl;
    ind++;
    ind++;
    codeExpression();
    f4 << "pop temp 0\npop pointer 1\npush temp 0\npop that 0\n";
  } 
  else 
  {
    ind++;
    ind++;
    codeExpression();
    ind++;
    f4 << "pop " << type << " " << index << endl;
  }
  ind++;
  if (d02[ind] == "</LetStatement>")
    ind++;
}

void codeExpression() 
{
  if (d02[ind] == "<Term>") 
  {
    ind++;
    codeTerm();
    while (chop(d02[ind])) 
    {
      string op = d02[ind];
      ind++;
      ind++;
      codeTerm();
      if (op == "+")
        f4 << "add\n";
      if (op == "-")
        f4 << "sub\n";
      if (op == "|")
        f4 << "or\n";
      if (op == "&")
        f4 << "and\n";
      if (op == ">")
        f4 << "gt\n";
      if (op == "<")
        f4 << "lt\n";
      if (op == "=")
        f4 << "eq\n";
      if (op == "*")
        f4 << "call Math.multiply 2\n";
      if (op == "/")
        f4 << "call Math.divide 2\n";
    }
  }
  if (d02[ind] == "</Expression>")
    ind++;
}

int codeExpressionList() 
{
  int np = 0;
  while (d02[ind] == "<Expression>") 
  {
    ind++;
    codeExpression();
    if (d02[ind] == ",")
      ind++;
    np++;
  }
  if (d02[ind] == "</ExpressionList>")
    ind++;
  return np;
}

void codeTerm() 
{
  if (d02[ind] == "~") 
  {
    ind++;
    ind++;
    codeTerm();
    f4 << "not" << endl;
  } 
  else if (d02[ind] == "-") 
  {
    ind++;
    ind++;
    codeTerm();
    f4 << "neg" << endl;
  } 
  else if (d02[ind] == "(") 
  {
    ind++;
    ind++;
    codeExpression();
    ind++;
  } 
  else if (dt[ind] == "integerConstant") 
  {
    f4 << "push constant " << d02[ind] << endl;
    ind++;
    ind++;
  } 
  else if (dt[ind] == "Keyword") 
  {
    if (d02[ind] == "true")
      f4 << "push constant 0\nnot" << endl;
    else if (d02[ind] == "false")
      f4 << "push constant 0" << endl;
    else if (d02[ind] == "null")
      f4 << "push constant 0" << endl;
    else if (d02[ind] == "this")
      f4 << "push pointer 0" << endl;
    ind++;
  } 
  else if (dt[ind] == "Identifier") 
  {
    string vname = d02[ind], vtype;
    string kind;
    int index;
    ind++;
    if (d02[ind] == ".") 
    {
      ind++;
      string id2 = d02[ind++];
      ind++;
      bool checker = !cst[vname].f.empty() || !srt[vname].f.empty();
      if (checker) 
      {
        if (!srt[vname].f.empty()) 
        {
          vtype = srt[vname].s.f;
          kind = srt[vname].f;
          index = srt[vname].s.s;
        } 
        else 
        {
          vtype = cst[vname].s.f;
          kind = cst[vname].f;
          index = cst[vname].s.s;
          if (kind == "field")
            kind = "this";
        }
        f4 << "push " << kind << " " << index << endl;
      }
      ind++;
      int np = codeExpressionList();
      ind++;
      ind++;
      if (checker)
        f4 << "call " << vtype << "." << id2 << " " << np + 1 << endl;
      else
        f4 << "call " << vname << "." << id2 << " " << np << endl;
    } 
    else if (d02[ind] == "(") 
    {
      f4 << "push pointer 0" << endl;
      ind++;
      int np = codeExpressionList();
      ind++;
      f4 << "call " << currentClassname << "." << vname << " " << np + 1 << endl;
    } 
    else if (d02[ind] == "[") 
    {
      if (srt[vname].f.empty() && cst[vname].f.empty()) 
      {
        f5 << "Declaration error: " << vname << " undeclared" << endl;
        exit(0);
      } 
      else 
      {
        if (!srt[vname].f.empty()) 
        {
          vtype = srt[vname].f;
          index = srt[vname].s.s;
        } 
        else 
        {
          vtype = cst[vname].f;
          index = cst[vname].s.s;
          if (vtype == "field")
            vtype = "this";
        }
        ind++;
        ind++;
      }
      codeExpression();
      f4 << "push " << vtype << " " << index << endl;
      f4 << "add" << endl;
      f4 << "pop pointer 1" << endl;
      f4 << "push that 0" << endl;
      ind++;
    } 
    else 
    {
      if (srt[vname].f.empty() && cst[vname].f.empty()) 
      {
        f5 << "Declaration error: " << vname << " undeclared" << endl;
        exit(0);
      } 
      else 
      {
        if (!srt[vname].f.empty()) 
        {
          vtype = srt[vname].f;
          index = srt[vname].s.s;
        } 
        else 
        {
          vtype = cst[vname].f;
          index = cst[vname].s.s;
          if (vtype == "field")
            vtype = "this";
        }
      }
      f4 << "push " << vtype << " " << index << endl;
    }
  } 
  else if (dt[ind] == "stringConstant") 
  {
    string s1 = d02[ind];
    f4 << "push constant " << s1.size() << endl;
    f4 << "call String.new 1" << endl;
    for (int i = 0; i < s1.size(); i++) 
    {
      f4 << "push constant " << (int)(s1[i]) << endl;
      f4 << "call String.appendChar 2" << endl;
    }
    ind++;
  }
  if (d02[ind] == "</Term>")
    ind++;
}

int main(int argc, char * argv[])
{
  for (int x = 1; x < argc; x++)
  {
    dp1.clear();
    dp0.clear();
    d02.clear();
    tk.clear();
    dp2.clear();
    dt.clear();
    ty.clear();
    cst.clear();
    srt.clear();
    tlabelnum = 0;
    currentsrname.clear();
    sc = fc = tc = lc = ac = tsc = 0;
    ind = 0;
    currentClassname.clear();
    idl = 0;
    t = 0;
    string s = argv[x];
    for (int i = 0; i < s.size(); i++)
      if (s[i] == '.')
        s.erase(i);
    fi1 = s + ".jack";
    fi2 = s + ".tok";
    fi3 = s + ".anz";
    fi4 = s + ".vm";
    fi5 = s + ".err";
    f1.open(fi1, ios :: in);
    while (!f1.eof())
    {
      string temp;
      getline(f1, temp, '\n');
      dp0.pb(temp);
    }
    f1.close();
    tokeniser();
    analyser();
    codegen();
  }
  return 0;
}