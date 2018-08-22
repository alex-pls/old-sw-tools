/*
........eWorld ReSearch 2004
........Alessandro Polo
........http://www.ewgate.net
........=====================
........This software is freeware. Source code is Open Source.
........Keep Author's Credits if you use any part of this software.
........=====================
........Project State: Completed
........Project Date:  27/2/2004
*/

#include "data.h"


CatData::CatData()
 {
 catname = "";
 s_mat = 0;
 f_mat = 0;
 };


CatData::CatData(AnsiString name, long smat, long fmat)
 {
	catname = AnsiString(name);
	s_mat = smat;
	f_mat = fmat;
 };

void CatData::SetData(AnsiString name, long smat, long fmat)
 {
	catname = AnsiString(name);
	s_mat = smat;
	f_mat = fmat;
 };

int CatData::SetRange(long smat, long fmat)
 {
	s_mat = smat;
	f_mat = fmat;
 return 1;
 };


bool CatData::IsRange(long value)
 {
	if ((f_mat == 0)&&(value >= s_mat))
		return true;
	else if ((value >= s_mat) && (value <= f_mat))
		return true;
	return false;
 };

////////////////////////////////////////////////////////////////////////////////

MacData::MacData()
 {
 macname = "Empty";
 n_cat = 0;
 CatArray = new CatData*[MAX_CATS];
 for (int i = 0; i < MAX_CATS; i++)
        CatArray[i] = NULL;
 };


MacData::MacData(AnsiString name, int num_cat)
 {
 macname = name;
 n_cat = num_cat;
 CatArray = new CatData*[MAX_CATS];
 for (int i = 0; i < MAX_CATS; i++)
        CatArray[i] = NULL;
 };

MacData::~MacData()
 {
 delete []CatArray;
 };

int MacData::AddCat(AnsiString name, long smat, long fmat)
 {
 int i = 0;
 while (CatArray[i]) i++;
 if (i < MAX_CATS)
        {
        CatArray[i] = new CatData(name, smat, fmat);
        return ++n_cat;
        };
 return 0;

 };

int MacData::RemCat(AnsiString name)
 {
 for (int i = 0; i < MAX_CATS; i++)
        if ((CatArray[i] != NULL)&&(CatArray[i]->GetName() == name))
		{
		delete CatArray[i];
		CatArray[i] = NULL;
                n_cat--;
		return n_cat;
		};
 return 0;
 };

CatData* MacData::GetCat(AnsiString name)
 {
 for (int i = 0; i < MAX_CATS; i++)
	if ((CatArray[i] != NULL)&&(CatArray[i]->GetName() == name))
		return CatArray[i];
 return NULL;
 };

CatData* MacData::GetCat(int pos)
 {
 if ((pos>=0)&&(pos<MAX_CATS))
	return CatArray[pos];
 return NULL;
 };

void MacData::ListCat(TStrings * list)
 {
 list->Clear();
 for (int i = 0; i < MAX_CATS; i++)
        if (CatArray[i] != NULL)
                list->Add(CatArray[i]->GetName());
 };

AnsiString MacData::SearchMat(long value)
 {
 for (int i = 0; i < MAX_CATS; i++)
        if (CatArray[i] != NULL)
                if (CatArray[i]->IsRange(value))
                        return CatArray[i]->GetName();
 return "";
 };

////////////////////////////////////////////////////////////////////////////////

AllData::AllData()
 {
 bookname = "";
 n_mac = 0;
 MacArray = new MacData*[MAX_MACS];
 for (int i = 0; i < MAX_MACS; i++)
        MacArray[i] = NULL;
 };

AllData::AllData(AnsiString name, int num_mac)
 {
 bookname = name;
 n_mac = num_mac;
 MacArray = new MacData*[MAX_MACS];
 for (int i = 0; i < MAX_MACS; i++)
        MacArray[i] = NULL;

 };

AllData::~AllData()
 {
 delete []MacArray;
 n_mac = 0;
 };

MacData* AllData::GetMac(AnsiString name)
 {
 for (int i = 0; i < MAX_MACS; i++)
	if ((MacArray[i] != NULL)&&(MacArray[i]->GetName() == name))
		return MacArray[i];
 return NULL;
 };

MacData* AllData::GetMac(int pos)
 {
 if ((pos>=0)&&(pos<MAX_MACS))
	return MacArray[pos];
 return NULL;
 };


int AllData::AddMac(AnsiString name, int num_cat)// = 1
 {
 int i = 0;
 while (MacArray[i]) i++;
 if (i < MAX_MACS)
        {
        MacArray[i] = new MacData(name, num_cat);
        return ++n_mac;
        };
 return 0;
 };

int AllData::RemMac(AnsiString name)
 {
 for (int i = 0; i < MAX_MACS; i++)
        if ((MacArray[i] != NULL)&&(MacArray[i]->GetName() == name))
		{
		delete MacArray[i];
		MacArray[i] = NULL;
                n_mac--;
		return n_mac;
		};
 return 0;
 };

