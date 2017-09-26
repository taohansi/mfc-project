// calculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calculator.h"
#include "calculatorDlg.h"
#include <vector>
#include <string>
#include <stack>
#include <math.h>
#include <cstdio>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CcalculatorDlg �Ի���




CcalculatorDlg::CcalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CcalculatorDlg::IDD, pParent)
	, m_StringInput(_T(""))
	, m_StringOutput(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_StringInput);
	DDX_Text(pDX, IDC_EDIT2, m_StringOutput);
}

BEGIN_MESSAGE_MAP(CcalculatorDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT2, &CcalculatorDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON_equation, &CcalculatorDlg::OnBnClickedButtonequation)
	ON_BN_CLICKED(IDC_BUTTON_number_1, &CcalculatorDlg::OnBnClickedButtonnumber1)
	ON_BN_CLICKED(IDC_BUTTON_number_2, &CcalculatorDlg::OnBnClickedButtonnumber2)
	ON_BN_CLICKED(IDC_BUTTON_number_3, &CcalculatorDlg::OnBnClickedButtonnumber3)
	ON_BN_CLICKED(IDC_BUTTON_number_4, &CcalculatorDlg::OnBnClickedButtonnumber4)
	ON_BN_CLICKED(IDC_BUTTON_dot, &CcalculatorDlg::OnBnClickedButtondot)
	ON_BN_CLICKED(IDC_BUTTON_number_5, &CcalculatorDlg::OnBnClickedButtonnumber5)
	ON_BN_CLICKED(IDC_BUTTON9, &CcalculatorDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON_number9, &CcalculatorDlg::OnBnClickedButtonnumber9)
	ON_BN_CLICKED(IDC_BUTTON_add, &CcalculatorDlg::OnBnClickedButtonadd)
	ON_BN_CLICKED(IDC_BUTTON_subscrab, &CcalculatorDlg::OnBnClickedButtonsubscrab)
	ON_BN_CLICKED(IDC_BUTTON_time, &CcalculatorDlg::OnBnClickedButtontime)
	ON_BN_CLICKED(IDC_BUTTON_divide, &CcalculatorDlg::OnBnClickedButtondivide)
	ON_BN_CLICKED(IDC_BUTTON1_parameter, &CcalculatorDlg::OnBnClickedButton1parameter)
	ON_BN_CLICKED(IDC_BUTTON_paramater2, &CcalculatorDlg::OnBnClickedButtonparamater2)
	ON_BN_CLICKED(IDC_BUTTON_lg, &CcalculatorDlg::OnBnClickedButtonlg)
	ON_BN_CLICKED(IDC_BUTTON_ln, &CcalculatorDlg::OnBnClickedButtonln)
	ON_BN_CLICKED(IDC_BUTTON_arc, &CcalculatorDlg::OnBnClickedButtonarc)
	ON_BN_CLICKED(IDC_BUTTON_sin, &CcalculatorDlg::OnBnClickedButtonsin)
	ON_BN_CLICKED(IDC_BUTTON_cos, &CcalculatorDlg::OnBnClickedButtoncos)
	ON_BN_CLICKED(IDC_BUTTON_tan, &CcalculatorDlg::OnBnClickedButtontan)
	ON_BN_CLICKED(IDC_BUTTON_number_0, &CcalculatorDlg::OnBnClickedButtonnumber0)
	ON_BN_CLICKED(IDC_BUTTON_number7, &CcalculatorDlg::OnBnClickedButtonnumber7)
	ON_BN_CLICKED(IDC_BUTTON_number_8, &CcalculatorDlg::OnBnClickedButtonnumber8)
	ON_BN_CLICKED(IDC_BUTTON_mod, &CcalculatorDlg::OnBnClickedButtonmod)
	ON_BN_CLICKED(IDC_BUTTON_dekete, &CcalculatorDlg::OnBnClickedButtondekete)
	ON_BN_CLICKED(IDC_BUTTON_empty, &CcalculatorDlg::OnBnClickedButtonempty)
	ON_BN_CLICKED(IDC_BUTTON_pow, &CcalculatorDlg::OnBnClickedButtonpow)
	ON_BN_CLICKED(IDC_BUTTONanswer, &CcalculatorDlg::OnBnClickedButtonanswer)
	ON_BN_CLICKED(IDC_BUTTON1, &CcalculatorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CcalculatorDlg ��Ϣ�������

BOOL CcalculatorDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CcalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CcalculatorDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ�������������
	// ���͸�֪ͨ��������д CDialog::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}
//�жϷ���
int definemark(char strc)
	{
       if(strc== '+'||strc=='-'||strc=='*'||strc=='/'|| strc == '('|| strc ==')'|| strc == '%'|| strc =='^'|| strc == '!'|| (strc>=97&& strc <=122) )
           return 1;
	   
	   if(strc>=48&&strc<=57||(strc=='.'))
		   return 2;
	   
	   return 3;

	}
int defineString(string str)
{

	 if(str== "+"||str=="-"||str=="*"||str=="/"||str== "^"|| str == "%" ||str == "^" )
           return 1;
    if(str[0]>=48&&str[0]<=57)
		return 2;
	if(str== "lg"||str== "sin"|| str == "cos"|| str == "tan"|| str == "arcsin"|| str == "arccos" || str == "arctan" || str == "ln"|| str == "!")
		 return 3;
	return 4;
}


//���ȼ�
//����������ȼ�
int preference (string str, int num)
{
	if(str == "#")
	return 0;
	if(str =="(")
	{
       return 11-(10*num);
	}
    
	if(str ==")")
	{
       return 1+10*num;
	}

    if(str == "+"|| str == "-")
	{
          return 2+num;
	}

	if(str == "*"|| str == "/"|| str =="%")
	{
          return 4+num;
	}
    
	if( str == "sin"|| str == "cos"|| str == "tan"|| str == "arcsin"|| str == "arccos" || str == "arctan" )
	{
         return 6+num;
	}
     
	if( str == "lg" || str ==" ln" || str =="^" || str == "!")
	{
         return 8+num;
	}

}

void CcalculatorDlg::OnBnClickedButtonequation()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�ж��Ƿ�Ϊ����
		


	m_StringOutput="";
	CString originString = m_StringInput;
	vector<string>BackExpression(100,"");
	int StringSize=m_StringInput.GetLength();
	int BackCounter= 0;
	int ifStart=0;
    int startNumber=0;
	int counterLength=0;
	int whether =0;

    stack<string>stringStack;
	stringStack.push("#");

	//������������
	for(int i=0;i<StringSize;i++)
	{
		char strchar=m_StringInput.GetAt(i);
		if(strchar=='-'|| strchar == '.')
		{
			if(i == 0)
			{
                  m_StringInput.Insert(i,'0');
				  continue;
			}
			char tempchar=m_StringInput.GetAt(i-1);
			if(tempchar== '(')
			{
				m_StringInput.Insert(i,'0');

     		}

		}
	}
    //���ڽ׳���һ����������ŵĲ�ͬ ���ַ��������޸�
	StringSize=m_StringInput.GetLength();
    for (int j= 0;j<StringSize;j++)
	{
		 char tempstr = m_StringInput.GetAt(j);
		if( tempstr == '!')
		{
			int num = j - 1;
            char tempchar = m_StringInput.GetAt(num);

			while( num!= 0&& definemark(tempchar) ==2)
			{
				num--;
				tempchar = m_StringInput.GetAt(num);
			}
           m_StringInput.Delete(j);
		   if(num != 0)
		   m_StringInput.Insert(num+1,'!');
		   else
		   {
              if(definemark(tempchar) ==2)
				  m_StringInput.Insert(num,'!');
			  else
                 m_StringInput.Insert(num+1,'!');
		   }
            
		}

	}
		StringSize=m_StringInput.GetLength();

	for(int i=0;i<StringSize;i++)
	{
		
		char strchar=m_StringInput.GetAt(i);

//��������������ֱ�ӽ����ַ�������
         if(definemark(strchar) == 2)
		 { 
		   if(ifStart== 0)
		   {
			   ifStart=1;
			   startNumber=i;
		   }		   
			counterLength++;
			if(i ==StringSize-1)
            {  
              CString NumberString="";
			  NumberString= m_StringInput.Mid(startNumber,counterLength);
			  BackExpression[BackCounter]= NumberString;
			  BackCounter++;
			  counterLength=0;
			  ifStart=0;
			  
		   }
			
			 int n2=i+1;
			char tempchar=m_StringInput.GetAt(n2);
		   if(definemark(tempchar) == 1)
		   {  
              CString NumberString="";
			  NumberString= m_StringInput.Mid(startNumber,counterLength);
			  BackExpression[BackCounter]= NumberString;
			  BackCounter++;
			  counterLength=0;
			  ifStart=0;
		   }

		 } 
//���� �����˷�����ô�����ȼ��Ƚ�
 //������ȼ�������ǰ �Ƚ�֮ǰԪ�ص��� ����ջ
		 if(definemark(strchar)== 1)
		 {
			 string character="";
			 int startNumber2 = i;
			 int length =1;
			 bool right = false;
			 //���������һ������� ��sin
			 if(i != StringSize -1&&strchar>=97&&strchar<=122)
			 {
			 char tempchar=m_StringInput.GetAt(i+1);
			 while (tempchar>=97&&tempchar<=122)
			 {
				 length++;
				 i++;
				 if(i == StringSize -1)
				 {
					 break;
				 }
				 tempchar=m_StringInput.GetAt(i+1);

			 }
			 }
			 
			 character = m_StringInput.Mid(startNumber2,length);
			 
		     

//��ʼ�������ȼ��Ƚ�		
			 int inPrefer = preference(stringStack.top(),1);
			 int outPrefer = preference(character,0);
			 if(outPrefer == inPrefer)
			 {
                stringStack.pop();
				continue;
			 }
			 if(outPrefer > inPrefer)
			 {
				 stringStack.push(character);

			 }
			 if(outPrefer < inPrefer)
			 {
                 int sign =0;
				 while(outPrefer <inPrefer)
				 {
                 string stringchar = stringStack.top();
				 BackExpression[BackCounter]=stringchar;
				 BackCounter++;
				 stringStack.pop();	
				 inPrefer = preference(stringStack.top(),1);
				 }
				 if(inPrefer == outPrefer)
				    {
                      stringStack.pop();				  
					  sign = 1;
					 continue;
					 
				    }
				 
				 if( sign == 0)
                 stringStack.push(character);

			 }
			 
			 
//�������ŵ����
		 }
		 if(definemark(strchar)== 3)
		 {
		m_StringOutput="������������";
		whether =1;

		 }


	}

//���õ������е�ջ��Ԫ�ص�����������
	//�õ��沨������
	while (stringStack.top()!= "#")
	{
           
           string tempStore = stringStack.top();
		   
		   BackExpression[BackCounter]=tempStore;
		   BackCounter++;
		   stringStack.pop();
	}

	int i=0;
	int counter1 =0;
	int counter2 =0;
	
	//���û��һһ��Ӧ���������
	while (BackExpression[i] != "")
	{
		if(BackExpression[i] == "(")
			counter1++;
		if(BackExpression[i] ==")")
			counter2++;
        i++;
	}
	if(counter1 != counter2)
	{
        m_StringOutput=("û�ж�Ӧ������");
		whether =1;
	}
  
	//��ȡ�沨������

	stack<float> resultNumber;
	int i1=0;
	const double Pi =3.1415926535;
    while (BackExpression[i1] != ""&& whether == 0)
	{
		//�������ֽ�������stack
		if(defineString(BackExpression[i1])== 2 )
		{
			double storeNumber= 0.0;
			storeNumber= atof(BackExpression[i1].c_str());
			resultNumber.push(storeNumber);
			i1++;
		}
		//��������������һ�����ֵ��� �ٽ����ѹ��
		if(defineString(BackExpression[i1])== 3)
		{
			double toCaNum =0.0;
			double resultNum =0.0;
			if(!resultNumber.empty())
			{
			toCaNum= resultNumber.top();
			resultNumber.pop();
			}
			else
			{
                 m_StringOutput="����������Ų�ƥ��";
				break;

			}
			
          if(BackExpression[i1]== "lg")
		  {
			  if(toCaNum<=0)
			  {
                m_StringOutput="�㲻���ø�����Ϊ�����Ĳ�����";
				break;
			  }
               resultNum =log10(toCaNum);
		  }

          if(BackExpression[i1]== "ln")
		  {
			  if(toCaNum<=0)
			  {
                m_StringOutput="�㲻���ø�����Ϊ�����Ĳ�����";
				break;
			  }
               resultNum =log(toCaNum);
		  }

		  if(BackExpression[i1] == "sin")
		  {
			  toCaNum = (toCaNum*Pi)/180;
               resultNum =sin(toCaNum);
		  }
		  if(BackExpression[i1] == "tan")
		  {
               toCaNum = (toCaNum*Pi)/180;
              resultNum =tan(toCaNum);
		  }
		  if(BackExpression[i1] == "cos")
		  {
               toCaNum = (toCaNum*Pi)/180;
              resultNum =cos(toCaNum);
		  }
		   if(BackExpression[i1] == "arcsin")
		  {
			  if(toCaNum>1|| toCaNum<-1)
			  {
			m_StringOutput="�����Ǻ���arcsin����������";
			  break;
			  }

               resultNum =asin(toCaNum);
			   resultNum = (resultNum*180)/Pi;
		  }
		  if(BackExpression[i1] == "arctan")
		  {
              
              toCaNum = (toCaNum*Pi)/180;
                resultNum = (resultNum*180)/Pi;
		  }
		  if(BackExpression[i1] == "arccos")
		  {
			   if(toCaNum>1|| toCaNum<-1)
			  {
			m_StringOutput="�����Ǻ���arccos����������";
			  break;
			  }
               toCaNum = (toCaNum*Pi)/180;
                resultNum = (resultNum*180)/Pi;
		  }
		   if(BackExpression[i1] == "!")
		  {
              if(toCaNum <0)
			  {
				m_StringOutput="�׳˲���������Ϊ����";
			  break;
			  }
			  if(toCaNum == 0)
				  resultNum =1;
			  resultNum = 1;
              while(toCaNum !=1)
			  {
                  resultNum*=toCaNum;
				  toCaNum --;
			  }
                
		  }
		  resultNumber.push(resultNum);
		  i1++;
         
		}
		//����˫���������������ֵ��� �ٽ����ѹ��
		if(defineString(BackExpression[i1])==1)
		{
             double num1 =0.0;
			 double num2 =0.0;
			 if(!resultNumber.empty())
			 {
			 num1= resultNumber.top();
			 resultNumber.pop();
			 if(!resultNumber.empty())
			  {
			 num2= resultNumber.top();
			 resultNumber.pop();
			   }
			 else
			 {
                m_StringOutput="����������Ų�ƥ��";
				break;
			 }

			 }
			 else
			 {
                m_StringOutput="����������Ų�ƥ��";
				break;
			 }

			
			 double resultNum =0.0;
			 if(BackExpression[i1] == "+")
			 {
                 resultNum = num1+num2;

			 }
			  if(BackExpression[i1] == "-")
			 {
                 
                resultNum = num2- num1;
			 }
                if(BackExpression[i1] == "*")
			 {
                 
                resultNum = num2* num1;
			 }

			  if(BackExpression[i1] == "/")
			  {
				  if(num1 ==0)
				  {
					  m_StringOutput=" ���ʽ���б�����Ϊ0�����";
					 break;
				  }
				  resultNum = num2/num1;
				   
			  }
			  if(BackExpression[i1] == "%")
			  {
                if(num1 ==0)
				{
					 m_StringOutput=" ���ʽ���б�����Ϊ0�����";
					 break;
				}
				int n1=num1;
				int n2=num2;
				resultNum =n2%n1;
			  }
			  if(BackExpression[i1] == "^")
			  {
               if(num1 == 0&&num2 ==0)
				   	{
					 m_StringOutput=" 0��0�η�û������";
					 break;
				}
                 resultNum =pow(num2,num1);

			  }
			  resultNumber.push(resultNum);
			   i1++;

            }

	}
	//Ϊ��˵��ԭ��û�б�����ô�������ֵ�������
	if(m_StringOutput== "")
	{
		double res = resultNumber.top();
     char buffer[100];
	 sprintf_s(buffer,"%f",res);
	 m_StringOutput=buffer;

	}
//�����ĩβһ�Ѷ���0������
	int OutLength = m_StringOutput.GetLength();
	int j=OutLength -1;
	char OutChar=m_StringOutput.GetAt(j);
	while( OutChar =='0')
	{
		m_StringOutput.Delete(j,1);
		j--;
		OutChar=m_StringOutput.GetAt(j);
	}
//������С���������
	OutLength = m_StringOutput.GetLength();
	int num = OutLength -1;
	if(m_StringOutput.GetAt(num) == '.')
	{
		m_StringOutput.Delete(num,'0');

	}
	m_StringInput= originString ;
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
       m_StringInput+="1";
	   UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber2()
{
	m_StringInput+="2";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    m_StringInput+="3";
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="4";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtondot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+=".";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="5";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_StringInput+="6";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="9";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonadd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="+";
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonsubscrab()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="-";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtontime()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="*";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtondivide()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="/";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButton1parameter()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="(";
	 UpdateData(FALSE);

}

void CcalculatorDlg::OnBnClickedButtonparamater2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+=")";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonlg()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="lg(";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonln()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="ln(";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonarc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="arc";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonsin()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="sin(";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtoncos()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="cos(";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtontan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="tan(";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="0";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="7";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonnumber8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="8";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonmod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="%";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtondekete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//ɾ��ĩβһ���ַ�
	int length = m_StringInput.GetLength();
	int index = length-1;
	m_StringInput.Delete(index);
	UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonempty()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//�����������
	m_StringInput.Empty();
    m_StringOutput.Empty();
	UpdateData(FALSE);

}

void CcalculatorDlg::OnBnClickedButtonpow()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_StringInput+="^";
	 UpdateData(FALSE);
}

void CcalculatorDlg::OnBnClickedButtonanswer()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//���õ��Ľ����ֵ�������
	if(m_StringOutput!="")
	{
	char temp = m_StringOutput[0];
	if(definemark(temp)==2)
	{
	m_StringInput = m_StringOutput;
     m_StringOutput.Empty();
	UpdateData(FALSE);
	}
	else
	{
           m_StringOutput += "\r\n������Ǳ����㲻�ܸ��������";
		   	UpdateData(FALSE);
	}
	}
}

void CcalculatorDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
		m_StringInput+="!";
	 UpdateData(FALSE);
}