void AllData::ListMac(TStrings * list)
 {
 list->Clear();

 for (int i = 0; i < MAX_MACS; i++)
        if (MacArray[i] != NULL)
                list->Add(MacArray[i]->GetName());
 };

int AllData::GetTotCatNumber(void)
 {
 int res = 0;
 for (int i = 0; i < MAX_MACS; i++)
        if (MacArray[i] != NULL)
                res += MacArray[i]->GetNumCat();
 return res;
 };


int AllData::LoadFromFile(AnsiString filename)
 {
 int errors = 0;
 AnsiString currMac, tmpline, tmpval, tmpval2;
 currMac = "";
 TStringList *expfile;
 expfile = new TStringList;
 expfile->Clear();
 expfile->LoadFromFile(filename);

 for (int i = 0; i < n_mac; i++)
        if (MacArray[i] != NULL)
		{
		delete MacArray[i];
		MacArray[i] = NULL;
		};
        n_mac = 0;




 if (expfile->Count)
        {
        for (int i = 0; i < expfile->Count; i++)
          {
          if ((expfile->Strings[i].SubString(1,1) != "#")&&(!expfile->Strings[i].Trim().IsEmpty()))  //comment
            {
            if (expfile->Strings[i].SubString(1,1) == "$") // new machine tag
                {
                currMac = "";
                currMac = Trim(expfile->Strings[i].SubString(2,expfile->Strings[i].Length()-1));
                errors += AddMac(currMac);
                }
            else
                {
                if (currMac == "")
                        errors++;
                else
                        {       // add catalog to currmac
                        tmpline = Trim(expfile->Strings[i]);
                        tmpval = Trim(tmpline.SubString(1, tmpline.AnsiPos("\t")));
                        tmpline = tmpline.SubString(tmpline.AnsiPos("\t")+1, tmpline.Length() - tmpline.AnsiPos("\t"));
                        tmpval2 = Trim(tmpline.SubString(1, tmpline.AnsiPos("\t")));
                        tmpline = Trim(tmpline.SubString(tmpline.AnsiPos("\t")+1, tmpline.Length() - tmpline.AnsiPos("\t")));
                        errors += GetMac(currMac)->AddCat(tmpval, tmpval2.ToDouble(), tmpline.ToDouble());
                        }
                };
            };

          }

        }
 else
        errors = 1;

 if (currMac == "")
        errors = 1;

 delete expfile;
 return errors;
 };

int AllData::SaveToFile(AnsiString filename)
 {
 if (MacArray == NULL)
        return 0;

 AnsiString TabS;
 TabS = "/t";
 TStringList *expfile;
 expfile = new TStringList;
 expfile->Clear();
 expfile->Add("#                       FASTCAT 1.0");
 expfile->Add("# =================================");
 expfile->Add("# Freeware - Open Source");
 expfile->Add("# by Alessandro Polo");
 expfile->Add("# http://www.ewgate.net/research");
 expfile->Add("# ");
 expfile->Add("# [source DATA File]");
 expfile->Add("# ");
 expfile->Add("# Last Update: " + AnsiString(Date()));
 expfile->Add("");
 expfile->Add("");

 for (int i = 0; i < MAX_MACS; i++)
        if (MacArray[i] != NULL)
                {
                expfile->Add("");
                expfile->Add("#macchina");
                expfile->Add("$" + MacArray[i]->GetName());
                expfile->Add("");
                expfile->Add("# idcat	from	to");


                for (int j = 0; j < MAX_CATS; j++)

                        if (MacArray[i]->GetCat(j) != NULL)

                                expfile->Add(AnsiString(MacArray[i]->GetCat(j)->GetName()) + "\t" + AnsiString(MacArray[i]->GetCat(j)->GetStart()) + "\t" + AnsiString(MacArray[i]->GetCat(j)->GetEnd()));


                                //                                expfile->Add(AnsiString(MacArray[i]->GetCat(j)->GetName()) + TabS +
//                                             AnsiString(MacArray[i]->GetCat(j)->GetStart()) + TabS +
//                                             AnsiString(MacArray[i]->GetCat(j)->GetEnd())   );
                };
 expfile->Add("");
 expfile->Add("");
 expfile->Add("# End Of File");



 expfile->SaveToFile(filename);
 delete expfile;

 return 1;
 };


int AllData::ExportMacs(AnsiString filename)
 {
 TStringList *expfile;
 expfile = new TStringList;
 expfile->Clear();

 for (int i = 0; i < MAX_MACS; i++)
        if (MacArray[i] != NULL)
                expfile->Add(MacArray[i]->GetName());

 expfile->SaveToFile(filename);
 delete expfile;
 return 1;

 };





